#pragma once


class Vector3d {
public:
	double x, y, z;

	static Vector3d xAxis; /// A vector representing the x axis
	static Vector3d yAxis; /// A vector representing the y axis
	static Vector3d zAxis; /// A vector representing the z axis
	static Vector3d origin; /// A vector representing the origin

	Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}
};


