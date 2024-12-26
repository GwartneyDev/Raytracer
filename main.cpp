#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include "color.h"
#include "ray.h"
#include <array>
#include "sphear.h"
#include "hittable_list.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}
 
using namespace std;
using vec3 = glm::dvec3;

struct{
    
    public:
    
  


    color ray_color(const ray& r, const hittable& world) {
        hit_record rec;
        if (world.hit(r, 0, infinity, rec)) {
           
            return 0.5 *  (rec.normal + vec3(1,1,1));
           }
        
   
        if (world.hit(r, 0, infinity, rec)) {
            return 0.5 * (rec.normal + color(1,1,1));
        }

        vec3 unit_direction = normalize(r.direction());
        auto a = 0.5 *(unit_direction.y + 1.0);
        return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
    }


}VectorStruct;


int main() {
    using vectorHorizontalPosition = glm::vec3;
    using vectorVerticalPosition = glm::vec3;
    using vectorOrigin = glm::vec3;

    // Window dimensions and aspect ratio
    const auto aspect_ratio = 16.0 / 9.0;
    const auto image_width = 400;
    
    
    // World

       hittable_list world;

    world.add(make_shared<sphere>(vec3(0,0,-1),0.5));
    world.add(make_shared<sphere>(vec3(0,-100.5,-1), 100));
       
    
    
    // Ensure the image height is an integer
    const auto image_height = static_cast<int>(image_width / aspect_ratio);
    
    // Camera parameters
    auto viewport_height = 2.0f;  // Ensure these are floats
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0f;

    // Vectors for the camera's position and screen setup
    auto horizontal = vectorHorizontalPosition(viewport_width, 0.0f, 0.0f);
    auto vertical = vectorVerticalPosition(0.0f, viewport_height, 0.0f);
    auto origin = vectorOrigin(0.0f, 0.0f, 0.0f);

    // Calculate the lower left corner of the viewport
    vectorOrigin lower_left_corner = origin - horizontal / 2.0f - vertical / 2.0f - glm::vec3(0.0f, 0.0f, focal_length);
  


    // Open the output file in PPM format
    std::ofstream outfile("output.ppm");
    outfile << "P3\n"; // Magic number for PPM format
    outfile << image_width << " " << image_height << "\n"; // Image dimensions
    outfile << "255\n"; // Maximum color value

    // Loop through the image pixels
    for (auto j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (auto i = 0; i < image_width; i++) {
            // Create a ray for the current pixel
            
            auto u = float(i) / float(image_width - 1); // Cast to float
            auto v = float(image_height - j - 1) / float(image_height - 1); // Cast to float
            
            ray r(origin, lower_left_corner + u *horizontal + v *vertical);

            // Get the color from the ray
            color pixel_color = VectorStruct.ray_color(r, world);
            
            // Write the color to the output file
            write_color(outfile, pixel_color); // Write to the outfile
        }

        outfile << "\n"; // Add a new line after each row of pixels
    }
    
    


 
     

   

    return 0;
}
