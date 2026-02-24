#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <sstream>
#include "core/canvas.h"
#include "core/color.h"

//TEST_CASE("Constructing the PPM header") {
//	Canvas c(5, 3);
//	std::string ppm = c.canvas_to_ppm(c);
//
//}

TEST_CASE("Constructing the PPM header") {
    Canvas c(5, 3);

    std::string ppm = Canvas::canvas_to_ppm(c);
        
    std::istringstream stream(ppm);
    std::string line1, line2, line3;

    std::getline(stream, line1);
    std::getline(stream, line2);
    std::getline(stream, line3);

    REQUIRE(line1 == "P3");
    REQUIRE(line2 == "5 3");
    REQUIRE(line3 == "255");
}

TEST_CASE("Constructing the PPM Pixel data") {
    Canvas c(5, 3);
    Color c1(1.5f, 0.0f, 0.0f),
        c2(0.0f, 0.5f, 0.0f),
        c3(-0.5f, 0.0f, 1.0f);

    Canvas::write_pixel(c, 0, 0, c1);
    Canvas::write_pixel(c, 2, 1, c2);
    Canvas::write_pixel(c, 4, 2, c3);

    std::string ppm = Canvas::canvas_to_ppm(c);
    std::istringstream stream(ppm);

    std::string garbage;
    std::getline(stream, garbage); // p3
    std::getline(stream, garbage); // 5 3
    std::getline(stream, garbage); // 255

    std::string line1, line2, line3;

    std::getline(stream, line1);
    std::getline(stream, line2);
    std::getline(stream, line3);

    REQUIRE(line1 == 
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    REQUIRE(line2 == 
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
    REQUIRE(line3 ==
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}

TEST_CASE("Splitting long lines in PPM files") {
    Canvas c(10, 2);
    c.fill_with(Color(1.0f, 0.8f, 0.6f));
   
    std::string ppm = Canvas::canvas_to_ppm(c);
    std::istringstream stream(ppm);

    std::string garbage;
    std::getline(stream, garbage); // p3
    std::getline(stream, garbage); // 10 2
    std::getline(stream, garbage); // 255

    // Read lines 4-7
    std::string l4, l5, l6, l7;
    std::getline(stream, l4);
    std::getline(stream, l5);
    std::getline(stream, l6);
    std::getline(stream, l7);

    REQUIRE(l4 == "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    REQUIRE(l5 == "153 255 204 153 255 204 153 255 204 153 255 204 153");
    REQUIRE(l6 == "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    REQUIRE(l7 == "153 255 204 153 255 204 153 255 204 153 255 204 153");
}

TEST_CASE("PPM files are terminated by a newline character") {
        Canvas c(5, 3);
        Color c1(1.5f, 0.0f, 0.0f),
            c2(0.0f, 0.5f, 0.0f),
            c3(-0.5f, 0.0f, 1.0f);

        Canvas::write_pixel(c, 0, 0, c1);
        Canvas::write_pixel(c, 2, 1, c2);
        Canvas::write_pixel(c, 4, 2, c3);

        std::string ppm = Canvas::canvas_to_ppm(c);

        REQUIRE(!ppm.empty());
        REQUIRE(ppm.back() == '\n');
}
    

