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

Rasterizer::Rasterizer(ViewportSettings &viewport_settings, Settings &settings) : ViewportRenderer(viewport_settings, settings) {
}

TGAImage Rasterizer::RenderImage() {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&this->local_settings);

    int w = this->viewport_settings.viewport_w;
    int h = this->viewport_settings.viewport_h;

    TGAImage framebuffer(w, h, C,
                         {0xaa * this->viewport_settings.B,
                          0xaa * this->viewport_settings.G,
                          0xaa * this->viewport_settings.R,
                          0xff * this->viewport_settings.A});
    int ax = appSettings->point_x, ay = appSettings->point_y;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;
    int dx = 7, dy = 3;

    framebuffer.set(ax, ay, red);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);
    framebuffer.set(dx, dy, white);

    return framebuffer;
}

void Rasterizer::TGA_to_buffer(TGAImage framebuffer, unsigned char **data) {
    int w = this->viewport_settings.viewport_w;
    int h = this->viewport_settings.viewport_h;
    *data = new unsigned char[w * h * C];

    // Iterar sobre cada píxel
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            // Obtener el color en (x, y)
            int flipped_y = h - 1 - y; // Fila invertida
            TGAColor color = framebuffer.get(x, flipped_y);

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
}

void Rasterizer::saveImage(TGAImage framebuffer) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    int ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                 now.time_since_epoch())
                 .count();
    std::string filename = "../output/framebuffer_" + std::to_string(ms) + ".tga";
    framebuffer.write_tga_file(filename);
}

bool Rasterizer::render(unsigned char **data) {
    APP_settings *appSettings = dynamic_cast<APP_settings *>(&this->local_settings);

    TGAImage framebuffer = this->RenderImage();
    this->TGA_to_buffer(framebuffer, data);

    if (appSettings->saveImage) {
        this->saveImage(framebuffer);
    }
    return true;
}
