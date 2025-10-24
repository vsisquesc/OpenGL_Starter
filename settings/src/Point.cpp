#include "Point.hpp"
#include "APP.hpp"
#include "ViewportSettings.hpp"
#include <APP_settings.hpp>
#include <functional>
#include <glad/glad.h>
#include <imgui.h>

Point::Point(ViewportSettings &viewport_settings, Settings &settings) : SettingsRenderer(viewport_settings, settings) {
}
bool Point::render() {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&this->local_settings);

    if (ImGui::Button("Reset local settings")) {
        appSettings->resetValues();
    }

    if (ImGui::Button("SaveImage")) {
        appSettings->setSave(true);
    } else {
        appSettings->setSave(false);
    }

    if (ImGui::InputInt("point x", &appSettings->point_x)) {
        if (appSettings->point_x < 0)
            appSettings->point_x = 0;
        if (appSettings->point_x > 100)
            appSettings->point_x = 100;
    }
    if (ImGui::InputInt("point y", &appSettings->point_y)) {
        if (appSettings->point_y < 0)
            appSettings->point_y = 0;
        if (appSettings->point_y > 100)
            appSettings->point_y = 100;
    }

    return true;
}
