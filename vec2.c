#include "vec2.h"
#include <math.h>

/**
 * Copy the values from one vec2 to another
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a the source vector
 */
void vec2_copy(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
}

/**
 * Set the components of a vec2 to the given values
 *
 * @param {vec2} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 */
void vec2_set(float* dst, float x, float y) {
    dst[0] = x;
    dst[1] = y;
}

/**
 * Adds two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_add(float* dst, float* b) {
    dst[0] = dst[0] + b[0];
    dst[1] = dst[1] + b[1];
}

/**
 * Subtracts vector b from vector a
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_subtract(float* dst, float* b) {
    dst[0] = dst[0] - b[0];
    dst[1] = dst[1] - b[1];
}

/**
 * Multiplies two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_multiply(float* dst, float* b) {
    dst[0] = dst[0] * b[0];
    dst[1] = dst[1] * b[1];
}

/**
 * Divides two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_divide(float* dst, float* b) {
    dst[0] = dst[0] / b[0];
    dst[1] = dst[1] / b[1];
}

/**
 * ceilf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_ceil(float* dst) {
    dst[0] = ceilf(dst[0]);
    dst[1] = ceilf(dst[1]);
}

/**
 * floorf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_floor(float* dst) {
    dst[0] = floorf(dst[0]);
    dst[1] = floorf(dst[1]);
}

/**
 * Returns the minimum of two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_min(float* dst, float* b) {
    dst[0] = fmin(dst[0], b[0]);
    dst[1] = fmin(dst[1], b[1]);
}

/**
 * Returns the maximum of two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_max(float* dst, float* b) {
    dst[0] = fmax(dst[0], b[0]);
    dst[1] = fmax(dst[1], b[1]);
}

/**
 * roundf the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_round(float* dst) {
    dst[0] = roundf(dst[0]);
    dst[1] = roundf(dst[1]);
}

/**
 * Scales a vec2 by a scalar number
 *
 * @param {vec2} out the receiving vector
 * @param {Number} b amount to scale the vector by
 */
void vec2_scale(float* dst, float b) {
    dst[0] = dst[0] * b;
    dst[1] = dst[1] * b;
}

/**
 * Adds two vec2's after scaling the second operand by a scalar value
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 */
void vec2_scaleAndAdd(float* dst, float* b, float scale) {
    dst[0] = dst[0] + (b[0] * scale);
    dst[1] = dst[1] + (b[1] * scale);
}

/**
 * Calculates the euclidian distance between two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} distance between a and b
 */
float vec2_distance(float* a, float* b) {
    float x = b[0] - a[0], y = b[1] - a[1];
    return sqrtf(x*x + y*y);
}

/**
 * Calculates the squared euclidian distance between two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} squared distance between a and b
 */
float vec2_squaredDistance(float* a, float* b) {
    float x = b[0] - a[0], y = b[1] - a[1];
    return x*x + y*y;
}

/**
 * Calculates the length of a vec2
 *
 * @param {vec2} a vector to calculate length of
 * @returns {Number} length of a
 */
float vec2_length(float* a) {
    float x = a[0], y = a[1];
    return sqrtf(x*x + y*y);
}

/**
 * Calculates the squared length of a vec2
 *
 * @param {vec2} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
float vec2_squaredLength(float* a) {
    float x = a[0], y = a[1];
    return x*x + y*y;
}

/**
 * Negates the components of a vec2
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a vector to negate
 * @returns {vec2} out
 */
void vec2_negate(float* dst) {
    dst[0] = -dst[0];
    dst[1] = -dst[1];
}

/**
 * Returns the inverse of the components of a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_inverse(float* dst) {
    dst[0] = 1.0 / dst[0];
    dst[1] = 1.0 / dst[1];
}

/**
 * Normalize a vec2
 *
 * @param {vec2} out the receiving vector
 */
void vec2_normalize(float* dst) {
    float x = dst[0], y = dst[1];
    float len = x*x + y*y;
    if (len > 0) {
        len = 1 / sqrtf(len);
        dst[0] = dst[0] * len;
        dst[1] = dst[1] * len;
    }
}

/**
 * Calculates the dot product of two vec2's
 *
 * @param {vec2} a the first operand
 * @param {vec2} b the second operand
 * @returns {Number} dot product of a and b
 */
float vec2_dot(float* a, float* b) {
    return a[0] * b[0] + a[1] * b[1];
}

/**
 * Computes the cross product of two vec2's
 * Note that the cross product must by definition produce a 3D vector
 *
 * @param {vec3} out the receiving vector
 * @param {vec2} b the second operand
 */
void vec2_cross(float* dst, float* b) {
    float z = dst[0] * b[1] - dst[1] * b[0];
    dst[0] = dst[1] = 0;
    dst[2] = z;
}

/**
 * Performs a linear interpolation between two vec2's
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} b the second operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec2_lerp(float* dst, float* b, float t) {
    float ax = dst[0], ay = dst[1];
    dst[0] = ax + t * (b[0] - ax);
    dst[1] = ay + t * (b[1] - ay);
}

/**
 * Transforms the vec2 with a mat2
 *
 * @param {vec2} out the receiving vector
 * @param {mat2} m matrix to transform with
 */
void vec2_transformMat2(float* dst, float* m) {
    float x = dst[0], y = dst[1];
    dst[0] = m[0] * x + m[2] * y;
    dst[1] = m[1] * x + m[3] * y;
}

/**
 * Transforms the vec2 with a mat2d
 *
 * @param {vec2} out the receiving vector
 * @param {mat2d} m matrix to transform with
 */
void vec2_transformMat2d(float* dst, float* m) {
    float x = dst[0], y = dst[1];
    dst[0] = m[0] * x + m[2] * y + m[4];
    dst[1] = m[1] * x + m[3] * y + m[5];
}

/**
 * Transforms the vec2 with a mat3
 * 3rd vector component is implicitly '1'
 *
 * @param {vec2} out the receiving vector
 * @param {mat3} m matrix to transform with
 */
void vec2_transformMat3(float* dst, float* m) {
    float x = dst[0], y = dst[1];
    dst[0] = m[0] * x + m[3] * y + m[6];
    dst[1] = m[1] * x + m[4] * y + m[7];
}

/**
 * Transforms the vec2 with a mat4
 * 3rd vector component is implicitly '0'
 * 4th vector component is implicitly '1'
 *
 * @param {vec2} out the receiving vector
 * @param {vec2} a the vector to transform
 * @param {mat4} m matrix to transform with
 */
void vec2_transformMat4(float* dst, float* m) {
    float x = dst[0];
    float y = dst[1];
    dst[0] = m[0] * x + m[4] * y + m[12];
    dst[1] = m[1] * x + m[5] * y + m[13];
}

/**
 * Rotate a 2D vector
 * @param {vec2} out The receiving vec2
 * @param {vec2} b The origin of the rotation
 * @param {Number} c The angle of rotation
 */
void vec2_rotate(float* dst, float* b, float c) {
    //Translate point to the origin
    float p0 = dst[0] - b[0],
    p1 = dst[1] - b[1],
    sinC = sinf(c),
    cosC = cosf(c);

    //perform rotation and translate to correct position
    dst[0] = p0*cosC - p1*sinC + b[0];
    dst[1] = p0*sinC + p1*cosC + b[1];
}

/**
 * Get the angle between two 2D vectors
 * @param {vec2} a The first operand
 * @param {vec2} b The second operand
 * @returns {Number} The angle in radians
 */
float vec2_angle(float* a, float* b) {
    float x1 = a[0],
        y1 = a[1],
        x2 = b[0],
        y2 = b[1];

    float len1 = x1*x1 + y1*y1;
    if (len1 > 0) {
        len1 = 1 / sqrtf(len1);
    }

    float len2 = x2*x2 + y2*y2;
    if (len2 > 0) {
        //TODO: evaluate use of glm_invsqrt here?
        len2 = 1 / sqrtf(len2);
    }

    float cosine = (x1 * x2 + y1 * y2) * len1 * len2;

    if(cosine > 1.0) {
        return 0;
    }
    else if(cosine < -1.0) {
        return M_PI;
    }
    else {
        return acosf(cosine);
    }
}

/**
 * Returns whether or not the vectors exactly have the same elements
 *
 * @param {vec2} a The first vector.
 * @param {vec2} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
uint8_t vec2_exactEquals(float* a, float* b) {
    return a[0] == b[0] && a[1] == b[1];
}
