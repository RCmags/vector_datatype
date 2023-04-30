/*
 This sketch shows to perform operations on vectors and how to convert arrays to vectors.
 */

#include <vector_type.h>

//======= Display functions =======

void printVector( vec3_t vec ) {
  Serial.print( vec.x );
  Serial.print( ", " );
  Serial.print( vec.y );
  Serial.print( ", " );
  Serial.print( vec.z );
}

void printOperation(String label, vec3_t input) {
  Serial.println(label);
  Serial.print( "\t\t(" );
  printVector(input);
  Serial.print( ")\n\n" );
}

//========== Main program =========

void setup() { 
  Serial.begin(9600);
  Serial.flush();
  
  //-------- Vectors -------- 
  
  // 0. Setters and getters:
  vec3_t v1 = { 1, 0, 0 };
  vec3_t v2 = { 0, 1, 0 };
  vec3_t v3 = { 0, 0, 1 }; 

  // initialize with vector as array
  vec3_t v4;
  
  for( int i = 0; i < 3; i += 1 ) {
    v4.set(i, 2*i + 1); // (index, value)
  }
  
  /* access component at index using: vec3_t.get(index) */

  // copy vector into array
  float arr_v[3]; v4.copyArray(arr_v);
  printOperation( "0. Copy into array", vec3_t(arr_v) );
  
  // 1. Operations: 
  //   Vectors can be manipulated in the same way as scalar values

  // Addition
  v4 = v1 + v2;
  printOperation( "1. Addition: ", v4 );

  // Subtraction
  v4 = v4 - v3;
  printOperation( "2. Subtraction: ", v4 );

  // Negation:
  v4 = -v4;
  printOperation( "3. Negation: ", v4 );

  // Increment:
  v4 += v2;
  printOperation( "4. Increment: ", v4 );

  // Decrement:
  v4 -= v1;
  printOperation( "5. Decrement: ", v4 );

  // Scalar product: 
  v4 = v4*5;
  printOperation( "6A. Scalar product: ", v4 );
  
    // Reverse order
  v4 = -3*v4;
  printOperation( "6B. Scalar product (reverse order): ", v4 );

  // Scalar divide:
  v4 = v4/8;
  printOperation( "7. Scalar divide: ", v4 );

  // Self multiply:
  v4 *= 10;
  printOperation( "8. Self multiply: ", v4 );

  // Self divide:
  v4 /= 20;
  printOperation( "9. Self divide: ", v4 );

  // Element-wise multiplication
  vec3_t v5 = v3 ^ v4;
  printOperation( "10A. Element-wise multiply", v5 );

    // self element-wise multiply
  v5 ^= v4;
  printOperation( "10B. Self Element-wise multiply", v5 ); 

  // 2. Important operations: 
  //  These are useful operations that are commonly encountered. They are explicitly named for clarity.

    // Normalize
  printOperation( "11. Normalize vector: ", v4.norm() ); 

    // Cross product
  v4 = v4.cross(v1);
  printOperation( "12. Cross product: ", v4 );
  
    // Dot product
  Serial.print( "13. Dot product: " );
  Serial.println( v4.dot(v2) );

    // Magnitude
  Serial.print( "14. Magnitude: " );
  Serial.print( v4.mag() );
  Serial.println("\n");

  // 3. Compatibility with arrays:
  //   In operations between a vector and an array, the array will be interpreted as a vector.

  float arr[] = {1, 2, 3};
  
  printOperation( "15. Vector and array addition: "     , v4 + arr );
  printOperation( "16. Vector and array subtraction: "  , v4 - arr );
  printOperation( "17. Vector and array cross product: ", v4.cross(arr) );

  Serial.print( "18. Dot product (array): " );
  Serial.print( v4.dot(arr) );
  Serial.println("\n");

  // Operations with arrays are not converted to a vector type. These need to be explicitly converted.
  printOperation( "19. Array conversion (multiply): ", vec3_t(arr)*3 );
  printOperation( "20. Array conversion (divide): ", vec3_t(arr)/10 );
}

void loop() {}
