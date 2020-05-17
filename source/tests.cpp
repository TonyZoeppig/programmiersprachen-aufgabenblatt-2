#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <vec2.hpp>

TEST_CASE("Vec2", "{Vec2}") {
    Vec2 a;
    Vec2 b{5.1f, -9.3f};
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
    REQUIRE(e.x == Approx(0.0f));
    REQUIRE(e.y == Approx(0.0f));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
