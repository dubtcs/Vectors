
#define _USE_MATH_DEFINES
// Right click math.h, then the cpp file and it says to inlude the above

#include <iostream>
#include <assert.h>
#include <math.h>

#include "src/Vectors.h"
#include "src/Geometry.h"

bool CloseEnough(float n1, float n2) {
	return std::abs(n1 - n2) <= 0.001;
}

/*Converts radians to degrees*/
float ToDeg(float n) {
	return n * (180.f/M_PI);
}

int main() {
	Vector3 v1{ 1, 2, 3 };
	Vector3 v2{ 1, 5, 7 };
	std::cout << v2 + 5 << std::endl;

	assert((v1.Cross(v2) == Vector3{ -1,-4,3 }));
	float m = v2.Magnitude();
	Vector3 v2u = v2.Unit();
	assert(CloseEnough(m, 8.66));

	assert(CloseEnough(v2u.x, 0.115));
	assert(CloseEnough(v2u.y, 0.577));
	assert(CloseEnough(v2u.z, 0.808));

	Vector3 lv = v1.Lerp(v2, 0.5);
	assert(CloseEnough(lv.x, 1) && CloseEnough(lv.y, 3.5) && CloseEnough(lv.z, 5));
	lv = v2.Lerp(v1, 0.9);
	assert(CloseEnough(lv.x, 1) && CloseEnough(lv.y, 2.3) && CloseEnough(lv.z, 3.4));

	Tri t1{ v1,v2, Vector3{5,5,6} };
	std::cout << t1;

	std::cout << std::endl;
	for (Vector3& v : t1.points) {
		std::cout << v << std::endl;
	}

	return EXIT_SUCCESS;
}
