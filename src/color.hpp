#pragma once
#include "vec3.hpp"

using color = vec3<double>;
void write_color(std::ostream& out, const vec3<double>& pixel_color)
{
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);
    out<<rbyte<<" "<<gbyte<<" "<<bbyte<<"\n";

}
