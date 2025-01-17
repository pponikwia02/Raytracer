#include "camera.hpp"
#include "color.hpp"
camera::camera(int iwidth, double aspect_ratio) : image_width(iwidth),aspect_ratio(aspect_ratio)
{
}
void camera::render()
{
     init();
      std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";
      for(int i=0;i<image_height;i++)
      {
        for (int j = 0; j < image_width; j++)
        {
            color pixel_color = color(double(i)/(image_height-1),double(j)/(image_width-1),0);
            write_color(std::cout, pixel_color);
        }
        
      }
}

void camera::init()
{
    image_height = int(image_width/aspect_ratio);
    
}
