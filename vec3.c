#include "vec3.h"
#include <math.h>

/**
 * Calculates the length of a vec3
 *
 * @param {vec3} a vector to calculate length of
 * @returns {Number} length of a
 */
float vec3_length(float* a) {
    float x = a[0];
    float y = a[1];
    float z = a[2];
    return sqrtf(x*x + y*y + z*z);
}

/**
 * Copy the values from one vec3 to another
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the source vector
 */
void vec3_copy(float* dst, float* a) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = a[2];
}

/**
 * Set the components of a vec3 to the given values
 *
 * @param {vec3} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 */
void vec3_set(float* dst, float x, float y, float z) {
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

/**
 * Adds two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_add(float* dst, float* b) {
    dst[0] = dst[0] + b[0];
    dst[1] = dst[1] + b[1];
    dst[2] = dst[2] + b[2];
}

/**
 * Subtracts vector b from vector a
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_subtract(float* dst, float* b) {
    dst[0] = dst[0] - b[0];
    dst[1] = dst[1] - b[1];
    dst[2] = dst[2] - b[2];
}

/**
 * Multiplies two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_multiply(float* dst, float* b) {
    dst[0] = dst[0] * b[0];
    dst[1] = dst[1] * b[1];
    dst[2] = dst[2] * b[2];
}

/**
 * Divides two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_divide(float* dst, float* b) {
    dst[0] = dst[0] / b[0];
    dst[1] = dst[1] / b[1];
    dst[2] = dst[2] / b[2];
}

/**
 * Math.ceil the components of a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_ceil(float* dst) {
    dst[0] = ceilf(dst[0]);
    dst[1] = ceilf(dst[1]);
    dst[2] = ceilf(dst[2]);
}

/**
 * Math.floor the components of a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_floor(float* dst) {
    dst[0] = floorf(dst[0]);
    dst[1] = floorf(dst[1]);
    dst[2] = floorf(dst[2]);
}

/**
 * Returns the minimum of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_min(float* dst, float* b) {
    dst[0] = fmin(dst[0], b[0]);
    dst[1] = fmin(dst[1], b[1]);
    dst[2] = fmin(dst[2], b[2]);
}

/**
 * Returns the maximum of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_max(float* dst, float* b) {
    dst[0] = fmax(dst[0], b[0]);
    dst[1] = fmax(dst[1], b[1]);
    dst[2] = fmax(dst[2], b[2]);
}

/**
 * Math.round the components of a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_round(float* dst) {
    dst[0] = roundf(dst[0]);
    dst[1] = roundf(dst[1]);
    dst[2] = roundf(dst[2]);
}

/**
 * Scales a vec3 by a scalar number
 *
 * @param {vec3} out the receiving vector
 * @param {Number} b amount to scale the vector by
 */
void vec3_scale(float* dst, float b) {
    dst[0] = dst[0] * b;
    dst[1] = dst[1] * b;
    dst[2] = dst[2] * b;
}

/**
 * Adds two vec3's after scaling the second operand by a scalar value
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 */
void vec3_scaleAndAdd(float* dst, float* b, float scale) {
    dst[0] = dst[0] + (b[0] * scale);
    dst[1] = dst[1] + (b[1] * scale);
    dst[2] = dst[2] + (b[2] * scale);
}

/**
 * Calculates the euclidian distance between two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} distance between a and b
 */
float vec3_distance(float* a, float* b) {
    float x = b[0] - a[0];
    float y = b[1] - a[1];
    float z = b[2] - a[2];
    return sqrtf(x*x + y*y + z*z);
}

/**
 * Calculates the squared euclidian distance between two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} squared distance between a and b
 */
float vec3_squaredDistance(float* a, float* b) {
    float x = b[0] - a[0];
    float y = b[1] - a[1];
    float z = b[2] - a[2];
    return x*x + y*y + z*z;
}

/**
 * Calculates the squared length of a vec3
 *
 * @param {vec3} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
float vec3_squaredLength(float* a) {
    float x = a[0];
    float y = a[1];
    float z = a[2];
    return x*x + y*y + z*z;
}

/**
 * Negates the components of a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_negate(float* dst) {
    dst[0] = -dst[0];
    dst[1] = -dst[1];
    dst[2] = -dst[2];
}

/**
 * Returns the inverse of the components of a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_inverse(float* dst) {
    dst[0] = 1.0 / dst[0];
    dst[1] = 1.0 / dst[1];
    dst[2] = 1.0 / dst[2];
}

/**
 * Normalize a vec3
 *
 * @param {vec3} out the receiving vector
 */
void vec3_normalize(float* dst) {
    float x = dst[0];
    float y = dst[1];
    float z = dst[2];
    float len = x*x + y*y + z*z;
    if (len > 0) {
        len = 1 / sqrtf(len);
        dst[0] = dst[0] * len;
        dst[1] = dst[1] * len;
        dst[2] = dst[2] * len;
    }
}

/**
 * Calculates the dot product of two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} dot product of a and b
 */
float vec3_dot(float* a, float* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/**
 * Computes the cross product of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 */
void vec3_cross(float* dst, float* b) {
    float ax = dst[0], ay = dst[1], az = dst[2];
    float bx = b[0], by = b[1], bz = b[2];

    dst[0] = ay * bz - az * by;
    dst[1] = az * bx - ax * bz;
    dst[2] = ax * by - ay * bx;
}

/**
 * Performs a linear interpolation between two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec3_lerp(float* dst, float* b, float t) {
    float ax = dst[0];
    float ay = dst[1];
    float az = dst[2];
    dst[0] = ax + t * (b[0] - ax);
    dst[1] = ay + t * (b[1] - ay);
    dst[2] = az + t * (b[2] - az);
}

/**
 * Performs a hermite interpolation with two control points
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 * @param {vec3} c the third operand
 * @param {vec3} d the fourth operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec3_hermite(float* dst, float* b, float* c, float* d, float t) {
    float factorTimes2 = t * t;
    float factor1 = factorTimes2 * (2 * t - 3) + 1;
    float factor2 = factorTimes2 * (t - 2) + t;
    float factor3 = factorTimes2 * (t - 1);
    float factor4 = factorTimes2 * (3 - 2 * t);

    dst[0] = dst[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
    dst[1] = dst[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
    dst[2] = dst[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
}

/**
 * Performs a bezier interpolation with two control points
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} b the second operand
 * @param {vec3} c the third operand
 * @param {vec3} d the fourth operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void vec3_bezier(float* dst, float* b, float* c, float* d, float t) {
    float inverseFactor = 1 - t;
    float inverseFactorTimesTwo = inverseFactor * inverseFactor;
    float factorTimes2 = t * t;
    float factor1 = inverseFactorTimesTwo * inverseFactor;
    float factor2 = 3 * t * inverseFactorTimesTwo;
    float factor3 = 3 * factorTimes2 * inverseFactor;
    float factor4 = factorTimes2 * t;

    dst[0] = dst[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
    dst[1] = dst[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
    dst[2] = dst[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
}

/**
 * Transforms the vec3 with a mat4.
 * 4th vector component is implicitly '1'
 *
 * @param {vec3} out the receiving vector
 * @param {mat4} m matrix to transform with
 */
void vec3_transformMat4(float* dst, float* m) {
    float x = dst[0], y = dst[1], z = dst[2];
    float w = m[3] * x + m[7] * y + m[11] * z + m[15];
    w = w || 1.0;
    dst[0] = (m[0] * x + m[4] * y + m[8] * z + m[12]) / w;
    dst[1] = (m[1] * x + m[5] * y + m[9] * z + m[13]) / w;
    dst[2] = (m[2] * x + m[6] * y + m[10] * z + m[14]) / w;
}

/**
 * Transforms the vec3 with a mat3.
 *
 * @param {vec3} out the receiving vector
 * @param {mat3} m the 3x3 matrix to transform with
 */
void vec3_transformMat3(float* dst, float* m) {
    float x = dst[0], y = dst[1], z = dst[2];
    dst[0] = x * m[0] + y * m[3] + z * m[6];
    dst[1] = x * m[1] + y * m[4] + z * m[7];
    dst[2] = x * m[2] + y * m[5] + z * m[8];
}

/**
 * Transforms the vec3 with a quat
 * Can also be used for dual quaternions. (Multiply it with the real part)
 *
 * @param {vec3} out the receiving vector
 * @param {quat} q quaternion to transform with
 */
void vec3_transformQuat(float* dst, float* q) {
    // benchmarks: https://jsperf.com/quaternion-transform-vec3-implementations-fixed
    float qx = q[0], qy = q[1], qz = q[2], qw = q[3];
    float x = dst[0], y = dst[1], z = dst[2];
    // var qvec = [qx, qy, qz];
    // var uv = vec3.cross([], qvec, a);
    float uvx = qy * z - qz * y,
        uvy = qz * x - qx * z,
        uvz = qx * y - qy * x;
    // var uuv = vec3.cross([], qvec, uv);
    float uuvx = qy * uvz - qz * uvy,
        uuvy = qz * uvx - qx * uvz,
        uuvz = qx * uvy - qy * uvx;
    // vec3.scale(uv, uv, 2 * w);
    float w2 = qw * 2;
    uvx *= w2;
    uvy *= w2;
    uvz *= w2;
    // vec3.scale(uuv, uuv, 2);
    uuvx *= 2;
    uuvy *= 2;
    uuvz *= 2;
    // return vec3.add(float* dst, a, vec3.add(float* dst, uv, uuv));
    dst[0] = x + uvx + uuvx;
    dst[1] = y + uvy + uuvy;
    dst[2] = z + uvz + uuvz;
}

/**
 * Rotate a 3D vector around the x-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 */
void vec3_rotateX(float* dst, float* b, float c) {
    float p[3], r[3];
    //Translate point to the origin
    p[0] = dst[0] - b[0];
    p[1] = dst[1] - b[1];
    p[2] = dst[2] - b[2];

    //perform rotation
    r[0] = p[0];
    r[1] = p[1]*cosf(c) - p[2]*sinf(c);
    r[2] = p[1]*sinf(c) + p[2]*cosf(c);

    //translate to correct position
    dst[0] = r[0] + b[0];
    dst[1] = r[1] + b[1];
    dst[2] = r[2] + b[2];
}

/**
 * Rotate a 3D vector around the y-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 */
void vec3_rotateY(float* dst, float* b, float c) {
    float p[3], r[3];
    //Translate point to the origin
    p[0] = dst[0] - b[0];
    p[1] = dst[1] - b[1];
    p[2] = dst[2] - b[2];

    //perform rotation
    r[0] = p[2]*sinf(c) + p[0]*cosf(c);
    r[1] = p[1];
    r[2] = p[2]*cosf(c) - p[0]*sinf(c);

    //translate to correct position
    dst[0] = r[0] + b[0];
    dst[1] = r[1] + b[1];
    dst[2] = r[2] + b[2];
}

/**
 * Rotate a 3D vector around the z-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 */
void vec3_rotateZ(float* dst, float* b, float c) {
    float p[3], r[3];
    //Translate point to the origin
    p[0] = dst[0] - b[0];
    p[1] = dst[1] - b[1];
    p[2] = dst[2] - b[2];

    //perform rotation
    r[0] = p[0]*cosf(c) - p[1]*sinf(c);
    r[1] = p[0]*sinf(c) + p[1]*cosf(c);
    r[2] = p[2];

    //translate to correct position
    dst[0] = r[0] + b[0];
    dst[1] = r[1] + b[1];
    dst[2] = r[2] + b[2];
}

/**
 * Get the angle between two 3D vectors
 * @param {vec3} a The first operand
 * @param {vec3} b The second operand
 * @returns {Number} The angle in radians
 */
float vec3_angle(float* a, float* b) {
    float tempA[3];
    float tempB[3];
    tempA[0] = a[0], tempA[1] = a[1], tempA[2] = a[2];
    tempB[0] = b[0], tempB[1] = b[1], tempB[2] = b[2];

    vec3_normalize(tempA);
    vec3_normalize(tempB);

    float cosine = vec3_dot(tempA, tempB);

    if(cosine > 1.0) {
        return 0;
    }
    else if(cosine < -1.0) {
        return M_PI;
    } else {
        return acosf(cosine);
    }
}

/**
 * Returns whether or not the vectors have exactly the same elements
 *
 * @param {vec3} a The first vector.
 * @param {vec3} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
uint8_t vec3_equals(float* a, float* b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}
