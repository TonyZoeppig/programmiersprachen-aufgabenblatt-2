#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m) {

	float a = e_00;
	float b = e_10;
	float c = e_01;
	float d = e_11;

	e_00 = (a * m.e_00) + (b * m.e_01);
	e_10 = (a * m.e_10) + (b * m.e_11);
	e_01 = (c * m.e_00) + (d * m.e_01);
	e_11 = (c * m.e_10) + (d * m.e_11);

	return Mat2{};
}

float Mat2::det() const
{
	return (e_00 * e_11) - (e_01 * e_10);
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	float x = (m.e_00 * v.x) + (m.e_10 * v.y);
	float y = (m.e_01 * v.x) + (m.e_11 * v.y);

	return Vec2{ x, y };
}

Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
	Vec2 a = m * v;
	return a;
}

Mat2 inverse(Mat2 const& m)
{
	float x = 1 / m.det();

	float a = m.e_11 * x;
	float b = -m.e_10 * x;
	float c = -m.e_01 * x;
	float d = m.e_00 * x;

	return Mat2{ a, b, c, d };
}

Mat2 transpose(Mat2 const& m)
{
	float a = m.e_00;
	float b = m.e_01;
	float c = m.e_10;
	float d = m.e_11;

	return Mat2{ a, b, c, d };
}

Mat2 make_rotation_mat2(float phi)
{
	float a = cos(phi);
	float b = -sin(phi);
	float c = sin(phi);
	float d = cos(phi);

	return Mat2{ a, b, c, d };
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
	Mat2 m3 = m1;
	m3 *= m2;
	return m3;
}