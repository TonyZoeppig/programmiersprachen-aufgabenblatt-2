#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "Window.hpp"

class Circle {
	public:
		Circle() = default;
		Circle(Vec2 const& cntr, float r, Color const& clr);
		float circumference() const;
		void draw(Window const& window);
		void draw(Window const& window, float thickness);
		bool is_inside(Vec2 const& point);
	private:
		Vec2 center_ = { 0.0f, 0.0f };
		float radius_ = 1.0f;
		Color color_ = { 0.0f, 0.0f, 0.0f };
};

#endif