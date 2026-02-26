#include "core/canvas.h"

Canvas::Canvas(int w, int h)
    : width(w),
    height(h),
    pixels(static_cast<size_t>(w)* h) 
{
    fill_with(Color(0, 0, 0));
}

void Canvas::fill_with(const Color& c) {
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

int Canvas::index(int x, int y) const {
    return y * width + x;
}

bool Canvas::is_empty() const {
    return pixels.empty();
}

Color Canvas::pixel_at(int x, int y) const {
    return pixels[index(x,y)];
}

Color Canvas::pixel_at(const Canvas& c, int x, int y) {
    return c.pixel_at(x, y);
}

void Canvas::write_pixel(Canvas& canvas, int x, int y, const Color& color) {
    if (!canvas.in_bounds(x, y))
        return;

    canvas.pixels[y * canvas.width + x] = color;
}

void Canvas::save_ppm(const std::string& filename) const {
    std::ofstream file(filename);    
    
    if (!file)
    {
        throw std::runtime_error("Failed to open output file");
    }

    file << Canvas::canvas_to_ppm(*this);
}


std::string Canvas::ppm_header(int width, int height) const {
    return "P3\n" +
        std::to_string(width) + " " + std::to_string(height) + "\n" +
        "255\n";
}

// Converts the canvas pixel buffer into a valid PPM(P3) 
// formatted string, including the header, RGB pixel data, 
// and line wrapping that ensures no line 
// exceeds 70 characters.
// O(width * height) time complexity 
std::string Canvas::canvas_to_ppm(const Canvas& c) {
    std::string ppm = c.ppm_header(c.width, c.height);

    std::size_t line_len = 0;

    // look through every line
    for (int row = 0; row < c.height; ++row) {
        line_len = 0;

        // loop through column
        for (int col = 0; col < c.width; ++col) {
            Color px = c.pixel_at(col, row);

            // clamp rgb values to integers with rounding
            int vals[3] = {
                Color::to_ppm(px.r),
                Color::to_ppm(px.g),
                Color::to_ppm(px.b)
            };

            // write values to string
            for (int i = 0; i < 3; ++i) {
                std::string token = std::to_string(vals[i]);

                // if not at the start of line make space before value
                std::size_t space = (line_len == 0) ? 0 : 1;

                // make sure adding value will not exceed 70 character limit
                if (line_len + space + token.size() > 70) {
                    ppm += "\n";
                    line_len = 0;
                    space = 0;
                }

                if (space) {
                    ppm += " ";
                    line_len += 1;
                }

                ppm += token;
                line_len += token.size();
            }
        }

        // start of new line ppm must end with new line as well
        ppm += "\n";
    }

    return ppm;
}

