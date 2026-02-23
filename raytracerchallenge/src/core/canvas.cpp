#include "core/canvas.h"

Canvas::Canvas(int w, int h)
    : width(w),
    height(h),
    pixels(static_cast<size_t>(w)* h) 
{
    fill_with(Color(0, 0, 0));
}

void Canvas::fill_with(Color c) {
    if (is_empty())
        return;

    for (Color& pixel : pixels) {
        pixel = c;
    }
}


void Canvas::write_pixel(int x, int y, Color c) {
    if (is_empty())
        return;

    pixels[y * width + x] = c;
}

bool Canvas::is_empty() {
    return pixels.empty();
}

Color Canvas::pixel_at(int x, int y) {
    return pixels[y * width + x];
}

Color Canvas::pixel_at(Canvas c, int x, int y) {
    return c.pixel_at(x, y);
}

void Canvas::write_pixel(Canvas canvas, int x,
    int y, Color color) {
    if (canvas.is_empty())
        return;

    canvas.pixels[y * canvas.width + x] = color;
}

std::fstream Canvas::canvas_to_ppm(Canvas c) {
    
}




