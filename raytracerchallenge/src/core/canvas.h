#ifndef CANVAS_H
#define CANVAS_H

#include "core/color.h"
#include "core/tuple.h"
#include <vector>
#include <fstream>
#include <string>

struct Canvas {
	int width = 0;
	int height = 0;
	std::vector<Color> pixels;


	Canvas() = default;
	Canvas(int w_, int h_);


	// fills entire canvas with a certain color
	void fill_with(const Color& c);


	//void fill_with(Tuple x1, Tuple x2, Tuple y1, Tuple y2);
	void write_pixel(int x, int y, Color color);

	// saves canvas to a .ppm file
	void save_ppm(const std::string& filename) const;

	// adds defult headers to ppm string
	[[nodiscard]] std::string ppm_header(int width, int height) const;

	int index(int x, int y) const;

	// checks if this canvas has any pixels
	[[nodiscard]] bool is_empty() const;

	// checks for point validity
	[[nodiscard]] constexpr bool in_bounds(int x, int y) const {
		return x >= 0 && x < width && y >= 0 && y < height;
	}

	// retrieves pixel (Color) found at coordinates x,y
	// must be used by Canvas object
	[[nodiscard]] Color pixel_at(std::size_t x, std::size_t y) const;



	// retrieves pixel (Color) found at coordinates x,y
	[[nodiscard]] static Color pixel_at(const Canvas& c, int x, int y);

	// Writes a Color (a.k.a pixel) at coordinate x, y
	static void write_pixel(Canvas& canvas, int x, int y, const Color& color);


	// Exports the canvas as a correctly 
	// formatted PPM image string.
	[[nodiscard]] static std::string canvas_to_ppm(const Canvas& c);

};

#endif // !CANVAS_H
