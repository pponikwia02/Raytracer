#include "camera.hpp"

camera::camera(int iwidth, double aspect_ratio) : image_width(iwidth),aspect_ratio(aspect_ratio)
{
}
void camera::render()
{
     init();
     
      std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";
      for(int j=0;j<image_height;j++)
      {
       
        for (int i = 0; i< image_width; i++)
        {
            ray r =get_ray(i,j);
            color pixel_color = ray_color(r);
            
            
            write_color(std::cout, pixel_color);

        }
        
      }
}

color camera::ray_color(const ray &r)
{
  vec3d unit_direction = unit_vector(r.GetDirection());
     auto a = 0.5*(unit_direction[1] + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

ray camera::get_ray(int x, int y)
{
    auto pixel_center = point00 + (y*delta_v) + (x*delta_h);
    auto ray_direction = pixel_center - camera_center;
    return ray{camera_center,ray_direction};
}

void camera::init()
{
    image_height = int(image_width/aspect_ratio);
    camera_center = point3(0,0,0);
    double focal_length = 1.0;

    double viewport_height = 2.0;
    double viewport_width = viewport_height*double((image_width/image_height));
    
    vec3d Vh {viewport_width,0,0};
    vec3d Vv {0,-viewport_height,0};
    delta_v = Vv/image_height;
    delta_h = Vh/image_width;
    
    auto upper_left = camera_center - vec3d{0,0,focal_length} - Vv/2 - Vh/2;
    point00 = upper_left + 0.5*(delta_v + delta_h);
    



}
