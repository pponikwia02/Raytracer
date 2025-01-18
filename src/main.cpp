#include "color.hpp"
#include "camera.hpp"
int main()
{
   auto aspec_ratio = 16.0/9.0;
   camera cam(800,aspec_ratio);
   cam.render();
  
    
 
}