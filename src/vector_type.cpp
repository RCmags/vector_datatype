#include "vector_type.h"

//------------------- Constructors -------------------
  
// Default to zero
vec3_t::vec3_t() {
    x = 0;
    y = 0;
    z = 0;  
}

// Specific components
vec3_t::vec3_t( float _x, float _y, float _z ) {
    x = _x;
    y = _y;
    z = _z;
}

// 2D vector:
vec3_t::vec3_t( float _x, float _y ) {
    x = _x;
    y = _y;
    z = 0;  
}

// Convert from array
vec3_t::vec3_t( float arr[] ) {
    x = arr[0];
    y = arr[1];
    z = arr[2];
}
  
//---------------- Basic operations ------------------

//-- Addition and subtration:

// Addition
vec3_t vec3_t::operator + ( const vec3_t &r ) {
    vec3_t v = { x + r.x ,
                 y + r.y ,
                 z + r.z };
    return v;
}

// Subtraction
vec3_t vec3_t::operator - ( const vec3_t &r ) {
    vec3_t v = { x - r.x ,
                 y - r.y ,
                 z - r.z };
    return v;
}

// Negation
vec3_t vec3_t::operator - ( void ) {
    vec3_t v = { -x ,
                 -y ,
                 -z };
    return v;
}

// Increment
void vec3_t::operator += ( const vec3_t &r ) {
    x += r.x;
    y += r.y;
    z += r.z;
}

// Decrement
void vec3_t::operator -= ( const vec3_t &r ) {
    x -= r.x;
    y -= r.y;
    z -= r.z;
} 

//-------- Scalar multiplication and division --------
  
// Scalar product
vec3_t vec3_t::operator * ( const float s ) {
    vec3_t v = { x * s ,
                 y * s ,
                 z * s };
    return v;
}

// Scalar division
vec3_t vec3_t::operator / ( const float s ) {
    vec3_t v = { x / s ,
                 y / s ,
                 z / s };
    return v;
}

// Self multiply
void vec3_t::operator *= ( const float s ) {
    x *= s;
    y *= s;
    z *= s;
}

// Self divide
void vec3_t::operator /= ( const float s ) {
    x /= s;
    y /= s;
    z /= s;
}

//--------------- Important operations ---------------

// Dot product
float vec3_t::dot( const vec3_t r ) {
    return x*r.x + y*r.y + z*r.z;  
}

// Cross product
vec3_t vec3_t::cross( const vec3_t r ) {
    vec3_t v = { y*r.z - z*r.y  ,
                -x*r.z + z*r.x  ,
                 x*r.y - y*r.x  }; 
    return v;
}

// Magnitude
float vec3_t::mag() {
    return sqrt( x*x + y*y + z*z );
}

// Normalize
vec3_t vec3_t::norm() {
    vec3_t v = { x, y, z };
    return v/mag();
}

//----------------- Global operators -----------------

// Reverse order - Scalar product
vec3_t operator * ( const float s, const vec3_t &r ) {
    vec3_t v = { r.x * s ,
               r.y * s ,
               r.z * s };
    return v;
}