

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
    ViewportSettings viewport_settings = ViewportSettings();
    APP_settings local_settings = APP_settings();
    std::unique_ptr<Rasterizer> rasterizer = std::make_unique<Rasterizer>(viewport_settings, local_settings);
    std::unique_ptr<Point> point = std::make_unique<Point>(viewport_settings, local_settings);
    APP application = APP(viewport_settings, local_settings, std::move(rasterizer), std::move(point));
    application.run();
    return 0;
}
