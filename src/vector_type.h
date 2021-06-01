#include "arduino.h"

#ifndef vector_type_h
#define vector_type_h

//--------- 3D vector ----------

struct vec3_t { 
	// Components
	float x;
	float y;
	float z;

	//- Constructors:
	vec3_t();
	vec3_t( float, float, float );
	vec3_t( float, float );
	vec3_t( float [] );

	//- Basic operations:

	// Addition and subtration:
	vec3_t operator + ( const vec3_t & );
	vec3_t operator - ( const vec3_t & );
	vec3_t operator - ( void );
	void operator += ( const vec3_t & );
	void operator -= ( const vec3_t & );

	// Scalar multiplication and division:
	vec3_t operator * ( const float );
	vec3_t operator / ( const float );
	void operator *= ( const float );
	void operator /= ( const float );

	// Important operations: 
	float dot( const vec3_t );
	vec3_t cross( const vec3_t );
	float mag();
	vec3_t norm();
};

// Reverse order - Scalar product
vec3_t operator * ( const float, const vec3_t & );

#endif
