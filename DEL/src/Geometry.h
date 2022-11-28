#pragma once

#include "Vectors.h"
#include <vector>

class Tri {
public:
	Tri(const Vector3& p1, const Vector3& p2, const Vector3& p3) : points{ p1, p2, p3 } {};
	friend std::ostream& operator<<(std::ostream& str, const Tri& me) {
		str << "[" << me.points[0] << ", " << me.points[1] << ", " << me.points[2] << "]";
		return str;
	}
public:
	Vector3 points[3];
};

class Mesh {
public:
	std::vector<Tri>tris;

};
