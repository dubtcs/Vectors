#pragma once

#include <iostream>

class Vector3 {
public:
	Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}
	Vector3(float n) : x{ n }, y{ n }, z{ n } {};
	Vector3() :x{ 0 }, y{ 0 }, z{ 0 } {};
	Vector3 operator+(const Vector3& other) { return Vector3{ x + other.x, y + other.y, z + other.z }; }
	Vector3 operator+(float n) { return Vector3{ x + n, y + n, z + n }; }

	Vector3 operator-(const Vector3& other) { return Vector3{ x - other.x, y - other.y, z - other.z }; }
	Vector3 operator-(float n) { return Vector3{ x - n, y - n, z - n }; }

	Vector3 operator*(float n) { return Vector3{ x * n, y * n, z * n }; }
	Vector3 operator/(float n) { return Vector3{ x / n, y / n, z / n }; }

	bool operator==(const Vector3& other) { return (x == other.x) && (y == other.y) && (z == other.z); }
	bool operator!=(const Vector3& other) { return (x != other.x) && (y != other.y) && (z != other.z); }

	friend std::ostream& operator<<(std::ostream& str, const Vector3& me) {
		str << "(" << me.x << ", " << me.y << ", " << me.z << ")";
		return str;
	}
public:
	float Dot(const Vector3& other) { return (x * other.x) + (y * other.y) + (z * other.z); }
	Vector3 Cross(const Vector3& other);
	float Magnitude() { return std::sqrt(x * x + y * y + z * z); }
	Vector3 Unit();
	float Angle(Vector3& other);
	Vector3 Lerp(Vector3& other, float percent);
public:
	float x, y, z;
};

class Vector2 {
public:
	Vector2(float x, float y) : x{ x }, y{ y } {}
	Vector2(float n) : x{ n }, y{ n } {};
	Vector2() :x{ 0 }, y{ 0 } {};
	Vector2 operator+(const Vector2& other) { return Vector2{ x + other.x, y + other.y }; }
	Vector2 operator+(float n) { return Vector2{ x + n, y + n }; }

	Vector2 operator-(const Vector2& other) { return Vector2{ x - other.x, y - other.y }; }
	Vector2 operator-(float n) { return Vector2{ x - n, y - n }; }

	Vector2 operator*(float n) { return Vector2{ x * n, y * n }; }
	Vector2 operator/(float n) { return Vector2{ x / n, y / n }; }

	bool operator==(const Vector2& other) { return (x == other.x) && (y == other.y); }
	bool operator!=(const Vector2& other) { return (x != other.x) && (y != other.y); }

	friend std::ostream& operator<<(std::ostream& str, const Vector2& me) {
		str << "(" << me.x << ", " << me.y << ")";
		return str;
	}
public:
	float Dot(const Vector2& other) { return (x * other.x) + (y * other.y); }
	float Magnitude() { return std::sqrt(x * x + y * y); }
	Vector2 Unit();
	float Angle(Vector2& other);
	Vector2 Lerp(Vector2& other, float percent);
public:
	float x, y;
};
