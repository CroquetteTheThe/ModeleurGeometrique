#pragma once


class Vector3f {
public:
	float x, y, z;

	static Vector3f xAxis; /// A vector representing the x axis
	static Vector3f yAxis; /// A vector representing the y axis
	static Vector3f zAxis; /// A vector representing the z axis
	static Vector3f origin; /// A vector representing the origin

	Vector3f(float x, float y, float z) : x(x), y(y), z(z) {};

	Vector3f() : x(0.f), y(0.f), z(0.f) {};


};