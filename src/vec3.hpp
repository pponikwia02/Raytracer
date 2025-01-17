//Template class that define 3-d vector. It will provide basic utilities like operator overload, methods to calculate vector length etc...
#pragma once
#include <iostream>
#include <cmath>
template<typename T>
class vec3
{
    public:
    T x,y,z;
    vec3() : x(T(0)),y(T(0)),z(T(0)) {}
    vec3(T xx, T yy, T zz) : x(xx),y(yy),z(zz){}

    vec3 operator-()const {return vec3{-x,-y,-z};}
    vec3 operator-(const vec3& v)const {return vec3(x-v.x,y-v.y,z-v.z);}
    vec3 operator+ (const vec3& v) const {return vec3(x+v.x,y+v.y,z+v.z);}
    vec3 operator*(const vec3& v) const {return vec3(x*v.x,y*v.y,z*v.z);}
    vec3 operator* (const T& t) const {return vec3(x*t,y*t,z*t);}
    vec3 operator/(const T& t) const {return vec3(x,y,z) *=(1/t);}
    

    vec3& operator +=(const vec3& v) {x+=v.x; y+=v.y; z+=v.z; return *this;}
    vec3& operator *=(const vec3& v) {x*=v.x; y*=v.y; z*=v.z; return *this;}
    vec3& operator /=(const vec3& v) {x/=v.x; y/=v.y; z/=v.z; return *this;}
    
    friend std::ostream& operator<<(std::ostream& out, vec3& v)
    {return out<<v.x<<" "<<v.y<" "<<v.z<<"\n";}
    friend vec3 operator * (const T &r, const vec3 &v)
    { return vec3<T>(v.x * r, v.y * r, v.z * r); }
    friend vec3 operator / (const T &r, const vec3 &v)
    { return vec3<T>(r / v.x, r / v.y, r / v.z); }
    //accessors
    const T& operator[] (u_int8_t i) {return (&x)[i];}
    T& operator[] (u_int8_t i) const {return (&x)[i];}

    T length() const {return std::sqrt(lengthSquared());}
    T lengthSquared() const {return x*x+y*y+z*z;}
    T dotProduct(const vec3& v) {return *this *= v;}
    vec3 crossProduct(const vec3& v) {return vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);}
};
