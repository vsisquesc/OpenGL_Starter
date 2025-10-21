

#include "imgui.h"
#include <iostream>
#include <memory>

#include <APP_settings.hpp>
#include <Point.hpp>
#include <Rasterizer.hpp>

#include <Settings.hpp>

#include <APP.hpp>

// Main code
int main() {
    APP_settings settings = APP_settings();
    std::unique_ptr<Rasterizer> rasterizer = std::make_unique<Rasterizer>();
    std::unique_ptr<Point> point = std::make_unique<Point>();
    // APP application = APP(settings);
    APP application = APP(settings, std::move(rasterizer), std::move(point));
    application.run();
    return 0;
}
