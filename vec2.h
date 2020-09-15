#ifndef VEC2_H
#define VEC2_H

#include <stdint.h>

/**
 * Copy the values from one vec2 to another
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a the source vector
 */
void vec2_copy(float* dst, float* a);

/**
 * Set the components of a vec2 to the given values
 *
 * @param {vec2} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 */
void vec2_set(float* dst, float x, float y);

/**
 * Adds two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_add(float* dst, float* b);

/**
 * Subtracts vector b from vector a
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_subtract(float* dst, float* b);

/**
 * Multiplies two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_multiply(float* dst, float* b);

/**
 * Divides two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_divide(float* dst, float* b);

/**
 * ceilf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_ceil(float* dst);

/**
 * floorf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_floor(float* dst);

/**
 * Returns the minimum of two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_min(float* dst, float* b);

/**
 * Returns the maximum of two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_max(float* dst, float* b);

/**
 * roundf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_round(float* dst);

/**
 * Scales a vec2 by a scalar number
 *
 * @param {vec2} out the receiving vector
 * @param {Number} b amount to scale the vector by
 */
void vec2_scale(float* dst, float b);

/**
 * Adds two vec2's after scaling the second operand by a scalar value
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 */
void vec2_scaleAndAdd(float* dst, float* b, float scale);

/**
 * Calculates the euclidian distance between two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} distance between a and b
 */
float vec2_distance(float* a, float* b);

/**
 * Calculates the squared euclidian distance between two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} squared distance between a and b
 */
float vec2_squaredDistance(float* a, float* b);

/**
 * Calculates the length of a vec2
 *
 * @param {vec2} a vector to calculate length of
 * @returns {Number} length of a
 */
float vec2_length(float* a);

/**
 * Calculates the squared length of a vec2
 *
 * @param {vec2} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
float vec2_squaredLength(float* a);

/**
 * Negates the components of a vec2
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a vector to negate
 * @returns {vec2} out
 */
void vec2_negate(float* dst);

/**
 * Returns the inverse of the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_inverse(float* dst);

/**
 * Normalize a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_normalize(float* dst);

/**
 * Calculates the dot product of two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} dot product of a and b
 */
float vec2_dot(float* a, float* b);

/**
 * Computes the cross product of two vec2's
 * Note that the cross product must by definition produce a 3D vector
 *
 * @param {vec3} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_cross(float* dst, float* b);

/**
 * Performs a linear interpolation between two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec2_lerp(float* dst, float* b, float t);

/**
 * Transforms the vec2 with a mat2
 *
 * @param {vec2} out the receiving vector
 * @param {mat2} m matrix to transform with
 */
void vec2_transformMat2(float* dst, float* m);

/**
 * Transforms the vec2 with a mat2d
 *
 * @param {vec2} out the receiving vector
 * @param {mat2d} m matrix to transform with
 */
void vec2_transformMat2d(float* dst, float* m);

/**
 * Transforms the vec2 with a mat3
 * 3rd vector component is implicitly '1'
 *
 * @param {vec2} out the receiving vector
 * @param {mat3} m matrix to transform with
 */
void vec2_transformMat3(float* dst, float* m);

/**
 * Transforms the vec2 with a mat4
 * 3rd vector component is implicitly '0'
 * 4th vector component is implicitly '1'
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a the vector to transform
 * @param {mat4} m matrix to transform with
 */
void vec2_transformMat4(float* dst, float* m);

/**
 * Rotate a 2D vector
 * @param {vec2} out The receiving vec2
 * @param {vec2} b The origin of the rotation
 * @param {Number} c The angle of rotation
 */
void vec2_rotate(float* dst, float* b, float c);

/**
 * Get the angle between two 2D vectors
 * @param {vec2} a The first operand
 * @param {vec2} b The second operand
 * @returns {Number} The angle in radians
 */
float vec2_angle(float* a, float* b);

/**
 * Returns whether or not the vectors exactly have the same elements
 *
 * @param {vec2} a The first vector.
 * @param {vec2} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
uint8_t vec2_exactEquals(float* a, float* b);

#endif
