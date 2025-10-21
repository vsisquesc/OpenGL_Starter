#pragma once
#include "Settings.hpp"
#include "SettingsRenderer.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>

class Point : public SettingsRenderer {
public:
    virtual bool render(Settings &settings) override;
};
