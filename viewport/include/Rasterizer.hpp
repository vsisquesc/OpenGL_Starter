#pragma once
#include "Settings.hpp"
#include "ViewportRenderer.hpp"
#include "ViewportSettings.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>
#include <tgaimage.hpp>

class Rasterizer : public ViewportRenderer {
public:
    Rasterizer(ViewportSettings &viewport_settings, Settings &settings);
    virtual bool render(unsigned char **data) override;

private:
    TGAImage RenderImage();
    void TGA_to_buffer(TGAImage image, unsigned char **data);
    void saveImage(TGAImage image);
};
