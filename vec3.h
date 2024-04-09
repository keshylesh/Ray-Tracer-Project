#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
	public:
		double e[3];
		
		vec3() : e{0, 0, 0} {}
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
		
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		// Negate vector
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; }

		// Vector addition
		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		// Scalar multiplication
		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
		}
		
		vec3& operator/=(double t) {
			return *this *= 1 / t;
		}

		double length() const {
			return sqrt(length_squared());
		}

		double length_squared() const {
			return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
		}
};

// point3 just an alias for vec3, for geometric clarity
using point3 = vec3 

// Vector utiliy functions

// Print vector
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector addition
inline vec3 operator+(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Vector subtraction
inline vec3 operator-(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}


inline vec3 operator*(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}
