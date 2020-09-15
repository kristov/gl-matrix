#include "vec4.h"
#include <math.h>

/**
 * Copy the values from one vec4 to another
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the source vector
 */
void vec4_copy(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = a[2];
    dst[3] = a[3];
}

/**
 * Set the components of a vec4 to the given values
 *
 * @param {vec4} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 * @param {Number} w W component
 */
void vec4_set(float* dst, float x, float y, float z, float w) {
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
    dst[3] = w;
}

/**
 * Adds two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_add(float* dst, float* b) {
    dst[0] = dst[0] + b[0];
    dst[1] = dst[1] + b[1];
    dst[2] = dst[2] + b[2];
    dst[3] = dst[3] + b[3];
}

/**
 * Subtracts vector b from vector a
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_subtract(float* dst, float* b) {
    dst[0] = dst[0] - b[0];
    dst[1] = dst[1] - b[1];
    dst[2] = dst[2] - b[2];
    dst[3] = dst[3] - b[3];
}

/**
 * Multiplies two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_multiply(float* dst, float* b) {
    dst[0] = dst[0] * b[0];
    dst[1] = dst[1] * b[1];
    dst[2] = dst[2] * b[2];
    dst[3] = dst[3] * b[3];
}

/**
 * Divides two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_divide(float* dst, float* b) {
    dst[0] = dst[0] / b[0];
    dst[1] = dst[1] / b[1];
    dst[2] = dst[2] / b[2];
    dst[3] = dst[3] / b[3];
}

/**
 * ceilf the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to ceil
 */
void vec4_ceil(float* dst) {
    dst[0] = ceilf(dst[0]);
    dst[1] = ceilf(dst[1]);
    dst[2] = ceilf(dst[2]);
    dst[3] = ceilf(dst[3]);
}

/**
 * floorf the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to floor
 */
void vec4_floor(float* dst) {
    dst[0] = floorf(dst[0]);
    dst[1] = floorf(dst[1]);
    dst[2] = floorf(dst[2]);
    dst[3] = floorf(dst[3]);
}

/**
 * Returns the minimum of two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_min(float* dst, float* b) {
    dst[0] = fmin(dst[0], b[0]);
    dst[1] = fmin(dst[1], b[1]);
    dst[2] = fmin(dst[2], b[2]);
    dst[3] = fmin(dst[3], b[3]);
}

/**
 * Returns the maximum of two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 */
void vec4_max(float* dst, float* b) {
    dst[0] = fmax(dst[0], b[0]);
    dst[1] = fmax(dst[1], b[1]);
    dst[2] = fmax(dst[2], b[2]);
    dst[3] = fmax(dst[3], b[3]);
}

/**
 * roundf the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to round
 */
void vec4_round(float* dst) {
    dst[0] = roundf(dst[0]);
    dst[1] = roundf(dst[1]);
    dst[2] = roundf(dst[2]);
    dst[3] = roundf(dst[3]);
}

/**
 * Scales a vec4 by a scalar number
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the vector to scale
 * @param {Number} b amount to scale the vector by
 */
void vec4_scale(float* dst, float b) {
    dst[0] = dst[0] * b;
    dst[1] = dst[1] * b;
    dst[2] = dst[2] * b;
    dst[3] = dst[3] * b;
}

/**
 * Adds two vec4's after scaling the second operand by a scalar value
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 */
void vec4_scaleAndAdd(float* dst, float* b, float scale) {
    dst[0] = dst[0] + (b[0] * scale);
    dst[1] = dst[1] + (b[1] * scale);
    dst[2] = dst[2] + (b[2] * scale);
    dst[3] = dst[3] + (b[3] * scale);
}

/**
 * Calculates the euclidian distance between two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} distance between a and b
 */
float vec4_distance(float* a, float* b) {
    float x = b[0] - a[0];
    float y = b[1] - a[1];
    float z = b[2] - a[2];
    float w = b[3] - a[3];
    return sqrtf(x*x + y*y + z*z + w*w);
}

/**
 * Calculates the squared euclidian distance between two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} squared distance between a and b
 */
float vec4_squaredDistance(float* a, float* b) {
    float x = b[0] - a[0];
    float y = b[1] - a[1];
    float z = b[2] - a[2];
    float w = b[3] - a[3];
    return x*x + y*y + z*z + w*w;
}

/**
 * Calculates the length of a vec4
 *
 * @param {vec4} a vector to calculate length of
 * @returns {Number} length of a
 */
float vec4_length(float* a) {
    float x = a[0];
    float y = a[1];
    float z = a[2];
    float w = a[3];
    return sqrtf(x*x + y*y + z*z + w*w);
}

/**
 * Calculates the squared length of a vec4
 *
 * @param {vec4} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
float vec4_squaredLength(float* a) {
    float x = a[0];
    float y = a[1];
    float z = a[2];
    float w = a[3];
    return x*x + y*y + z*z + w*w;
}

/**
 * Negates the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to negate
 */
void vec4_negate(float* dst) {
    dst[0] = -dst[0];
    dst[1] = -dst[1];
    dst[2] = -dst[2];
    dst[3] = -dst[3];
}

/**
 * Returns the inverse of the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to invert
 */
void vec4_inverse(float* dst) {
    dst[0] = 1.0 / dst[0];
    dst[1] = 1.0 / dst[1];
    dst[2] = 1.0 / dst[2];
    dst[3] = 1.0 / dst[3];
}

/**
 * Normalize a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to normalize
 */
void vec4_normalize(float* dst) {
    float x = dst[0];
    float y = dst[1];
    float z = dst[2];
    float w = dst[3];
    float len = x*x + y*y + z*z + w*w;
    if (len > 0) {
        len = 1 / sqrtf(len);
        dst[0] = x * len;
        dst[1] = y * len;
        dst[2] = z * len;
        dst[3] = w * len;
    }
}

/**
 * Calculates the dot product of two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} dot product of a and b
 */
float vec4_dot(float* a, float* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

/**
 * Performs a linear interpolation between two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} b the second operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec4_lerp(float* dst, float* b, float t) {
    float ax = dst[0];
    float ay = dst[1];
    float az = dst[2];
    float aw = dst[3];
    dst[0] = ax + t * (b[0] - ax);
    dst[1] = ay + t * (b[1] - ay);
    dst[2] = az + t * (b[2] - az);
    dst[3] = aw + t * (b[3] - aw);
}

/**
 * Transforms the vec4 with a mat4.
 *
 * @param {vec4} out the receiving vector
 * @param {mat4} m matrix to transform with
 */
void vec4_transformMat4(float* dst, float* m) {
    float x = dst[0], y = dst[1], z = dst[2], w = dst[3];
    dst[0] = m[0] * x + m[4] * y + m[8] * z + m[12] * w;
    dst[1] = m[1] * x + m[5] * y + m[9] * z + m[13] * w;
    dst[2] = m[2] * x + m[6] * y + m[10] * z + m[14] * w;
    dst[3] = m[3] * x + m[7] * y + m[11] * z + m[15] * w;
}

/**
 * Transforms the vec4 with a quat
 *
 * @param {vec4} out the receiving vector
 * @param {quat} q quaternion to transform with
 */
void vec4_transformQuat(float* dst, float* q) {
    float x = dst[0], y = dst[1], z = dst[2];
    float qx = q[0], qy = q[1], qz = q[2], qw = q[3];

    // calculate quat * vec
    float ix = qw * x + qy * z - qz * y;
    float iy = qw * y + qz * x - qx * z;
    float iz = qw * z + qx * y - qy * x;
    float iw = -qx * x - qy * y - qz * z;

    // calculate result * inverse quat
    dst[0] = ix * qw + iw * -qx + iy * -qz - iz * -qy;
    dst[1] = iy * qw + iw * -qy + iz * -qx - ix * -qz;
    dst[2] = iz * qw + iw * -qz + ix * -qy - iy * -qx;
    dst[3] = dst[3];
}

/**
 * Returns whether or not the vectors have exactly the same elements
 *
 * @param {vec4} a The first vector.
 * @param {vec4} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
uint8_t vec4_equals(float* a, float* b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}
