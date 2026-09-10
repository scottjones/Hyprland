#include <render/gl/RendererInfo.hpp>

#include <gtest/gtest.h>

TEST(RendererInfo, SoftwareRenderers) {
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("llvmpipe (LLVM 22.1.0, 128 bits)"));
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("softpipe"));
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("Software Rasterizer"));
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("LLVMPIPE (LLVM 22.1.0, 128 bits)"));
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("SoFtPiPe"));
    EXPECT_TRUE(Render::GL::isSoftwareRenderer("software rasterizer"));
}

TEST(RendererInfo, AcceleratedRenderers) {
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("Apple M1 (G13G B1)"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("Apple M2 (G14G B0)"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("AMD Radeon Graphics (radeonsi, gfx1103_r1)"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("Mesa Intel(R) Graphics (ADL GT2)"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("NVIDIA GeForce RTX 3060/PCIe/SSE2"));
}

TEST(RendererInfo, DisplayDriverNamesAreNotSoftwareRendererEvidence) {
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("simpledrm"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("apple-drm"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer("asahi"));
    EXPECT_FALSE(Render::GL::isSoftwareRenderer(""));
}
