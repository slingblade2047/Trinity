#pragma once

// Embedded provenance record. These strings intentionally remain present in
// release binaries so a distributed ASI can be traced to its public source.
#define TRINITY_MAINTAINER "slingblade2047"
#define TRINITY_SOURCE_URL "https://github.com/slingblade2047/Trinity"
#define TRINITY_UPSTREAM_URL "https://github.com/XeTrinityz/Trinity"
#define TRINITY_BUILD_LINEAGE "XeTrinityz original; slingblade2047 CD 1.17/1.18 compatibility fork"
#define TRINITY_RESEARCH_CREDITS "Orcax1399; Gugi96"

namespace trinity::provenance
{
    inline constexpr char kBinaryMarker[] =
        "TRINITY_PROVENANCE|maintainer=" TRINITY_MAINTAINER
        "|source=" TRINITY_SOURCE_URL
        "|upstream=" TRINITY_UPSTREAM_URL
        "|lineage=" TRINITY_BUILD_LINEAGE
        "|research=" TRINITY_RESEARCH_CREDITS;
}
