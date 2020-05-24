#define _USE_MATH_DEFINES

#include <cmath>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle(Vec2 const& cntr, float r, Color const& clr) :
	center_{cntr},
	radius_{r},
	color_{clr} {}

float Circle::circumference() const
{
	return 2 * M_PI * radius_;
}

void Circle::draw(Window const& window)
{
	Vec2 start_point{ center_.x, center_.y + radius_ };
	Vec2 end_point = start_point;
	Mat2 rotation_matrix = make_rotation_mat2((0.1 * M_PI) / 180);

	for (int i = 1; i <= 3600; ++i) {

		Vec2 next_point = center_ + (rotation_matrix * (end_point - center_));
		// end_point = rotation_matrix * start_point;

		window.draw_line(end_point.x, end_point.y, next_point.x, next_point.y, color_.r, color_.g, color_.b, 1.0f);

		end_point = next_point;
	}
}

void Circle::draw(Window const& window, float thickness)
{
	Vec2 start_point{ center_.x, center_.y + radius_ };
	Vec2 end_point = start_point;
	Mat2 rotation_matrix = make_rotation_mat2((0.1 * M_PI) / 180);

	for (int i = 1; i <= 3600; ++i) {

		Vec2 next_point = center_ + (rotation_matrix * (end_point - center_));
		// end_point = rotation_matrix * start_point;

		window.draw_line(end_point.x, end_point.y, next_point.x, next_point.y, color_.r, color_.g, color_.b, thickness);

		end_point = next_point;
	}
}

bool Circle::is_inside(Vec2 const& point)
{
	float distance = sqrt(pow(point.x - center_.x, 2) + pow(point.y - center_.y, 2));

	if (distance <= radius_) {
		return true;
	}

	return false;
}

