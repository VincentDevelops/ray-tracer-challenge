#ifndef CANVAS_H
#define CANVAS_H

#include "core/color.h"
#include "core/tuple.h"
#include <vector>
#include <fstream>

struct Canvas {
private:
	int width = 0;
	int height = 0;
	std::vector<Color> pixels;

public:

	Canvas() = default;
	Canvas(int w_, int h_);

	void fill_with(Color c);
	//void fill_with(Tuple x1, Tuple x2, Tuple y1, Tuple y2);
	void write_pixel(int x, int y, Color color);

	bool is_empty();

	Color pixel_at(int x, int y);

	static Color pixel_at(Canvas c, int x, int y);
	static void write_pixel(Canvas canvas,
								int x, int y, Color color);

	static std::fstream canvas_to_ppm(Canvas c);

};

#endif // !CANVAS_H
