/*
 This sketch shows to perform operations on vectors and how to convert arrays to vectors.
 */

#include <vector_type.h>

// Display function
void printVector( vec3_t vec ) {
  Serial.print( vec.x );
  Serial.print( ", " );
  Serial.print( vec.y );
  Serial.print( ", " );
  Serial.print( vec.z );
  Serial.println();
}

void setup() { 
  Serial.begin(9600);
  Serial.flush();
  
  //-------- Vectors -------- 
  vec3_t v1 = { 1, 0, 0 };
  vec3_t v2 = { 0, 1, 0 };
  vec3_t v3 = { 0, 0, 1 }; 
  vec3_t v4;

  //-- Operations: 
  //   Vectors can be manipulated in the same way as scalar values

  // Addition
  v4= v1 + v2;
  printVector( v4 );

  // Subtraction
  v4 = v4 - v3;
  printVector( v4 );

  // Negation:
  v4 = -v4;
  printVector( v4 );

  // Increment:
  v4 += v2;
  printVector( v4 );

  // Decrement:
  v4 -= v1;
  printVector( v4 );

  // Scalar product: 
  v4 = v4*5;
  printVector( v4 );
  
    // Reverse order
  v4 = -3*v4;
  printVector( v4 );

  // Scalar divide:
  v4 = v4/8;
  printVector( v4 );

  // Self multiply:
  v4 *= 10;
  printVector( v4 );

  // Self divide:
  v4 /= 20;
  printVector( v4 );

  //-- Important operations: 
  //  These are useful operations that are commonly encountered. They are explicitly named for clarity.
  
    // Dot product
  Serial.println( v4.dot(v1) );

    // Cross product
  v4 = v4.cross(v1);
  printVector( v4 );

    // Magnitude
  Serial.println( v4.mag() );

    // Normalize
  printVector( v4.norm() );  

  //-- Compatibility with arrays:
  //   In operations between a vector and an array, the array will be interpreted as a vector.

  float arr[] = {1, 2, 3};
  
  printVector( v4 + arr );
  printVector( v4 - arr );
  printVector( v4.cross(arr) );
  Serial.println( v4.dot(arr) );

  // Operations with arrays are not converted to a vector type. These need to be explicitly converted.
  printVector( vec3_t(arr)*3 );
  printVector( vec3_t(arr)/10 );
}

void loop() {}
