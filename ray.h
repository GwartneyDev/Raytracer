#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>
#define GLM_FORCE_PRECISION_HIGHP_DOUBLE // Enforce double precision

using vec3 = glm::dvec3;

class ray {
    
public:
    ray() {}
    
    ray(const vec3& origin, const vec3& direction)
    
    : orig(origin), dir(direction) {}
    
    vec3 origin() const {
        return orig;
    }
    
    vec3 direction() const {
        return dir;
    }
    
    vec3 at(double t) const {
        return orig + t * dir;
    }
   
private:
    vec3 orig, dir;
};

#endif
