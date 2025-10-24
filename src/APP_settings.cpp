#include "APP_settings.hpp"

APP_settings::APP_settings() {
    this->point_x = 50.0;
    this->point_y = 50.0;
    this->saveImage = false;
}

void APP_settings::resetValues() {
    *this = APP_settings();
}

void APP_settings::setSave(bool val) {
    this->saveImage = val;
}