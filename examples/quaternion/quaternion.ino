/*
 This sketch shows to perform operations on quaternions and how to convert arrays to quaternions.
 */

#include <quaternion_type.h>

// Display functions

void printVector( vec3_t vec ) {
  Serial.print( vec.x );
  Serial.print( ", " );
  Serial.print( vec.y );
  Serial.print( ", " );
  Serial.print( vec.z );
  Serial.println();
}

void printQuat( quat_t quat ) {
  Serial.print( quat.w );
  Serial.print( ", " );
  printVector( quat.v );
}

void setup() { 
  Serial.begin(9600);
  Serial.flush();
  
  //-------- Quaternions --------
  quat_t q1 = { 1, 0, 0, 0 };
  quat_t q2 = { 0, 1, 0, 0 };
  quat_t q3 = { 0, 0, 1, 0 };
  quat_t q4 = { 0, 0, 0, 1 };
  quat_t q5;
  
  //-- Operations:
  //   Quaternions can be manipulated in the same way as scalar values

  // Addition
  q5 = q1 + q2;
  printQuat( q5 );

  // Subtraction
  q5 = q5 - q3;
  printQuat( q5 );

  // Negation:
  q5 = -q5;
  printQuat( q5 );

  // Increment:
  q5 += q4;
  printQuat( q5 );

  // Decrement:
  q5 -= q1;
  printQuat( q5 );

  // Scalar product: 
  q5 = q5*5;
  printQuat( q5 );
    // Reverse order
  q5 = -3*q5;
  printQuat( q5 );
  
  // Scalar divide:
  q5 = q5/8;
  printQuat( q5 );

  // Scalar self multiply:
  q5 *= 10;
  printQuat( q5 );

  // Scalar self divide:
  q5 /= 20;
  printQuat( q5 );

  //- Important operations:
  //  These are useful operations that are commonly encountered. They are explicitly named for clarity.
  
    // Conjugate
  printQuat( q5.conj() );

    // Inner product
  Serial.println( q5.inner() );

    // Magnitude
  Serial.println( q5.mag() );

    // Normalize
  printQuat( q5.norm() );  

  //- Quaternion multiplication and division:
  //  Quats can be multiplied together to generate a new quaternion. This can encode simultaneous rotations. 

    // Multiply
  q5 = q5*q2;
  printQuat( q5 );

    // Divide
  q5 = q5/q2;
  printQuat( q5 );

    // Self multiply
  q5 *= q4;
  printQuat( q5 );

    // Self divide
  q5 /= q3;  
  printQuat( q5 );
  
  //- Vector rotation:
  // A quaternion can rotate and stretch a 3D vector

    // A) Rotate by angle about axis
  constexpr float angle = (PI/180.0) * 30;
  vec3_t axis = { 0, 1, 0 };

  quat_t qrot;
  qrot.setRotation( false, axis, angle );     // Unit quaternion: true = small angle approximation ; false = exact rotation
  vec3_t vec = { 1,0,0 };                     // Vector to rotate

    // Rotate into angle
  printQuat( qrot.rotate(true, vec) );
    // Rotate away from angle
  printQuat( qrot.rotate(false, vec) );
 
    // Axes projections
  printVector( qrot.axisX(true) );
  printVector( qrot.axisY(true) );
  printVector( qrot.axisZ(true) );

    // B) Rotate by unit vector 
  qrot.setRotation( false, axis );     // Unit vector has magniude sin(angle)

  printQuat( qrot.rotate(true, vec) );

  //-- Compatibility with arrays:
  //   In operations between a quaternion and an array, the array will be interpreted as a quaternion.

  float arr[] = {1, 2, 3, 4};
  
  printQuat( qrot + arr );
  printQuat( qrot - arr );
  printQuat( qrot*arr );

  // Operations with arrays are not converted to a quaternion type. These need to be explicitly converted.
  printQuat( quat_t(arr)*3 );
  printQuat( quat_t(arr)/10 );

    printQuat( qrot.rotate(true, vec) );

  //-- Compatibility with vectors
  //   Vectors will be interpreted as quaternions without a scalar value (w = 0)

  vec3_t v = {1, 2, 3};
  quat_t q6 = {1, 3, 3, 3};
  
  printQuat( q6 + v );
  printQuat( q6 - v );
  printQuat( q6*v );
}

void loop() {}
