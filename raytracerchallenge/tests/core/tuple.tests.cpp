#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
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
    Tuple tuple(4.3f, -4.2f, 3.1f, 1.0f);
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

TEST_CASE("point() should return a point tuple") {
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

TEST_CASE("testing == for a vector and point") {
    Tuple vector = Tuple::vector(1.0f, 1.0f, 1.0f);
    Tuple point = Tuple::point(1.0f, 1.0f, 1.0f);
    REQUIRE((vector == point) == false);
}

TEST_CASE("testing == for a vector and vector") {
    Tuple vector = Tuple::vector(1.0f, 1.0f, 1.0f);
    Tuple vector2 = Tuple::vector(1.0f, 1.0f, 1.0f);
    REQUIRE((vector == vector2) == true);
}

TEST_CASE("testing == for a point and point") {
    Tuple point= Tuple::point(1.0f, 1.0f, 1.0f);
    Tuple point2 = Tuple::point(1.0f, 1.0f, 1.0f);
    REQUIRE((point == point2) == true);
}

TEST_CASE("testing + of a point and vector tuples") {
    Tuple point(3.0f, -2.0f, 5.0f, 1.0f);
    Tuple vector(-2.0f, 3.0f, 1.0f, 0.0f);
    Tuple sum = point + vector;
    REQUIRE(sum.x == 1.0f);
    REQUIRE(sum.y == 1.0f);
    REQUIRE(sum.z == 6.0f);
    REQUIRE(sum.is_point() == true);
}

TEST_CASE("testing + of a vector and vector tuples") {
    Tuple vector1(3.0f, -2.0f, 5.0f, 0.0f);
    Tuple vector2(-2.0f, 3.0f, 1.0f, 0.0f);
    Tuple sum = vector1 + vector2;
    REQUIRE(sum.x == 1.0f);
    REQUIRE(sum.y == 1.0f);
    REQUIRE(sum.z == 6.0f);
    REQUIRE(sum.is_vector() == true);
}

TEST_CASE("testing + of a point and point tuples") {
    Tuple point1(3.0f, -2.0f, 5.0f, 1.0f);
    Tuple point2(-2.0f, 3.0f, 1.0f, 1.0f);
    REQUIRE_THROWS(point1 + point2);
}

TEST_CASE("testing negation") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    tuple = -tuple;
    REQUIRE(tuple.x == -1.0f);
    REQUIRE(tuple.y == 2.0f);
    REQUIRE(tuple.z == -3.0f);
    REQUIRE(tuple.w == 4.0f);
}

TEST_CASE("testing multiplication scaler") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    float scaler = 3.5f;
    tuple = tuple * scaler;

    REQUIRE(tuple.x == 3.5f);
    REQUIRE(tuple.y == -7.0f);
    REQUIRE(tuple.z == 10.5f);
    REQUIRE(tuple.w == -14.0f);
}

TEST_CASE("testing division scaler") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    float scaler = 2.0f;
    tuple = tuple / scaler;

    REQUIRE(tuple.x == 0.5f);
    REQUIRE(tuple.y == -1.0f);
    REQUIRE(tuple.z == 1.5f);
    REQUIRE(tuple.w == -2.0f);
}

TEST_CASE("testing magnitude") {
    Tuple tuple(1.0, 2.0, 3.0, 0.0);
        
    REQUIRE(Tuple::magnitude(tuple) 
                == Catch::Approx(std::sqrt(14.0f)));
    tuple = Tuple::point(1.0, 2.0, 3.0);

    REQUIRE_THROWS(Tuple::magnitude(tuple));

}

TEST_CASE("normalize vector (1,2,3)") {
    Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);

    Tuple n = Tuple::normalize(v);

    REQUIRE(n.x == Catch::Approx(0.26726124f));
    REQUIRE(n.y == Catch::Approx(0.53452248f));
    REQUIRE(n.z == Catch::Approx(0.80178373f));
    REQUIRE(n.is_vector());
}

TEST_CASE("normalized vector has magnitude 1") {
    Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);

    Tuple n = Tuple::normalize(v);

    REQUIRE(Tuple::magnitude(n) == Catch::Approx(1.0f));
}

TEST_CASE("normalize zero vector throws") {
    Tuple v = Tuple::vector(0.0f, 0.0f, 0.0f);

    REQUIRE_THROWS(Tuple::normalize(v));
}

TEST_CASE("normalize point throws") {
    Tuple p = Tuple::point(1.0f, 2.0f, 3.0f);

    REQUIRE_THROWS(Tuple::normalize(p));
}

TEST_CASE("dot product scaler") {
    Tuple vector1 = Tuple::vector(1, 2, 3);
    Tuple vector2 = Tuple::vector(2, 3, 4);
    
    float dot = Tuple::dot(vector1, vector2);
    REQUIRE(dot == 20.0f);
}

TEST_CASE("dot product throws") {
    Tuple point = Tuple::point(1, 2, 3);
    Tuple vector = Tuple::vector(2, 3, 4);

    REQUIRE_THROWS(Tuple::dot(point, vector));
}

TEST_CASE("cross product vector") {
    Tuple vector1 = Tuple::vector(1, 2, 3);
    Tuple vector2 = Tuple::vector(2, 3, 4);

    REQUIRE(Tuple::cross(vector1, vector2) 
                == Tuple::vector(-1, 2, -1));

    REQUIRE(Tuple::cross(vector2, vector1) 
                == Tuple::vector(1, -2, 1));
}

TEST_CASE("cross product throws") {
    Tuple point = Tuple::point(1, 2, 3);
    Tuple vector = Tuple::vector(2, 3, 4);

    REQUIRE_THROWS(Tuple::cross(point, vector));
}