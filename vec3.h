#ifndef VEC3_H
#define VEC3_H

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
			return *this;
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

		bool near_zero() const {
			// Return true if the vector is close to zero in all dims
			auto s = 1e-8;
			return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < 2) && (std::fabs(e[2]) < s);
		}

		static vec3 random() {
			return vec3(random_double(), random_double(), random_double());
		}

		static vec3 random(double min, double max) {
			return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
		}
};

// point3 just an alias for vec3, for geometric clarity
using point3 = vec3; 

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

inline vec3 operator*(double t, const vec3 &v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

// Dot product
inline double dot(const vec3 &u, const vec3 &v) {
	return (u.e[0] * v.e[0]) + (u.e[1] * v.e[1]) + (u.e[2] * v.e[2]);
}

// Cross product
inline vec3 cross(const vec3 &u, const vec3 &v) {
	return vec3(
		(u.e[1] * v.e[2]) - (u.e[2] * v.e[1]),
		(u.e[2] * v.e[0]) - (u.e[0] * v.e[2]),
		(u.e[0] * v.e[1]) - (u.e[1] * v.e[0])
	);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

/*
 * Returns a random unit vector
 */
inline vec3 random_unit_vector() {
	while (true) {
		auto p = vec3::random(-1, 1);
		auto lensq = p.length_squared();
		if ((lensq > 1e-160) && (lensq <= 1)) {
			return p / sqrt(lensq);
		}
	}
}

/*
 * Checks which hemisphere of the surface the unit vector
 * is on. Since we want it to be a reflected ray, we need it
 * to be on the outer hemisphere. If it's on the outer hemisphere
 * return the vector as is, otherwise return the inverted vector;
 */
inline vec3 random_on_hemisphere(const vec3 &normal) {
	vec3 on_unit_sphere = random_unit_vector();
	if (dot(on_unit_sphere, normal) > 0.0) {
		return on_unit_sphere;
	}
	else {
		return -on_unit_sphere;
	}
}

inline vec3 reflect(const vec3 &v, const vec3 &n) {
	return v - (2 * dot(v, n) * n);
}

#endif
