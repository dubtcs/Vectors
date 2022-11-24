
#include "Vectors.h"
#include <algorithm>

/*Returns the cross product of another vector.*/
Vector3 Vector3::Cross(const Vector3& other) {
	return Vector3{
		(y * other.z) - (z * other.y),
		(z * other.x) - (x * other.z),
		(x * other.y) - (y * other.x)
	};
}

/*Returns the unit vector*/
Vector3 Vector3::Unit() {
	float mag = this->Magnitude();
	return Vector3{x / mag, y / mag, z / mag};
}

/*Get the angle between this vector and another in RADIANS.*/
float Vector3::Angle(Vector3& other) {
	float top = this->Dot(other);
	float bot = (this->Magnitude()) * (other.Magnitude());
	return std::acos(top / bot);
}

/*Returns a vector interpolated between the two.*/
Vector3 Vector3::Lerp(Vector3& other, float percent) {
	percent = std::max(0.f, std::min(1.f, percent));
	float dx = (other.x - x) * percent;
	float dy = (other.y - y) * percent;
	float dz = (other.z - z) * percent;
	return Vector3{ x + dx, y + dy, z + dz };
}

/*Returns the unit vector*/
Vector2 Vector2::Unit() {
	float mag = this->Magnitude();
	return Vector2{ x / mag,y / mag };
}

/*Get the angle between this vector and another in RADIANS.*/
float Vector2::Angle(Vector2& other) {
	float top = this->Dot(other);
	float bot = (this->Magnitude()) * (other.Magnitude());
	return std::acos(top / bot);
}

/*Returns a vector interpolated between the two.*/
Vector2 Vector2::Lerp(Vector2& other, float percent) {
	percent = std::max(0.f, std::min(1.f, percent));
	float dx = (other.x - x) * percent;
	float dy = (other.y - y) * percent;
	return Vector2{ x + dx, y + dy };
}
