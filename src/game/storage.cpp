#include "storage.h"

#include <Windows.h>
#include <atomic>
#include <array>
#include <intrin.h>
#include <MinHook.h>

#include "offsets.h"
#include "../mem/hooks.h"
#include "../core/logger.h"

namespace trinity::game
{
    namespace
    {
        using StorageOpen_t = void* (__fastcall*)(void*, unsigned char, unsigned char, void*);
        using SetInventory_t = void* (__fastcall*)(void*, void*);
        using Warehouse_t = void* (__fastcall*)(void*, void*, void*, void*);

        StorageOpen_t  g_openOriginal = nullptr;
        SetInventory_t g_setOriginal = nullptr;
        Warehouse_t    g_warehouseOriginal = nullptr;
        void* g_openTarget = nullptr;
        void* g_setTarget = nullptr;
        void* g_warehouseTarget = nullptr;

        std::atomic<unsigned> g_openCount{ 0 };
        std::atomic<unsigned> g_setCount{ 0 };
        std::atomic<unsigned> g_warehouseCount{ 0 };

        struct OpenSample
        {
            unsigned sequence{};
            DWORD threadId{};
            void* self{};
            unsigned char mode{};
            unsigned char inventory{};
            void* context{};
            void* caller{};
        };

        constexpr unsigned kOpenHistorySize = 48;
        std::array<OpenSample, kOpenHistorySize> g_openHistory{};

        void DumpRecentOpenHistory(const char* reason)
        {
            const unsigned total = g_openCount.load(std::memory_order_acquire);
            const unsigned first = total > kOpenHistorySize ? total - kOpenHistorySize : 0;
            LOG("storage-trace: recent-open-history reason=%s first=%u total=%u", reason, first, total);
            for (unsigned sequence = first; sequence < total; ++sequence)
            {
                const OpenSample& sample = g_openHistory[sequence % kOpenHistorySize];
                if (sample.sequence != sequence)
                    continue;
                LOG("storage-trace: open[%u] tid=%lu self=%p mode=%u inventory=%u context=%p caller=%p",
                    sample.sequence, sample.threadId, sample.self, sample.mode,
                    sample.inventory, sample.context, sample.caller);
            }
        }

        void* __fastcall hkStorageOpen(void* self, unsigned char mode,
                                       unsigned char inventory, void* context)
        {
            const unsigned n = g_openCount.fetch_add(1, std::memory_order_acq_rel);
            OpenSample& sample = g_openHistory[n % kOpenHistorySize];
            sample = { n, GetCurrentThreadId(), self, mode, inventory, context, _ReturnAddress() };
            return g_openOriginal(self, mode, inventory, context);
        }

        void* __fastcall hkSetInventory(void* self, void* inventory)
        {
            const unsigned n = g_setCount.fetch_add(1, std::memory_order_relaxed);
            if (n < 64)
            {
                LOG("storage-trace: set-inventory[%u] tid=%lu self=%p inventory=%p caller=%p",
                    n, GetCurrentThreadId(), self, inventory, _ReturnAddress());
                DumpRecentOpenHistory("set-inventory");
            }
            return g_setOriginal(self, inventory);
        }

        void* __fastcall hkWarehouse(void* self, void* arg2, void* arg3, void* arg4)
        {
            const unsigned n = g_warehouseCount.fetch_add(1, std::memory_order_relaxed);
            if (n < 64)
                LOG("storage-trace: warehouse[%u] tid=%lu self=%p rdx=%p r8=%p r9=%p caller=%p",
                    n, GetCurrentThreadId(), self, arg2, arg3, arg4, _ReturnAddress());
            return g_warehouseOriginal(self, arg2, arg3, arg4);
        }
    }

    bool Storage::Install()
    {
        const bool openOk = mem::InstallHook(
            "storage-capture: mode opener", kSig_StorageOpenCapture,
            "native Open Storage capture unavailable", &hkStorageOpen,
            &g_openOriginal, &g_openTarget, 1);
        const bool setOk = mem::InstallHook(
            "storage-capture: set inventory", kSig_StorageSetInventoryCapture,
            "storage selection capture unavailable", &hkSetInventory,
            &g_setOriginal, &g_setTarget, 1);
        const bool warehouseOk = mem::InstallHook(
            "storage-capture: warehouse UI", kSig_StorageWarehouseCapture,
            "warehouse UI capture unavailable", &hkWarehouse,
            &g_warehouseOriginal, &g_warehouseTarget, 1);

        if (openOk || setOk || warehouseOk)
            LOG_OK("storage-trace: armed (open=%d setInventory=%d warehouse=%d); open one storage normally.",
                   openOk ? 1 : 0, setOk ? 1 : 0, warehouseOk ? 1 : 0);
        return openOk && setOk && warehouseOk;
    }

    void Storage::Remove()
    {
        mem::RemoveHook(&g_warehouseTarget);
        mem::RemoveHook(&g_setTarget);
        mem::RemoveHook(&g_openTarget);
    }
}
