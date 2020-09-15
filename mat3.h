#ifndef MAT3_H
#define MAT3_H

#include <stdint.h>

/**
 * Copies the upper-left 3x3 values into the given mat3.
 *
 * @param {mat3} out the receiving 3x3 matrix
 * @param {mat4} a   the source 4x4 matrix
 */
void mat3_fromMat4(float* dst, float* a);

/**
 * Copy the values from one mat3 to another
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} a the source matrix
 */
void mat3_copy(float* dst, float* a);

/**
 * Set the components of a mat3 to the given values
 *
 * @param {mat3} out the receiving matrix
 * @param {Number} m00 Component in column 0, row 0 position (index 0)
 * @param {Number} m01 Component in column 0, row 1 position (index 1)
 * @param {Number} m02 Component in column 0, row 2 position (index 2)
 * @param {Number} m10 Component in column 1, row 0 position (index 3)
 * @param {Number} m11 Component in column 1, row 1 position (index 4)
 * @param {Number} m12 Component in column 1, row 2 position (index 5)
 * @param {Number} m20 Component in column 2, row 0 position (index 6)
 * @param {Number} m21 Component in column 2, row 1 position (index 7)
 * @param {Number} m22 Component in column 2, row 2 position (index 8)
 */
void mat3_set(float* dst, float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);

/**
 * Set a mat3 to the identity matrix
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_identity(float* dst);

/**
 * Transpose the values of a mat3
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_transpose(float* dst);

/**
 * Inverts a mat3
 *
 * @param {mat3} out the receiving matrix
 * @returns {mat3} out
 */
void mat3_invert(float* dst);

/**
 * Calculates the adjugate of a mat3
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_adjoint(float* dst);

/**
 * Calculates the determinant of a mat3
 *
 * @param {mat3} a the source matrix
 * @returns {Number} determinant of a
 */
float mat3_determinant(float* dst);

/**
 * Multiplies two mat3's
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_multiply(float* dst, float* b);

/**
 * Translate a mat3 by the given vector
 *
 * @param {mat3} out the receiving matrix
 * @param {vec2} v vector to translate by
 */
void mat3_translate(float* dst, float* v);

/**
 * Rotates a mat3 by the given angle
 *
 * @param {mat3} out the receiving matrix
 * @param {Number} rad the angle to rotate the matrix by
 */
void mat3_rotate(float* dst, float rad);

/**
 * Scales the mat3 by the dimensions in the given vec2
 *
 * @param {mat3} out the receiving matrix
 * @param {vec2} v the vec2 to scale the matrix by
 **/
void mat3_scale(float* dst, float* v);

/**
 * Creates a matrix from a vector translation
 * This is equivalent to (but much faster than):
 *
 *     mat3_identity(dest);
 *     mat3_translate(dest, vec);
 *
 * @param {mat3} out mat3 receiving operation result
 * @param {vec2} v Translation vector
 */
void mat3_fromTranslation(float* dst, float* v);

/**
 * Creates a matrix from a given angle
 * This is equivalent to (but much faster than):
 *
 *     mat3_identity(dest);
 *     mat3_rotate(dest, dest, rad);
 *
 * @param {mat3} out mat3 receiving operation result
 * @param {Number} rad the angle to rotate the matrix by
 * @returns {mat3} out
 */
void mat3_fromRotation(float* dst, float rad);

/**
 * Creates a matrix from a vector scaling
 * This is equivalent to (but much faster than):
 *
 *     mat3_identity(dest);
 *     mat3_scale(dest, vec);
 *
 * @param {mat3} out mat3 receiving operation result
 * @param {vec2} v Scaling vector
 */
void mat3_fromScaling(float* dst, float* v);

/**
 * Copies the values from a mat2d into a mat3
 *
 * @param {mat3} out the receiving matrix
 * @param {mat2d} a the matrix to copy
 **/
void mat3_fromMat2d(float* dst, float* a);

/**
* Calculates a 3x3 matrix from the given quaternion
*
* @param {mat3} out mat3 receiving operation result
* @param {quat} q Quaternion to create matrix from
*/
void mat3_fromQuat(float* dst, float* q);

/**
* Calculates a 3x3 normal matrix (transpose inverse) from the 4x4 matrix
*
* @param {mat3} out mat3 receiving operation result
* @param {mat4} a Mat4 to derive the normal matrix from
*/
void mat3_normalFromMat4(float* dst, float* a);

/**
 * Generates a 2D projection matrix with the given bounds
 *
 * @param {mat3} out mat3 frustum matrix will be written into
 * @param {number} width Width of your gl context
 * @param {number} height Height of gl context
 */
void mat3_projection(float* dst, float width, float height);

/**
 * Returns Frobenius norm of a mat3
 *
 * @param {mat3} a the matrix to calculate Frobenius norm of
 * @returns {Number} Frobenius norm
 */
float mat3_frob(float* a);

/**
 * Adds two mat3's
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_add(float* dst, float* b);

/**
 * Subtracts matrix b from matrix a
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_subtract(float* dst, float* b);

/**
 * Multiply each element of the matrix by a scalar.
 *
 * @param {mat3} out the receiving matrix
 * @param {Number} b amount to scale the matrix's elements by
 */
void mat3_multiplyScalar(float* dst, float b);

/**
 * Adds two mat3's after multiplying each element of the second operand by a scalar value.
 *
 * @param {mat3} out the receiving vector
 * @param {mat3} b the second operand
 * @param {Number} scale the amount to scale b's elements by before adding
 */
void mat3_multiplyScalarAndAdd(float* dst, float* b, float scale);

/**
 * Returns whether or not the matrices have exactly the same elements.
 *
 * @param {mat3} a The first matrix.
 * @param {mat3} b The second matrix.
 * @returns {uint8_t} 1 if the matrices are equal, 0 otherwise.
 */
uint8_t mat3_equals(float* a, float* b);

#endif
