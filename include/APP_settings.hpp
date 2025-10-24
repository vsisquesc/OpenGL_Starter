#pragma once
#include "Settings.hpp"
#include <functional>
#include <glad/glad.h>
#include <imgui.h>

class APP_settings : public Settings {
public:
    APP_settings();
    void resetValues() override;
    void setSave(bool val);

    int point_x;
    int point_y;
    bool saveImage;
};
