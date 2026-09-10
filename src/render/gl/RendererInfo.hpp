#pragma once

#include <string_view>

namespace Render::GL {
    bool isSoftwareRenderer(std::string_view rendererName);
}
