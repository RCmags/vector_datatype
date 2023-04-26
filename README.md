# Vector datatype
This library includes structs for 3d vectors and quaternions. Both vectors and quaternions can perform basic operations such as addition, subtraction, multiplication, division, increment, decrement, etc. Other operations include the dot product, cross product, magnitude, and normalize.  

Quaternions can also be defined as unit quaternions to represent rotations and can be used to rotate and scale vectors. Vectors are compatible with quaternions, and both types are compatible with arrays. A length-3 array can be added, subtracted, etc, from a vector or a quaternion, and a length-4 array can perform the same operations with a quaternion. See the examples for a complete list of the operations available for each type.

## References
For more information on vector and quaternion operations, see these links:  

- [Quaternions and rotations](http://danceswithcode.net/engineeringnotes/quaternions/quaternions.html)
- [Quaternion operations](http://graphics.stanford.edu/courses/cs348a-17-winter/Papers/quaternion.pdf)  
- [Vector operations](http://emweb.unl.edu/Math/mathweb/vectors/vectors.html)

## Diagrams

<p align="center">
<img src="http://danceswithcode.net/engineeringnotes/quaternions/images/axis-angle.png">
<img src="https://opentextbc.ca/calculusv3openstax/wp-content/uploads/sites/288/2019/08/CNX_Calc_Figure_12_02_011.jpg">
</p>
