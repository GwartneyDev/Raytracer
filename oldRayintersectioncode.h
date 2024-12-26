// 
////    // Ray-sphere intersection test function
//    static float hitSphere(const vec3& p0, const vec3& p1, const vec3& center, float radius) {
//        // Displacement vector from the ray's origin (p0) to the center of the sphere
//        vec3 oc = p0 - center;
//
//        // A = p1 · p1: The squared magnitude of the ray's direction
//        float A = glm::dot(p1, p1);
//
//        // B = 2 * (p0 - C) · p1: How the ray moves in relation to the sphere's center
//        float B = 2.0f * glm::dot(oc, p1);
//
//        // C = (p0 - C) · (p0 - C) - r^2: Distance from the origin to the sphere's center minus the squared radius
//        float C_term = glm::dot(oc, oc) - radius * radius;
//
//        // Discriminant = B^2 - 4AC
//        float discriminant = B * B - 4 * A * C_term;
//
//        // If the discriminant is negative, there's no intersection (ray misses the sphere)
//        if (discriminant < 0) {
//            return -1.0f; // No intersection
//        } else {
//            // Calculate the two possible values of t (where the ray intersects the sphere)
//            // We return the smallest t that gives us the intersection point closest to the origin
//            return (-B - sqrt(discriminant)) / (2.0f * A);
//        }
//    }

  // Convert std::array to glm::vec3 for math operations
//     vec3 toVec3(const array<int, 3>& arr) {
//         return glm::vec3(arr[0], arr[1], arr[2]);
//     }
//
//     // Ray equation: r(t) = p0 + t * p1
//    static float hitSphear(const vec3& p0, float t, const vec3& p1, vec3& Center , vec3& Radius) {
//
//
//         vec3 oc = p0 - Center;  // (p0 - C): This is the displacement vector, telling us how far the ray's origin is from the sphere's center.
//
//         float A = glm::dot(p1, p1);// p1 · p1: The magnitude squared of the ray’s direction. This gives us the scaling factor for the ray’s movement. Note this normaly would be tied into the entire
//         //equation and not seperated out.
//
//         float B = 2.0f * glm::dot(oc, p1); // 2 * (p0 - C) · p1: This is telling us how the ray moves toward the sphere aka its 2t (p0 -c)* our direction this would come from the expansion portion
//         //on paper.
//
//
//         ///
//         ///
//         /// Drive straight toward the center:
//         /// Start at the ray’s origin (p0), and the displacement vector (p0 - C)
//         /// is like driving toward the center of the sphere.
//         /// It's simply the vector from the ray's starting point (p0) to the sphere's center (C).
//         /// Turn around and go back toward the surface:
//         /// Once you're heading toward the sphere's center,
//         /// you turn around and head back along the radius toward the sphere's surface.
//         /// That's where you use the radius (r) to adjust how far you need to go back.
//         /// By subtracting r^2 (the squared radius), you're adjusting that displacement
//         /// to reflect where the ray intersects the sphere's surface, not just the center.
//         ///
//         ///
//
//         float C_term = glm::dot(oc, oc) - glm::dot(Radius, Radius);
//
//         // check if our out put is <0
//         auto discriminant = glm::dot(B,B) - 4 * A * C_term;
//
//         if(discriminant < 0){
//                 return -1.0;
//             }
//             else{
//                 return (-B - sqrt(discriminant)) / (2.0 * A);
//             }
//     }
  
//
// Check if the ray hits the sphere
//float t = hitSphere(r.origin(), r.direction(), sphere_center, sphere_radius);


//
//color ray_color(const ray& r) {
//    
//    
//    // Define the sphere's center and radius
//    vec3 sphere_center(0.0f, 0.0f, -1.0f);  // Example sphere center at (0, 0, -1)
//    auto sphere_radius = 0.5f;  // Sphere radius of 0.5
//        
//      
//    sphear sphere(sphere_center, sphere_radius);
//
//
//
//
//    auto ray_tmin = 0.001;  // A small positive value to avoid hitting the origin
//    auto ray_tmax = 100.0;  // Large enough value for the maximum distance
//    // 4. Create a hit_record to store intersection information
//     hit_record rec;
//
//      
//    auto t= sphere.hit(r, ray_tmin, ray_tmax, rec);
//    
//    
//    
//    if (t > 0.0) {
//        vec3 N = normalize(r.at(t) - vec3(0, 0, -1));  // Normalize the normal vector
//        
//        
//        vec3 color_value = 0.5f * (N + vec3(1.0f, 1.0f, 1.0f));  // Ensure the normal is in the [0, 1]
//        
//        return color_value;
//    };
//    
//    
//    // If the ray hits the sphere, return red color
//    if (t > 0.0f) {
//        return color(1.0f, 0.0f, 0.0f);  // Red color
//    }
//    
//    // If the ray misses the sphere, calculate the color based on ray direction
//    vec3 unit_direction = glm::normalize(r.direction());
//    
//    // Calculate t for the gradient effect
//        auto t_gradient = 0.5f * (unit_direction.y + 1.0f);  // Range [0, 1] based on ray's direction
//
//    // Interpolate between white and light blue
//    return (1.0f - t_gradient) * color(1.0f, 1.0f, 1.0f) + t_gradient * color(0.5f, 0.7f, 1.0f);
//}
//
//
//}VectorStruct;
