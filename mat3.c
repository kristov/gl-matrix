#include "mat3.h"
#include <math.h>

/**
 * Copies the upper-left 3x3 values into the given mat3.
 *
 * @param {mat3} out the receiving 3x3 matrix
 * @param {mat4} a   the source 4x4 matrix
 */
void mat3_fromMat4(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = a[2];
    dst[3] = a[4];
    dst[4] = a[5];
    dst[5] = a[6];
    dst[6] = a[8];
    dst[7] = a[9];
    dst[8] = a[10];
}

/**
 * Copy the values from one mat3 to another
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} a the source matrix
 */
void mat3_copy(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = a[2];
    dst[3] = a[3];
    dst[4] = a[4];
    dst[5] = a[5];
    dst[6] = a[6];
    dst[7] = a[7];
    dst[8] = a[8];
}

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
void mat3_set(float* dst, float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
    dst[0] = m00;
    dst[1] = m01;
    dst[2] = m02;
    dst[3] = m10;
    dst[4] = m11;
    dst[5] = m12;
    dst[6] = m20;
    dst[7] = m21;
    dst[8] = m22;
}

/**
 * Set a mat3 to the identity matrix
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_identity(float* dst) {
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 1;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 1;
}

/**
 * Transpose the values of a mat3
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_transpose(float* dst) {
    // If we are transposing ourselves we can skip a few steps but have to cache some values
    float a01 = dst[1], a02 = dst[2], a12 = dst[5];
    dst[1] = dst[3];
    dst[2] = dst[6];
    dst[3] = a01;
    dst[5] = dst[7];
    dst[6] = a02;
    dst[7] = a12;
}

/**
 * Inverts a mat3
 *
 * @param {mat3} out the receiving matrix
 * @returns {mat3} out
 */
void mat3_invert(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2];
    float a10 = dst[3], a11 = dst[4], a12 = dst[5];
    float a20 = dst[6], a21 = dst[7], a22 = dst[8];

    float b01 = a22 * a11 - a12 * a21;
    float b11 = -a22 * a10 + a12 * a20;
    float b21 = a21 * a10 - a11 * a20;

    // Calculate the determinant
    float det = a00 * b01 + a01 * b11 + a02 * b21;

    if (!det) {
        return;
    }
    det = 1.0 / det;

    dst[0] = b01 * det;
    dst[1] = (-a22 * a01 + a02 * a21) * det;
    dst[2] = (a12 * a01 - a02 * a11) * det;
    dst[3] = b11 * det;
    dst[4] = (a22 * a00 - a02 * a20) * det;
    dst[5] = (-a12 * a00 + a02 * a10) * det;
    dst[6] = b21 * det;
    dst[7] = (-a21 * a00 + a01 * a20) * det;
    dst[8] = (a11 * a00 - a01 * a10) * det;
}

/**
 * Calculates the adjugate of a mat3
 *
 * @param {mat3} out the receiving matrix
 */
void mat3_adjoint(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2];
    float a10 = dst[3], a11 = dst[4], a12 = dst[5];
    float a20 = dst[6], a21 = dst[7], a22 = dst[8];

    dst[0] = (a11 * a22 - a12 * a21);
    dst[1] = (a02 * a21 - a01 * a22);
    dst[2] = (a01 * a12 - a02 * a11);
    dst[3] = (a12 * a20 - a10 * a22);
    dst[4] = (a00 * a22 - a02 * a20);
    dst[5] = (a02 * a10 - a00 * a12);
    dst[6] = (a10 * a21 - a11 * a20);
    dst[7] = (a01 * a20 - a00 * a21);
    dst[8] = (a00 * a11 - a01 * a10);
}

/**
 * Calculates the determinant of a mat3
 *
 * @param {mat3} a the source matrix
 * @returns {Number} determinant of a
 */
float mat3_determinant(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2];
    float a10 = dst[3], a11 = dst[4], a12 = dst[5];
    float a20 = dst[6], a21 = dst[7], a22 = dst[8];

    return a00 * (a22 * a11 - a12 * a21) + a01 * (-a22 * a10 + a12 * a20) + a02 * (a21 * a10 - a11 * a20);
}

/**
 * Multiplies two mat3's
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_multiply(float* dst, float* b) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2];
    float a10 = dst[3], a11 = dst[4], a12 = dst[5];
    float a20 = dst[6], a21 = dst[7], a22 = dst[8];

    float b00 = b[0], b01 = b[1], b02 = b[2];
    float b10 = b[3], b11 = b[4], b12 = b[5];
    float b20 = b[6], b21 = b[7], b22 = b[8];

    dst[0] = b00 * a00 + b01 * a10 + b02 * a20;
    dst[1] = b00 * a01 + b01 * a11 + b02 * a21;
    dst[2] = b00 * a02 + b01 * a12 + b02 * a22;

    dst[3] = b10 * a00 + b11 * a10 + b12 * a20;
    dst[4] = b10 * a01 + b11 * a11 + b12 * a21;
    dst[5] = b10 * a02 + b11 * a12 + b12 * a22;

    dst[6] = b20 * a00 + b21 * a10 + b22 * a20;
    dst[7] = b20 * a01 + b21 * a11 + b22 * a21;
    dst[8] = b20 * a02 + b21 * a12 + b22 * a22;
}

/**
 * Translate a mat3 by the given vector
 *
 * @param {mat3} out the receiving matrix
 * @param {vec2} v vector to translate by
 */
void mat3_translate(float* dst, float* v) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2],
        a10 = dst[3], a11 = dst[4], a12 = dst[5],
        a20 = dst[6], a21 = dst[7], a22 = dst[8],
        x = v[0], y = v[1];

    dst[0] = a00;
    dst[1] = a01;
    dst[2] = a02;

    dst[3] = a10;
    dst[4] = a11;
    dst[5] = a12;

    dst[6] = x * a00 + y * a10 + a20;
    dst[7] = x * a01 + y * a11 + a21;
    dst[8] = x * a02 + y * a12 + a22;
}

/**
 * Rotates a mat3 by the given angle
 *
 * @param {mat3} out the receiving matrix
 * @param {Number} rad the angle to rotate the matrix by
 */
void mat3_rotate(float* dst, float rad) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2],
        a10 = dst[3], a11 = dst[4], a12 = dst[5],
        a20 = dst[6], a21 = dst[7], a22 = dst[8],

    s = sinf(rad),
    c = cosf(rad);

    dst[0] = c * a00 + s * a10;
    dst[1] = c * a01 + s * a11;
    dst[2] = c * a02 + s * a12;

    dst[3] = c * a10 - s * a00;
    dst[4] = c * a11 - s * a01;
    dst[5] = c * a12 - s * a02;

    dst[6] = a20;
    dst[7] = a21;
    dst[8] = a22;
};

/**
 * Scales the mat3 by the dimensions in the given vec2
 *
 * @param {mat3} out the receiving matrix
 * @param {vec2} v the vec2 to scale the matrix by
 **/
void mat3_scale(float* dst, float* v) {
    float x = v[0], y = v[1];

    dst[0] = x * dst[0];
    dst[1] = x * dst[1];
    dst[2] = x * dst[2];

    dst[3] = y * dst[3];
    dst[4] = y * dst[4];
    dst[5] = y * dst[5];

    dst[6] = dst[6];
    dst[7] = dst[7];
    dst[8] = dst[8];
}

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
void mat3_fromTranslation(float* dst, float* v) {
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 1;
    dst[5] = 0;
    dst[6] = v[0];
    dst[7] = v[1];
    dst[8] = 1;
}

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
void mat3_fromRotation(float* dst, float rad) {
    float s = sinf(rad), c = cosf(rad);

    dst[0] = c;
    dst[1] = s;
    dst[2] = 0;

    dst[3] = -s;
    dst[4] = c;
    dst[5] = 0;

    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 1;
}

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
void mat3_fromScaling(float* dst, float* v) {
    dst[0] = v[0];
    dst[1] = 0;
    dst[2] = 0;

    dst[3] = 0;
    dst[4] = v[1];
    dst[5] = 0;

    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 1;
}

/**
 * Copies the values from a mat2d into a mat3
 *
 * @param {mat3} out the receiving matrix
 * @param {mat2d} a the matrix to copy
 **/
void mat3_fromMat2d(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = 0;

    dst[3] = a[2];
    dst[4] = a[3];
    dst[5] = 0;

    dst[6] = a[4];
    dst[7] = a[5];
    dst[8] = 1;
}

/**
* Calculates a 3x3 matrix from the given quaternion
*
* @param {mat3} out mat3 receiving operation result
* @param {quat} q Quaternion to create matrix from
*/
void mat3_fromQuat(float* dst, float* q) {
    float x = q[0], y = q[1], z = q[2], w = q[3];
    float x2 = x + x;
    float y2 = y + y;
    float z2 = z + z;

    float xx = x * x2;
    float yx = y * x2;
    float yy = y * y2;
    float zx = z * x2;
    float zy = z * y2;
    float zz = z * z2;
    float wx = w * x2;
    float wy = w * y2;
    float wz = w * z2;

    dst[0] = 1 - yy - zz;
    dst[3] = yx - wz;
    dst[6] = zx + wy;

    dst[1] = yx + wz;
    dst[4] = 1 - xx - zz;
    dst[7] = zy - wx;

    dst[2] = zx - wy;
    dst[5] = zy + wx;
    dst[8] = 1 - xx - yy;
}

/**
* Calculates a 3x3 normal matrix (transpose inverse) from the 4x4 matrix
*
* @param {mat3} out mat3 receiving operation result
* @param {mat4} a Mat4 to derive the normal matrix from
*/
void mat3_normalFromMat4(float* dst, float* a) {
    float a00 = a[0], a01 = a[1], a02 = a[2], a03 = a[3];
    float a10 = a[4], a11 = a[5], a12 = a[6], a13 = a[7];
    float a20 = a[8], a21 = a[9], a22 = a[10], a23 = a[11];
    float a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

    float b00 = a00 * a11 - a01 * a10;
    float b01 = a00 * a12 - a02 * a10;
    float b02 = a00 * a13 - a03 * a10;
    float b03 = a01 * a12 - a02 * a11;
    float b04 = a01 * a13 - a03 * a11;
    float b05 = a02 * a13 - a03 * a12;
    float b06 = a20 * a31 - a21 * a30;
    float b07 = a20 * a32 - a22 * a30;
    float b08 = a20 * a33 - a23 * a30;
    float b09 = a21 * a32 - a22 * a31;
    float b10 = a21 * a33 - a23 * a31;
    float b11 = a22 * a33 - a23 * a32;

    // Calculate the determinant
    float det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

    if (!det) {
        return;
    }
    det = 1.0 / det;

    dst[0] = (a11 * b11 - a12 * b10 + a13 * b09) * det;
    dst[1] = (a12 * b08 - a10 * b11 - a13 * b07) * det;
    dst[2] = (a10 * b10 - a11 * b08 + a13 * b06) * det;

    dst[3] = (a02 * b10 - a01 * b11 - a03 * b09) * det;
    dst[4] = (a00 * b11 - a02 * b08 + a03 * b07) * det;
    dst[5] = (a01 * b08 - a00 * b10 - a03 * b06) * det;

    dst[6] = (a31 * b05 - a32 * b04 + a33 * b03) * det;
    dst[7] = (a32 * b02 - a30 * b05 - a33 * b01) * det;
    dst[8] = (a30 * b04 - a31 * b02 + a33 * b00) * det;
}

/**
 * Generates a 2D projection matrix with the given bounds
 *
 * @param {mat3} out mat3 frustum matrix will be written into
 * @param {number} width Width of your gl context
 * @param {number} height Height of gl context
 */
void mat3_projection(float* dst, float width, float height) {
    dst[0] = 2 / width;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = -2 / height;
    dst[5] = 0;
    dst[6] = -1;
    dst[7] = 1;
    dst[8] = 1;
}

/**
 * Returns Frobenius norm of a mat3
 *
 * @param {mat3} a the matrix to calculate Frobenius norm of
 * @returns {Number} Frobenius norm
 */
float mat3_frob(float* a) {
  return (sqrtf(powf(a[0], 2) + powf(a[1], 2) + powf(a[2], 2) + powf(a[3], 2) + powf(a[4], 2) + powf(a[5], 2) + powf(a[6], 2) + powf(a[7], 2) + powf(a[8], 2)));
}

/**
 * Adds two mat3's
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_add(float* dst, float* b) {
    dst[0] = dst[0] + b[0];
    dst[1] = dst[1] + b[1];
    dst[2] = dst[2] + b[2];
    dst[3] = dst[3] + b[3];
    dst[4] = dst[4] + b[4];
    dst[5] = dst[5] + b[5];
    dst[6] = dst[6] + b[6];
    dst[7] = dst[7] + b[7];
    dst[8] = dst[8] + b[8];
}

/**
 * Subtracts matrix b from matrix a
 *
 * @param {mat3} out the receiving matrix
 * @param {mat3} b the second operand
 */
void mat3_subtract(float* dst, float* b) {
    dst[0] = dst[0] - b[0];
    dst[1] = dst[1] - b[1];
    dst[2] = dst[2] - b[2];
    dst[3] = dst[3] - b[3];
    dst[4] = dst[4] - b[4];
    dst[5] = dst[5] - b[5];
    dst[6] = dst[6] - b[6];
    dst[7] = dst[7] - b[7];
    dst[8] = dst[8] - b[8];
}

/**
 * Multiply each element of the matrix by a scalar.
 *
 * @param {mat3} out the receiving matrix
 * @param {Number} b amount to scale the matrix's elements by
 */
void mat3_multiplyScalar(float* dst, float b) {
    dst[0] = dst[0] * b;
    dst[1] = dst[1] * b;
    dst[2] = dst[2] * b;
    dst[3] = dst[3] * b;
    dst[4] = dst[4] * b;
    dst[5] = dst[5] * b;
    dst[6] = dst[6] * b;
    dst[7] = dst[7] * b;
    dst[8] = dst[8] * b;
}

/**
 * Adds two mat3's after multiplying each element of the second operand by a scalar value.
 *
 * @param {mat3} out the receiving vector
 * @param {mat3} b the second operand
 * @param {Number} scale the amount to scale b's elements by before adding
 */
void mat3_multiplyScalarAndAdd(float* dst, float* b, float scale) {
    dst[0] = dst[0] + (b[0] * scale);
    dst[1] = dst[1] + (b[1] * scale);
    dst[2] = dst[2] + (b[2] * scale);
    dst[3] = dst[3] + (b[3] * scale);
    dst[4] = dst[4] + (b[4] * scale);
    dst[5] = dst[5] + (b[5] * scale);
    dst[6] = dst[6] + (b[6] * scale);
    dst[7] = dst[7] + (b[7] * scale);
    dst[8] = dst[8] + (b[8] * scale);
}

/**
 * Returns whether or not the matrices have exactly the same elements in the same position (when compared with ===)
 *
 * @param {mat3} a The first matrix.
 * @param {mat3} b The second matrix.
 * @returns {uint8_t} 1 if the matrices are equal, 0 otherwise.
 */
uint8_t mat3_equals(float* a, float* b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] &&
        a[3] == b[3] && a[4] == b[4] && a[5] == b[5] &&
        a[6] == b[6] && a[7] == b[7] && a[8] == b[8];
}
