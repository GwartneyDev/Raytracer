#include "ray.h"
#include <glm/glm.hpp> // Include the glm library for vec3
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "hittable.h"

class sphere : public hittable {
private:
    using point3 = glm::dvec3;  // Change to dvec3 for double precision
    point3 center;  // The center of the sphere
    double radius;  // The radius of the sphere
    
public:
    sphere() = default; // Default constructor
    
    sphere(const point3& cen, double r) : center(cen), radius(r) {} // Parameterized constructor
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        // Displacement vector from the ray's origin (p0) to the center of the sphere
        glm::dvec3 oc = r.origin() - center;  // Vector from ray origin to sphere center
        
        // A = p1 · p1: The squared magnitude of the ray's direction
        double A = glm::dot(r.direction(), r.direction());
        
        // B = 2 * (p0 - C) · p1: How the ray moves in relation to the sphere's center
        double B = 2.0 * glm::dot(oc, r.direction());
        
        // C = (p0 - C) · (p0 - C) - r^2: Distance from the origin to the sphere's center minus the squared radius
        double C_term = glm::dot(oc, oc) - radius * radius;
        
        // Discriminant = B^2 - 4AC
        double discriminant = B * B - 4.0 * A * C_term;
        
        // If the discriminant is negative, there's no intersection (ray misses the sphere)
        if (discriminant < 0) {
            return false;  // No intersection
        } else {
            // Calculate the square root of the discriminant
            double sqrtd = sqrt(discriminant);
            
            // The two possible values of t (where the ray intersects the sphere)
            double root = (-B - sqrtd) / (2.0 * A);
            
            // If the first root is not in the valid range, try the second root
            if (root <= ray_tmin || ray_tmax <= root) {
                root = (-B + sqrtd) / (2.0 * A);
                
                // If the second root is also not in the valid range, return no intersection
                if (root <= ray_tmin || ray_tmax <= root) {
                    return false;  // No valid intersection within the valid range
                }
            }
            
            // Set the hit record
            rec.t = root;
            rec.p = r.at(rec.t);
            
            // Cast center to glm::vec3 (float) before subtracting
            rec.normal = glm::normalize(rec.p - center);  // Normalize the vector
            return true;
        }
    }
};
