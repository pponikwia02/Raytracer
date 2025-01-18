#include "ray.hpp"

ray::ray(const point3 &ori, const vec3d &direction) : dir(direction), origin(ori)
{
}

const vec3d &ray::GetDirection() const
{
    return dir;
}

const point3 &ray::GetOrigin() const
{
    return origin;
}

point3 ray::at(double t)
{
    return origin + t* dir;
}
