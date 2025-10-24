#pragma once
#include "Rasterizer.hpp"
#include "APP.hpp"
#include "ViewportSettings.hpp"
#include <APP_settings.hpp>

#include <tgaimage.hpp>

#include <chrono>
#include <functional>
#include <glad/glad.h>
#include <imgui.h>
#include <iostream>

constexpr TGAColor white = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 128, 64, 255};
constexpr TGAColor yellow = {0, 200, 255, 255};

bool Rasterizer::render(ViewportSettings &viewport_settings, Settings &settings, unsigned char **data) {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&settings);

    int w = viewport_settings.viewport_w;
    int h = viewport_settings.viewport_h;

    TGAImage framebuffer(w, h, C,
                         {255.0f * viewport_settings.B,
                          255.0f * viewport_settings.G,
                          255.0f * viewport_settings.R,
                          255.0f * viewport_settings.A});

    int ax = appSettings->point_x, ay = appSettings->point_y;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    *data = new unsigned char[w * h * C];

    // Iterar sobre cada píxel
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            // Obtener el color en (x, y)
            TGAColor color = framebuffer.get(x, y);

            // Calcular posición lineal del píxel
            int idx = (y * w + x) * C;

            // Convertir de BGRA → RGBA directamente
            (*data)[idx + 0] = color.bgra[2]; // R
            (*data)[idx + 1] = color.bgra[1]; // G
            (*data)[idx + 2] = color.bgra[0]; // B
            if (C == 4)
                (*data)[idx + 3] = color.bgra[3]; // A
        }
    }

    if (appSettings->saveImage) {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        int ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                     now.time_since_epoch())
                     .count();
        std::string filename = "../output/framebuffer_" + std::to_string(ms) + ".tga";
        framebuffer.write_tga_file(filename);
    }
    return true;
}
