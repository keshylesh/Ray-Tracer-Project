#ifndef HITTABLE_H
#define HITTABLE_H

/*
 * Generic hittable class definitions, describes a 'hittable' thing
 */

class hit_record {
	public:
		point3 p;
		vec3 normal;
		double t;
		bool front_face; // whether normal is on outside (true) or inside (false)

		void set_face_normal(const ray& r, const vec3& outward_normal) {
			// Sets the hit record normal vector
			// NOTE: outward_normal is assumed to have unit length
			
			front_face = dot(r.direction(), outward_normal) < 0;
			normal = front_face ? outward_normal : -outward_normal;
		}
};

class hittable {
	public:
		virtual ~hittable() = default;

		/*
		 * Takes in a ray reference, and an interval to detect a hit and 
		 * only register it if between the two bounds
		 */
		virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
