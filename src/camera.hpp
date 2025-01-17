#pragma once
#include "vec3.hpp"

class camera
{
    public:
    camera(int iwidth, double aspect_ratio);
    void render();
 
    private:
    void init();
    double aspect_ratio;
    int image_width;
    int image_height;
    point3 camera_center;
    point3 point00; // location of point (0,0)
    vec3d delta_v; //difference between each pixel center verticaly
    vec3d delta_u; // same but horizontaly;

    
};