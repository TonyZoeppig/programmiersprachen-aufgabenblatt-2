#define _USE_MATH_DEFINES

#include <cmath>
#include "circle.hpp"
#include "circle.hpp"

Circle::Circle(Vec2 const& cntr, float r, Color const& clr) :
	center_{cntr},
	radius_{r},
	color_{clr} {}

float Circle::circumference() const
{
	return 2 * M_PI * radius_;
}

