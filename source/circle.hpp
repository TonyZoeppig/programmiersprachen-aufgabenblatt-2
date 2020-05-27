#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "Window.hpp"

class Circle {
	public:
		Circle() = default;
		Circle(Vec2 const& cntr, float r, Color const& clr);
		Vec2 center() const;
		float circumference() const;
		void draw(Window const& window) const;
		void draw(Window const& window, float thickness) const;
		bool is_inside(Vec2 const& point) const;
	private:
		Vec2 center_;
		float radius_ = 1.0f;
		Color color_;
};

#endif