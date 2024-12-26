#include "ray.h"
#include <glm/glm.hpp> // Include the glm library for vec3
 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef HITTABLE_H
#define HITTABLE_H

using namespace std;

class hit_record{
  
    using vec3 = glm::dvec3;

    public:
        vec3 p;
        vec3 normal;
        double t;
};

class hittable {
    public:
    virtual ~hittable()= default;
        
        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};
#endif
