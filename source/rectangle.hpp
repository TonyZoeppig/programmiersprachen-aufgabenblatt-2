#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"

namespace aufgabe2 {
	class Rectangle {
	public:
		Rectangle() = default;
		Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr);
		float circumference() const;
	private:
		Vec2 min_{ 0.0f, 0.0f };
		Vec2 max_{ 1.0f, 1.0f };
		Color color_{ 0.0f, 0.0f, 0.0f };
	};
}

#endif