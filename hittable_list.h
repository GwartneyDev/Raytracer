
#include "ray.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "hittable.h"

 
class hittable_list : public hittable {
    
public:
    std::vector<std::shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) {
        add(object);
    }
    
    //Clear list
    void clear() {
        objects.clear();
    }
    
    void add(std::shared_ptr<hittable> object) {
        //add to end
        objects.push_back(object);
    }
    
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        //This is our temp_record of the intersection
        hit_record temp_rec;
        
        bool hit_anything = false;
        //Start at the furthest intersection point
        auto closest_so_far = ray_tmax;
        
        //loop through the list of objects
        for (const auto& object : objects) {
                    if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
                        //pass in the values set true once we find intersection point
                        hit_anything = true;
                        //set the closest current point in the loop to the intersection point t
                        closest_so_far = temp_rec.t;
                        //update the record
                        rec = temp_rec;
                    }
                }

                return hit_anything;
    }
};
