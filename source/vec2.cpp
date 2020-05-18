#include <iostream>
#include "vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& v)
{
	return Vec2{x += v.x, y += v.y};
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
	return Vec2{x -= v.x, y -= v.y};
}

Vec2& Vec2::operator*=(float s)
{
	return Vec2{x *= s, y *= s};
}

Vec2& Vec2::operator/=(float s)
{
	if (s == 0.0f) {
		std::cout << "Eine Division durch 0 ist nicht erlaubt" << std::endl;
		return Vec2{};
	}
	return Vec2{ x /= s, y /= s };
}

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	Vec2 a = u;
	a += v;
	return a;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	Vec2 a = u;
	a -= v;
	return a;
}

Vec2 operator*(Vec2 const& v, float s)
{
	Vec2 a = v;
	a *= s;
	return a;
}

Vec2 operator/(Vec2 const& v, float s)
{
	Vec2 a = v;
	a /= s;
	return a;
}

Vec2 operator*(float s, Vec2 const& v)
{
	Vec2 a = v * s;
	return a;
}
