#pragma once
#include "vec3.hpp"
class ray
{
    public:
    ray() {}
    ray(const point3& ori,const vec3d& direction) ;
     const vec3d& GetDirection() const;
    
    const point3& GetOrigin() const;
   
    point3 at(double t);
    

    private:
    vec3d dir;
    point3 origin;
};