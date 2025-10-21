#pragma once
#include "Point.hpp"
#include "APP.hpp"
#include <APP_settings.hpp>

#include <functional>
#include <glad/glad.h>
#include <imgui.h>

bool Point::render(Settings &settings) {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&settings);

    if (ImGui::Button("Reset local settings")) {
        appSettings->resetValues();
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
