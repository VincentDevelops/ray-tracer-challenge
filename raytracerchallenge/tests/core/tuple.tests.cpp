#include <catch2/catch_test_macros.hpp>
#include "core/tuple.h"

TEST_CASE("Tuple() constructor check") {
    Tuple tuple;
    REQUIRE(tuple.x == 0.0f);
    REQUIRE(tuple.y == 0.0f);
    REQUIRE(tuple.z == 0.0f);
    REQUIRE(tuple.w == 1.0f);
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("Tuple(x,y,z,w) constructor check point") {
    Tuple tuple(4.3, -4.2, 3.1, 1.0);
    REQUIRE(tuple.x == 4.3f);
    REQUIRE(tuple.y == -4.2f);
    REQUIRE(tuple.z == 3.1f);
    REQUIRE(tuple.w == 1.0f);
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("Tuple(x,y,z,w) constructor check vector") {
    Tuple tuple(4.3, -4.2, 3.1, 0.0);
    REQUIRE(tuple.x == 4.3f);
    REQUIRE(tuple.y == -4.2f);
    REQUIRE(tuple.z == 3.1f);
    REQUIRE(tuple.w == 0.0f);
    REQUIRE(tuple.is_vector() == true);
}

TEST_CASE("point(x,y,z) should return a point tuple") {
    Tuple tuple = Tuple::point(4.3, -4.2, 3.1);
    REQUIRE(tuple.x == 4.3f);
    REQUIRE(tuple.y == -4.2f);
    REQUIRE(tuple.z == 3.1f);
    REQUIRE(tuple.w == 1.0f);
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("vector() should return a point tuple") {
    Tuple tuple = Tuple::point();
    REQUIRE(tuple.x == 0.0f);
    REQUIRE(tuple.y == 0.0f);
    REQUIRE(tuple.z == 0.0f);
    REQUIRE(tuple.w == 1.0f);
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("vector(x,y,z) should return a vector tuple") {
    Tuple tuple = Tuple::vector(4.3, -4.2, 3.1);
    REQUIRE(tuple.x == 4.3f);
    REQUIRE(tuple.y == -4.2f);
    REQUIRE(tuple.z == 3.1f);
    REQUIRE(tuple.w == 0.0f);
    REQUIRE(tuple.is_vector() == true);
}

TEST_CASE("vector() should return a vector tuple") {
    Tuple tuple = Tuple::vector();
    REQUIRE(tuple.x == 0.0f);
    REQUIRE(tuple.y == 0.0f);
    REQUIRE(tuple.z == 0.0f);
    REQUIRE(tuple.w == 0.0f);
    REQUIRE(tuple.is_vector() == true);
}