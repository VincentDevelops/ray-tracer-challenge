#ifndef ANALOG_H
#define ANALOG_H

#include "core/matrix.h"
#include "core/canvas.h"
#include <iostream>

inline void analog_clock() {
    const float RADIUS = 25.0f;
    const float CANVAS_SIZE = 100; //px
    const Color color(.5, .5, .5);
    const int hours = 12;
    Canvas canvas(CANVAS_SIZE, CANVAS_SIZE);
    Matrix center_transform = Matrix::translation(CANVAS_SIZE / 2, 0, CANVAS_SIZE / 2);
    Tuple twelve = Tuple::point(0, 0, -RADIUS);
    Tuple hour = Tuple::point(0, 0, 0);

    for (int i = 0; i < hours; i++) {
        hour = Matrix::rotation_y(i * (rtc::PI / 6)) * twelve;
        hour = center_transform * hour; // move to middle in context of frame
        canvas.write_pixel(hour.x, hour.z, color);
    }

    canvas.save_ppm("test_analog.ppm");

}



#endif // ANALOG_H


