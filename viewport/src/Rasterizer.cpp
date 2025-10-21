#pragma once
#include "Rasterizer.hpp"
#include "APP.hpp"
#include <APP_settings.hpp>

#include <functional>
#include <glad/glad.h>
#include <imgui.h>

bool Rasterizer::render(Settings &settings, unsigned char **data) {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&settings);

    int w = appSettings->viewport_w;
    int h = appSettings->viewport_h;
    // Gestionar cambios en h y w; hacer estático
    *data = new unsigned char[w * h * C];

    //  Hacer dinámico
    float c_values[C] = {
        appSettings->R,
        appSettings->G,
        appSettings->B,
        appSettings->A};
    auto ptr = *data;
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            for (int z = 0; z < C; z++) {
                int idx = (y * w * C) + (x * C) + z;
                if (x == appSettings->point_x && y == appSettings->point_y) {
                    ptr[idx] = 255;
                } else {

                    ptr[idx] = 0xaa * c_values[z];
                }
            }
        }
    }
    return true;
}
