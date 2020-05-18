
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

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
	Mat2 m3 = m1;
	m3 *= m2;
	return m3;
}