#include <catch2/catch_test_macros.hpp>
#include "core/tuple.h"
#include "core/math_utils.h"

TEST_CASE("Tuple() constructor check") {
    Tuple tuple;
    REQUIRE(rtc::float_equals(tuple.x, 0.0f));
    REQUIRE(rtc::float_equals(tuple.y, 0.0f));
    REQUIRE(rtc::float_equals(tuple.z, 0.0f));
    REQUIRE(rtc::float_equals(tuple.w, 1.0f));
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("Tuple(x,y,z,w) constructor check point") {
    Tuple tuple(4.3f, -4.2f, 3.1f, 1.0f);
    REQUIRE(rtc::float_equals(tuple.x, 4.3f));
    REQUIRE(rtc::float_equals(tuple.y, -4.2f));
    REQUIRE(rtc::float_equals(tuple.z, 3.1f));
    REQUIRE(rtc::float_equals(tuple.w, 1.0f));
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("Tuple(x,y,z,w) constructor check vector") {
    Tuple tuple(4.3, -4.2, 3.1, 0.0);
    REQUIRE(rtc::float_equals(tuple.x, 4.3f));
    REQUIRE(rtc::float_equals(tuple.y, -4.2f));
    REQUIRE(rtc::float_equals(tuple.z, 3.1f));
    REQUIRE(rtc::float_equals(tuple.w, 0.0f));
    REQUIRE(tuple.is_vector() == true);
}

TEST_CASE("point(x,y,z) should return a point tuple") {
    Tuple tuple = Tuple::point(4.3, -4.2, 3.1);
    REQUIRE(rtc::float_equals(tuple.x, 4.3f));
    REQUIRE(rtc::float_equals(tuple.y, -4.2f));
    REQUIRE(rtc::float_equals(tuple.z, 3.1f));
    REQUIRE(rtc::float_equals(tuple.w, 1.0f));
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("point() should return a point tuple") {
    Tuple tuple = Tuple::point();
    REQUIRE(rtc::float_equals(tuple.x, 0.0f));
    REQUIRE(rtc::float_equals(tuple.y, 0.0f));
    REQUIRE(rtc::float_equals(tuple.z, 0.0f));
    REQUIRE(rtc::float_equals(tuple.w, 1.0f));
    REQUIRE(tuple.is_point() == true);
}

TEST_CASE("vector(x,y,z) should return a vector tuple") {
    Tuple tuple = Tuple::vector(4.3, -4.2, 3.1);
    REQUIRE(rtc::float_equals(tuple.x, 4.3f));
    REQUIRE(rtc::float_equals(tuple.y, -4.2f));
    REQUIRE(rtc::float_equals(tuple.z, 3.1f));
    REQUIRE(rtc::float_equals(tuple.w, 0.0f));
    REQUIRE(tuple.is_vector() == true);
}

TEST_CASE("vector() should return a vector tuple") {
    Tuple tuple = Tuple::vector();
    REQUIRE(rtc::float_equals(tuple.x, 0.0f));
    REQUIRE(rtc::float_equals(tuple.y, 0.0f));
    REQUIRE(rtc::float_equals(tuple.z, 0.0f));
    REQUIRE(rtc::float_equals(tuple.w, 0.0f));
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
    REQUIRE(rtc::float_equals(sum.x, 1.0f));
    REQUIRE(rtc::float_equals(sum.y, 1.0f));
    REQUIRE(rtc::float_equals(sum.z, 6.0f));
    REQUIRE(sum.is_point() == true);
}

TEST_CASE("testing + of a vector and vector tuples") {
    Tuple vector1(3.0f, -2.0f, 5.0f, 0.0f);
    Tuple vector2(-2.0f, 3.0f, 1.0f, 0.0f);
    Tuple sum = vector1 + vector2;
    REQUIRE(rtc::float_equals(sum.x, 1.0f));
    REQUIRE(rtc::float_equals(sum.y, 1.0f));
    REQUIRE(rtc::float_equals(sum.z, 6.0f));
    REQUIRE(sum.is_vector() == true);
}

TEST_CASE("testing + of a point and point tuples") {
    Tuple point1(3.0f, -2.0f, 5.0f, 1.0f);
    Tuple point2(-2.0f, 3.0f, 1.0f, 1.0f);
}

TEST_CASE("testing negation") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    tuple = -tuple;
    REQUIRE(rtc::float_equals(tuple.x, -1.0f));
    REQUIRE(rtc::float_equals(tuple.y, 2.0f));
    REQUIRE(rtc::float_equals(tuple.z, -3.0f));
    REQUIRE(rtc::float_equals(tuple.w, 4.0f));
}

TEST_CASE("testing multiplication scaler") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    float scaler = 3.5f;
    tuple = tuple * scaler;

    REQUIRE(rtc::float_equals(tuple.x, 3.5f));
    REQUIRE(rtc::float_equals(tuple.y, -7.0f));
    REQUIRE(rtc::float_equals(tuple.z, 10.5f));
    REQUIRE(rtc::float_equals(tuple.w, -14.0f));
}

TEST_CASE("testing division scaler") {
    Tuple tuple(1.0f, -2.0f, 3.0f, -4.0f);
    float scaler = 2.0f;
    tuple = tuple / scaler;

    REQUIRE(rtc::float_equals(tuple.x, 0.5f));
    REQUIRE(rtc::float_equals(tuple.y, -1.0f));
    REQUIRE(rtc::float_equals(tuple.z, 1.5f));
    REQUIRE(rtc::float_equals(tuple.w, -2.0f));
}

TEST_CASE("testing magnitude") {
    Tuple tuple(1.0, 2.0, 3.0, 0.0);
        
    REQUIRE(rtc::float_equals(
        Tuple::magnitude(tuple),
        std::sqrt(14.0f)
    ));
    tuple = Tuple::point(1.0, 2.0, 3.0);

    REQUIRE_THROWS(Tuple::magnitude(tuple));

}

TEST_CASE("normalize vector (1,2,3)") {
    Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);

    Tuple n = Tuple::normalize(v);

    REQUIRE(rtc::float_equals(n.x, 0.26726124f));
    REQUIRE(rtc::float_equals(n.y, 0.53452248f));
    REQUIRE(rtc::float_equals(n.z, 0.80178373f));
    REQUIRE(n.is_vector());
}

TEST_CASE("normalized vector has magnitude 1") {
    Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);

    Tuple n = Tuple::normalize(v);

    REQUIRE(rtc::float_equals(Tuple::magnitude(n), 1.0f));
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
    REQUIRE(rtc::float_equals(dot, 20.0f));
}

TEST_CASE("cross product vector") {
    Tuple vector1 = Tuple::vector(1, 2, 3);
    Tuple vector2 = Tuple::vector(2, 3, 4);

    REQUIRE(Tuple::cross(vector1, vector2) 
                == Tuple::vector(-1, 2, -1));

    REQUIRE(Tuple::cross(vector2, vector1) 
                == Tuple::vector(1, -2, 1));
}
