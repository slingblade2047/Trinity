#pragma once

namespace trinity::game
{
    // Read-only capture of the native storage UI path. This diagnostic stage
    // deliberately does not expose an Open button or alter game arguments.
    class Storage
    {
    public:
        static bool Install();
        static void Remove();
    };
}
