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
	void fill_with(Color c);


	//void fill_with(Tuple x1, Tuple x2, Tuple y1, Tuple y2);
	void write_pixel(int x, int y, Color color);

	// saves canvas to a .ppm file
	void save_ppm(const std::string& filename) const;

	// adds defult headers to ppm string
	std::string ppm_header(int width, int height) const;


	// checks if this canvas has any pixels
	bool is_empty() const;


	// retrieves pixel (Color) found at coordinates x,y
	// must be used by Canvas object
	Color pixel_at(int x, int y) const;



	// retrieves pixel (Color) found at coordinates x,y
	static Color pixel_at(const Canvas c, int x, int y);

	// Writes a Color (a.k.a pixel) at coordinate x, y
	static void write_pixel(Canvas& canvas, int x, int y, const Color& color);


	// Exports the canvas as a correctly 
	// formatted PPM image string.
	static std::string canvas_to_ppm(const Canvas& c);

};

#endif // !CANVAS_H
