#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <vec2.hpp>
#include <mat2.hpp>

TEST_CASE("Vec2", "{Vec2}") {
    Vec2 a;
    Vec2 b{ 5.1f, -9.3f };
    REQUIRE(a.x == 0.0f);
    REQUIRE(a.y == 0.0f);
    REQUIRE(b.x == Approx(5.1f));
    REQUIRE(b.y == Approx(-9.3f));
}

TEST_CASE("Vec2 +=", "{Vec2}") {
    Vec2 a{ 1.0f, 1.0f };
    Vec2 b{ 3.0f, 4.0f };
    a += b;
    REQUIRE(a.x == Approx(4.0f));
    REQUIRE(a.y == Approx(5.0f));

    Vec2 c;
    Vec2 d{ 0.0f, -2.0f };
    c += d;
    REQUIRE(c.x == Approx(0.0f));
    REQUIRE(c.y == Approx(-2.0f));

    Vec2 e{ -1.0f, -1.0f };
    Vec2 f{ 1.0f, 1.0f };
    e += f;
    REQUIRE(e.x == Approx(0.0f));
    REQUIRE(e.y == Approx(0.0f));
}

TEST_CASE("Vec2 -=", "{Vec2}") {
    Vec2 a{ 10.0f, 14.0f };
    Vec2 b{ 3.0f, 4.0f };
    a -= b;
    REQUIRE(a.x == Approx(7.0f));
    REQUIRE(a.y == Approx(10.0f));

    Vec2 c;
    Vec2 d{ 0.0f, 2.0f };
    c -= d;
    REQUIRE(c.x == Approx(0.0f));
    REQUIRE(c.y == Approx(-2.0f));

    Vec2 e{ -1.0f, -1.0f };
    Vec2 f{ 1.0f, 1.0f };
    e -= f;
    REQUIRE(e.x == Approx(-2.0f));
    REQUIRE(e.y == Approx(-2.0f));
}

TEST_CASE("Vec2 *=", "{Vec2}") {
    Vec2 a{ 1.0f, 1.0f };
    float b = 3.5f;
    a *= b;
    REQUIRE(a.x == Approx(3.5f));
    REQUIRE(a.y == Approx(3.5f));

    Vec2 c;
    float d = 2.0;
    c *= d;
    REQUIRE(c.x == Approx(0.0f));
    REQUIRE(c.y == Approx(0.0f));

    Vec2 e{ -1.0f, -1.0f };
    float f = 0.6f;
    e *= f;
    REQUIRE(e.x == Approx(-0.6f));
    REQUIRE(e.y == Approx(-0.6f));
}

TEST_CASE("Vec2 /=", "{Vec2}") {
    Vec2 a{ 9.0f, 12.0f };
    float b = 3.0f;
    a /= b;
    REQUIRE(a.x == Approx(3.0f));
    REQUIRE(a.y == Approx(4.0f));

    Vec2 c;
    float d = 2.0;
    c /= d;
    REQUIRE(c.x == Approx(0.0f));
    REQUIRE(c.y == Approx(0.0f));

    Vec2 e{ -1.0f, -1.0f };
    float f = 0.0f;
    e /= f;
    REQUIRE(e.x == Approx(-1.0f));
    REQUIRE(e.y == Approx(-1.0f));
}

TEST_CASE("Vec2 +", "{Vec2}") {
    Vec2 a{ 9.0f, 12.0f };
    Vec2 b{ 3.0f, 3.6f };
    Vec2 c = a + b;
    REQUIRE(c.x == Approx(12.0f));
    REQUIRE(c.y == Approx(15.6f));

    Vec2 d;
    Vec2 e{ -3.0f, 2.7f };
    Vec2 f = d + e;
    REQUIRE(f.x == Approx(-3.0f));
    REQUIRE(f.y == Approx(2.7f));
}

TEST_CASE("Vec2 -", "{Vec2}") {
    Vec2 a{ 14.7f, 0.6f };
    Vec2 b{ 3.0f, 3.6f };
    Vec2 c = a - b;
    REQUIRE(c.x == Approx(11.7f));
    REQUIRE(c.y == Approx(-3.0f));

    Vec2 d;
    Vec2 e{ -3.0f, 2.7f };
    Vec2 f = d - e;
    REQUIRE(f.x == Approx(3.0f));
    REQUIRE(f.y == Approx(-2.7f));
}

TEST_CASE("Vec2 *", "{Vec2}") {
    Vec2 a{ 9.0f, 12.0f };
    float b = 3.0f;
    Vec2 c = a * b;
    REQUIRE(c.x == Approx(27.0f));
    REQUIRE(c.y == Approx(36.0f));

    Vec2 d;
    float e = 10.0f;
    Vec2 f = d * e;
    REQUIRE(f.x == Approx(0.0f));
    REQUIRE(f.y == Approx(0.0f));

    Vec2 g{ 9.0f, 12.0f };
    float h = 3.0f;
    Vec2 i = h * g;
    REQUIRE(i.x == Approx(27.0f));
    REQUIRE(i.y == Approx(36.0f));

    Vec2 j;
    float k = 10.0f;
    Vec2 l = d * e;
    REQUIRE(l.x == Approx(0.0f));
    REQUIRE(l.y == Approx(0.0f));
}

TEST_CASE("Vec2 /", "{Vec2}") {
    Vec2 a{ 14.0f, 7.0f };
    float b = 7.0f;
    Vec2 c = a / b;
    REQUIRE(c.x == Approx(2.0f));
    REQUIRE(c.y == Approx(1.0f));

    Vec2 d;
    float e = 4.5f;
    Vec2 f = d / e;
    REQUIRE(f.x == Approx(0.0f));
    REQUIRE(f.y == Approx(0.0f));

    Vec2 g{ 3.1f, 4.5f };
    float h = 0;
    Vec2 i = g / h;
    REQUIRE(i.x == Approx(3.1f));
    REQUIRE(i.y == Approx(4.5f));
}

TEST_CASE("MAT2 *=", "{MAT2}") {
    Mat2 a{ 1.0f, 1.0f, 1.0f, 1.0f };
    Mat2 b{ 2.0f, 3.0f, 4.0f, 5.0f };
    a *= b;
    REQUIRE(a.e_00 == Approx(6.0f));
    REQUIRE(a.e_10 == Approx(8.0f));
    REQUIRE(a.e_01 == Approx(6.0f));
    REQUIRE(a.e_11 == Approx(8.0f));

    Mat2 c;
    Mat2 d{ 4.0f, 7.0f, 3.0f, 9.0f };
    c *= d;
    REQUIRE(c.e_00 == Approx(4.0f));
    REQUIRE(c.e_10 == Approx(7.0f));
    REQUIRE(c.e_01 == Approx(3.0f));
    REQUIRE(c.e_11 == Approx(9.0f));
}

TEST_CASE("MAT2 *", "{MAT2}") {
    Mat2 a{ 1.0f, 1.0f, 1.0f, 1.0f };
    Mat2 b{ 2.0f, 3.0f, 4.0f, 5.0f };
    Mat2 c = a * b;
    REQUIRE(c.e_00 == Approx(6.0f));
    REQUIRE(c.e_10 == Approx(8.0f));
    REQUIRE(c.e_01 == Approx(6.0f));
    REQUIRE(c.e_11 == Approx(8.0f));

    Mat2 d;
    Mat2 e{ 4.0f, 7.0f, 3.0f, 9.0f };
    Mat2 f = d * e;
    REQUIRE(f.e_00 == Approx(4.0f));
    REQUIRE(f.e_10 == Approx(7.0f));
    REQUIRE(f.e_01 == Approx(3.0f));
    REQUIRE(f.e_11 == Approx(9.0f));
}

TEST_CASE("MAT2 det", "{MAT2}") {
    Mat2 a = { 3.0f, 7.0f, 1.0f, 4.0f };
    REQUIRE(a.det() == Approx(5.0f));

    Mat2 b;
    REQUIRE(b.det() == Approx(1.0f));
}

TEST_CASE("MAT2 * VEC2", "{MAT2}") {
    Mat2 a = { 3.0f, 7.0f, 1.0f, 4.0f };
    Vec2 b = { 2.0f, 5.0f };
    Vec2 c = a * b;
    REQUIRE(c.x == Approx(41.0f));
    REQUIRE(c.y == Approx(22.0f));

    Mat2 e{};
    Vec2 f{};
    Vec2 g = e * f;
    REQUIRE(g.x == Approx(0.0f));
    REQUIRE(g.y == Approx(0.0f));

    Mat2 h = { 3.0f, 7.0f, 1.0f, 4.0f };
    Vec2 i = { 2.0f, 5.0f };
    Vec2 j = i * h;
    REQUIRE(j.x == Approx(41.0f));
    REQUIRE(j.y == Approx(22.0f));

    Mat2 k{};
    Vec2 l{};
    Vec2 m = l * k;
    REQUIRE(m.x == Approx(0.0f));
    REQUIRE(m.y == Approx(0.0f));
}

TEST_CASE("MAT2 inverse", "{MAT2}") {
    Mat2 a = { 3.0f, 5.0f, 4.0f, 2.0f };
    Mat2 a_inverse = inverse(a);
    REQUIRE(a_inverse.e_00 == Approx(-0.14285f));
    REQUIRE(a_inverse.e_10 == Approx(0.35714f));
    REQUIRE(a_inverse.e_01 == Approx(0.28571f));
    REQUIRE(a_inverse.e_11 == Approx(-0.21428f));

    Mat2 b{};
    Mat2 b_inverse = inverse(b);
    REQUIRE(b_inverse.e_00 == Approx(1.0f));
    REQUIRE(b_inverse.e_10 == Approx(0.0f));
    REQUIRE(b_inverse.e_01 == Approx(0.0f));
    REQUIRE(b_inverse.e_11 == Approx(1.0f));
}

TEST_CASE("MAT2 transpose", "{MAT2}") {
    Mat2 a = { 3.0f, 5.0f, 4.0f, 2.0f };
    Mat2 a_trans = transpose(a);
    REQUIRE(a_trans.e_00 == Approx(3.0f));
    REQUIRE(a_trans.e_10 == Approx(4.0f));
    REQUIRE(a_trans.e_01 == Approx(5.0f));
    REQUIRE(a_trans.e_11 == Approx(2.0f));

    Mat2 b{};
    Mat2 b_trans = transpose(b);
    REQUIRE(b_trans.e_00 == Approx(1.0f));
    REQUIRE(b_trans.e_10 == Approx(0.0f));
    REQUIRE(b_trans.e_01 == Approx(0.0f));
    REQUIRE(b_trans.e_11 == Approx(1.0f));
}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}
