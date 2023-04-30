/*
 This sketch shows to perform operations on quaternions and how to convert arrays to quaternions.
 */

#include <quaternion_type.h>

//======= Display functions =======

void printQuat( vec3_t vec ) {
  Serial.print( vec.x );
  Serial.print( ", " );
  Serial.print( vec.y );
  Serial.print( ", " );
  Serial.print( vec.z );
}

void printQuat( quat_t quat ) {
  Serial.print( quat.w );
  Serial.print( ", " );
  printQuat( quat.v );
}

template<typename T=quat_t>
void printOperation(String label, T input) {
  Serial.println(label);
  Serial.print( "\t\t(" );
  printQuat(input);
  Serial.print( ")\n\n" );
}

//========== Main program =========

void setup() { 
  Serial.begin(9600);
  Serial.flush();
  
  //-------- Quaternions --------

  // 0. Setters and getters:
  quat_t q1 = { 1, 0, 0, 0 };
  quat_t q2 = { 0, 1, 0, 0 };
  quat_t q3 = { 0, 0, 1, 0 };
  quat_t q4 = { 0, 0, 0, 1 };

  // initialize with vector as array
  quat_t q5;
  
  for( int i = 0; i < 4; i += 1 ) {
    q5.set(i, 2*i + 1); // (index, value)
  }

  /* access component at index using: quat_t.get(index) */

  // copy vector into array
  float arr_q[4]; q5.copyArray(arr_q);
  printOperation( "0. Copy into array", quat_t(arr_q) );
  
  // 1. Basic operations:
  //   Quaternions can be manipulated in the same way as scalar values

  // Addition
  q5 = q1 + q2;
  printOperation( "1. Addition: ", q5 );

  // Subtraction
  q5 = q2 - q3;
  printOperation( "2. Subtraction: ", q5 );

  // Negation:
  q5 = -q5;
  printOperation( "3. Negation: ", q5 );

  // Increment:
  q5 += q4;
  printOperation( "4. Increment: ", q5 );

  // Decrement:
  q5 -= q1;
  printOperation( "5. Decrement: ", q5 );

  // Scalar product: 
  q5 = q5*5;
  printOperation( "6A. Scalar product: ", q5 );
    // Reverse order
  q5 = -3*q5;
  printOperation( "6B. Scalar product (reverse order): ", q5 );
  
  // Scalar divide:
  q5 = q5/8;
  printOperation( "7. Scalar divide: ", q5 );

  // Scalar self multiply:
  q5 *= 10;
  printOperation( "8. Scalar self multiply: ", q5 );

  // Scalar self divide:
  q5 /= 2;
  printOperation( "9. Scalar self divide: ", q5 );

  // Element-wise multiplication
  quat_t q6 = q5 ^ q4;
  printOperation( "10A. Element-wise multiply", q6 );

  // self element-wise multiply
  q6 ^= q5;
  printOperation( "10B. Self Element-wise multiply", q6 ); 


  // 2. Quaternion multiplication and division:
  /* Quats can be multiplied together to generate a new quaternion. This can encode multiple rotations */

    // Multiply
  q5 = q5*q1;
  printOperation( "11. Quaternion multiply: ", q5 );

    // Divide
  q5 = q5/q2;
  printOperation( "12. Quaternion division: ", q5 );
  
    // Self multiply
  q5 *= q3;
  printOperation( "13. Quaternion self multiply: ", q5 );

    // Self divide
  q5 /= q4;  
  printOperation( "14. Quaternion self divide: ", q5 );

  // 3. Important operations:
  
    // Conjugate
  printOperation( "15. Conjugate: ", q5.conj() );  

    // Normalize
  printOperation( "16. Normalize: ", q5.norm() );

    // Inner product
  Serial.print( "17. Inner product: " );
  Serial.println( q5.inner() );

    // Magnitude
  Serial.print( "18. Magnitude: " );
  Serial.print( q5.mag() );
  Serial.print("\n\n");

  // 4. Compatibility with arrays:
  /* In operations between a quaternion and an array, the array will be interpreted as a quaternion */
  float arr[] = {1, 2, 3, 4};

  printOperation( "19. Quaternion and array addition: "   , q5 + arr );
  printOperation( "20. Quaternion and array subtraction: ", q5 - arr );
  printOperation( "21. Quaternion and array multiply: "   , q5 * arr );

  // Operations with arrays are not converted to a quaternion type. These need to be explicitly converted.
  printOperation( "22. Array conversion (multiply): ", quat_t(arr)*3 );
  printOperation( "23. Array conversion (divide): "  , quat_t(arr)/10 );

  //-- Compatibility with vectors
  /* Vectors will be interpreted as quaternions without a scalar value (w = 0) */
  vec3_t vec = {1, 2, 3};

  printOperation( "24. Quaternion and vector addition: "   , q5 + vec );
  printOperation( "25. Quaternion and vector subtraction: ", q5 - vec );
  printOperation( "26. Quaternion and vector multiply; "   , q5 * vec );
  
  // 5. Vector rotation: a quaternion can rotate and stretch a 3D vector

  // A) Rotate by angle about axis
  constexpr float angle = (PI/180.0) * 30;
  vec3_t axis = { 0, 1, 0 };

  /* Can choose between LARGE_ANGLE and SMALL_ANGLE. 
   * Use SMALL_ANGLE for a small angle approximation (less than 30 deg) and faster excecution */
  quat_t qrot; qrot.setRotation( axis, angle, SMALL_ANGLE );   
  vec3_t vec_rot;                                               // rotated vector
  vec = { 1,0,0 };                                              // initial vector

      // Rotate into angle
  vec_rot = qrot.rotate(vec, GLOBAL_FRAME);            

  printOperation<vec3_t>( "27. Rotate by axis and angle (Global): ", vec_rot );

      // Rotate away from angle
  vec_rot = qrot.rotate(vec, LOCAL_FRAME);   
  
  printOperation<vec3_t>( "28. Rotate by axis and angle (local): ", vec_rot );

  // B) Rotate by unit vector of magnitude sin(angle)
  qrot.setRotation( axis, LARGE_ANGLE );     
  vec_rot = qrot.rotate(vec, GLOBAL_FRAME);
    
  printOperation<vec3_t>( "29. Rotate by unit vector: ", vec_rot );
 
  // 6. Axes projections: can choose between GLOBAL_FRAME and LOCAL_FRAME
  /* GLOBAL_FRAME projects local axis-vectors to global coordinates 
   * LOCAL_FRAME projects global axis-vectors to local coordinates */
  qrot.setRotation( axis, angle, LARGE_ANGLE );
  
  vec3_t x = qrot.axisX(GLOBAL_FRAME);    
  vec3_t y = qrot.axisY(GLOBAL_FRAME);
  vec3_t z = qrot.axisZ(GLOBAL_FRAME);
    
  printOperation<vec3_t>( "30. X-axis vector: ", x );    
  printOperation<vec3_t>( "31. Y-axis vector: ", y );
  printOperation<vec3_t>( "32. Z-axis vector: ", z );
}

void loop() {}
