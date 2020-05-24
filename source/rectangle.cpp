#include "rectangle.hpp"

namespace aufgabe2 {
	Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr) :
		min_{ min },
		max_{ max },
		color_{ clr } {}

	float Rectangle::circumference() const
	{
		return 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
	}

	void Rectangle::draw(Window const& window) const
	{
		// draw top horizontal line
		window.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, 1.0f);

		// draw bottom horizontal line
		window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, 1.0f);

		// draw left vertical line
		window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, 1.0f);

		// draw right vertical line
		window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, 1.0f);
	}

	void Rectangle::draw(Window const& window, float thickness) const
	{
		// draw top horizontal line
		window.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);

		// draw bottom horizontal line
		window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);

		// draw left vertical line
		window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);

		// draw right vertical line
		window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	}
	bool Rectangle::is_inside(Vec2 const& point)
	{
		if (point.x <= max_.x && point.x >= min_.x && point.y <= max_.y && point.y >= min_.y) {
			return true;
		}

		return false;
	}
}

