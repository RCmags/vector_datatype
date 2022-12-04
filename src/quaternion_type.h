#include <Arduino.h>
#include "vector_type.h"

#ifndef quaternion_type_h
#define quaternion_type_h
 
//------- 4D Quaternion --------

struct quat_t {
    // Components:
    float  w;  
    vec3_t v;

    // Constructors:
    quat_t();
    quat_t( float, float, float, float );
    quat_t( float, vec3_t );
    quat_t( vec3_t );
    quat_t( float [] );

    //- Basic Operations:

    // Addition and subtraction:
    quat_t operator + ( const quat_t & );
    quat_t operator - ( const quat_t & );
    quat_t operator - ( void );
    void operator += ( const quat_t & );
    void operator -= ( const quat_t & );

    // Scalar product and division:
    quat_t operator * ( const float );
    quat_t operator / ( const float );
    void operator *= ( const float );
    void operator /= ( const float );

    //- Important operations:
    quat_t conj();
    float inner();
    float mag();
    quat_t norm();

    //- Quaternion multiplication and division:
    quat_t operator * ( const quat_t & );
    quat_t operator / ( quat_t & );
    void operator *= ( const quat_t & );
    void operator /= ( quat_t & );

    //- Set as rotation transform:

    // Axis and angle 
    void setRotation( const bool, vec3_t, float );
    void setRotation( const bool, vec3_t );

    // Vector rotation:
    vec3_t rotate( const bool, vec3_t );

    // Axis vector projections:
    vec3_t axisX( const bool );
    vec3_t axisY( const bool );
    vec3_t axisZ( const bool );
};

// Vector multiplication - Result is quaternion
quat_t operator * ( vec3_t &, vec3_t & );

// Reverse order - Scalar product
quat_t operator * ( const float, quat_t & );

#endif
