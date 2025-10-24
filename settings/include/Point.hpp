#pragma once
#include "Settings.hpp"
#include "SettingsRenderer.hpp"
#include "ViewportSettings.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>
class Point : public SettingsRenderer {
public:
    Point(ViewportSettings &viewport_settings, Settings &settings);
    virtual bool render() override;
};
