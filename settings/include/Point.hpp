#pragma once
#include "Settings.hpp"
#include "SettingsRenderer.hpp"
#include "ViewportSettings.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>
class Point : public SettingsRenderer {
public:
    virtual bool render(ViewportSettings &viewport_settings, Settings &settings) override;
};
