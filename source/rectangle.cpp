#include "rectangle.hpp"

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr) :
	min_{min},
	max_{max},
	color_{clr} {}
