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
	std::cout << "If wurde nicht ausgeführt" << std::endl;
	return Vec2{ x /= s, y /= s };
}
