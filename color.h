#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>
#define GLM_FORCE_PRECISION_HIGHP_DOUBLE // Enforce double precision

using color = glm::dvec3; // Define color as double-precision vec3

void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

#endif
