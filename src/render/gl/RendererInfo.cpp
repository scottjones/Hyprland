#include "RendererInfo.hpp"

#include <algorithm>
#include <cctype>
#include <string>

bool Render::GL::isSoftwareRenderer(std::string_view rendererName) {
    std::string name{rendererName};
    std::ranges::transform(name, name.begin(), [](unsigned char character) { return static_cast<char>(std::tolower(character)); });
    return name.contains("llvmpipe") || name.contains("softpipe") || name.contains("software rasterizer");
}
