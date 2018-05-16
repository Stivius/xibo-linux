#pragma once

#include <string>
#include <gtkmm/image.h>

class IBackground
{
public:
    IBackground() = default;
    IBackground(const IBackground&) = delete;
    IBackground& operator=(const IBackground&) = delete;

    virtual void set_color(uint32_t) = 0;
    virtual void set_image(const std::string& image_path) = 0;
    virtual void set_size(int width, int height) = 0;
    virtual void show() = 0;
    virtual operator Gtk::Image&() = 0;
};