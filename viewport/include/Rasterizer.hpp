#pragma once
#include "Settings.hpp"
#include "ViewportRenderer.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>

class Rasterizer : public ViewportRenderer {
public:
    virtual bool render(Settings &settings, unsigned char **data) override;
};
