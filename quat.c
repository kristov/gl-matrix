#include "quat.h"
#include "epsilon.h"
#include <math.h>

/**
 * Set a quat to the identity quaternion
 *
 * @param {quat} out the receiving quaternion
 */
void quat_identity(float* dst) {
    dst[0] = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 1;
}

/**
 * Sets a quat from the given angle and rotation axis,
 * then returns it.
 *
 * @param {quat} out the receiving quaternion
 * @param {vec3} axis the axis around which to rotate
 * @param {Number} rad the angle in radians
 **/
void quat_setAxisAngle(float* dst, float* axis, float rad) {
    rad = rad * 0.5;
    float s = sinf(rad);
    dst[0] = s * axis[0];
    dst[1] = s * axis[1];
    dst[2] = s * axis[2];
    dst[3] = cosf(rad);
}

/**
 * Gets the rotation axis and angle for a given
 *  quaternion. If a quaternion is created with
 *  setAxisAngle, this method will return the same
 *  values as providied in the original parameter list
 *  OR functionally equivalent values.
 * Example: The quaternion formed by axis [0, 0, 1] and
 *  angle -90 is the same as the quaternion formed by
 *  [0, 0, 1] and 270. This method favors the latter.
 * @param  {vec3} out_axis  Vector receiving the axis of rotation
 * @param  {quat} q     Quaternion to be decomposed
 * @return {Number}     Angle, in radians, of the rotation
 */
float quat_getAxisAngle(float* out_axis, float* q) {
    float rad = acosf(q[3]) * 2.0;
    float s = sinf(rad / 2.0);
    if (s > EPSILON) {
        out_axis[0] = q[0] / s;
        out_axis[1] = q[1] / s;
        out_axis[2] = q[2] / s;
    }
    else {
        // If s is zero, return any axis (no rotation - axis does not matter)
        out_axis[0] = 1;
        out_axis[1] = 0;
        out_axis[2] = 0;
    }
    return rad;
}

/**
 * Multiplies two quat's
 *
 * @param {quat} out the receiving quaternion
 * @param {quat} b the second operand
 */
void quat_multiply(float* dst, float* b) {
    float ax = dst[0], ay = dst[1], az = dst[2], aw = dst[3];
    float bx = b[0], by = b[1], bz = b[2], bw = b[3];

    dst[0] = ax * bw + aw * bx + ay * bz - az * by;
    dst[1] = ay * bw + aw * by + az * bx - ax * bz;
    dst[2] = az * bw + aw * bz + ax * by - ay * bx;
    dst[3] = aw * bw - ax * bx - ay * by - az * bz;
}

/**
 * Rotates a quaternion by the given angle about the X axis
 *
 * @param {quat} out quat receiving operation result
 * @param {number} rad angle (in radians) to rotate
 */
void quat_rotateX(float* dst, float rad) {
    rad *= 0.5;

    float ax = dst[0], ay = dst[1], az = dst[2], aw = dst[3];
    float bx = sinf(rad), bw = cosf(rad);

    dst[0] = ax * bw + aw * bx;
    dst[1] = ay * bw + az * bx;
    dst[2] = az * bw - ay * bx;
    dst[3] = aw * bw - ax * bx;
}

/**
 * Rotates a quaternion by the given angle about the Y axis
 *
 * @param {quat} out quat receiving operation result
 * @param {number} rad angle (in radians) to rotate
 */
void quat_rotateY(float* dst, float rad) {
    rad *= 0.5;

    float ax = dst[0], ay = dst[1], az = dst[2], aw = dst[3];
    float by = sinf(rad), bw = cosf(rad);

    dst[0] = ax * bw - az * by;
    dst[1] = ay * bw + aw * by;
    dst[2] = az * bw + ax * by;
    dst[3] = aw * bw - ay * by;
}

/**
 * Rotates a quaternion by the given angle about the Z axis
 *
 * @param {quat} out quat receiving operation result
 * @param {number} rad angle (in radians) to rotate
 */
void quat_rotateZ(float* dst, float rad) {
    rad *= 0.5;

    float ax = dst[0], ay = dst[1], az = dst[2], aw = dst[3];
    float bz = sinf(rad), bw = cosf(rad);

    dst[0] = ax * bw + ay * bz;
    dst[1] = ay * bw - ax * bz;
    dst[2] = az * bw + aw * bz;
    dst[3] = aw * bw - az * bz;
}

/**
 * Calculates the W component of a quat from the X, Y, and Z components.
 * Assumes that quaternion is 1 unit in length.
 * Any existing W component will be ignored.
 *
 * @param {quat} out the receiving quaternion
 */
void quat_calculateW(float* dst) {
    float x = dst[0], y = dst[1], z = dst[2];

    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
    dst[3] = sqrtf(fabs(1.0 - x * x - y * y - z * z));
}

/**
 * Performs a spherical linear interpolation between two quat
 *
 * @param {quat} out the receiving quaternion
 * @param {quat} b the second operand
 * @param {Number} t interpolation amount, in the range [0-1], between the two inputs
 */
void quat_slerp(float* dst, float* b, float t) {
    // benchmarks:
    //    http://jsperf.com/quaternion-slerp-implementations
    float ax = dst[0], ay = dst[1], az = dst[2], aw = dst[3];
    float bx = b[0], by = b[1], bz = b[2], bw = b[3];

    float omega, cosom, sinom, scale0, scale1;

    // calc cosine
    cosom = ax * bx + ay * by + az * bz + aw * bw;
    // adjust signs (if necessary)
    if ( cosom < 0.0 ) {
        cosom = -cosom;
        bx = - bx;
        by = - by;
        bz = - bz;
        bw = - bw;
    }
    // calculate coefficients
    if ( (1.0 - cosom) > EPSILON ) {
        // standard case (slerp)
        omega  = acosf(cosom);
        sinom  = sinf(omega);
        scale0 = sinf((1.0 - t) * omega) / sinom;
        scale1 = sinf(t * omega) / sinom;
    }
    else {
        // "from" and "to" quaternions are very close
        //  ... so we can do a linear interpolation
        scale0 = 1.0 - t;
        scale1 = t;
    }
    // calculate final values
    dst[0] = scale0 * ax + scale1 * bx;
    dst[1] = scale0 * ay + scale1 * by;
    dst[2] = scale0 * az + scale1 * bz;
    dst[3] = scale0 * aw + scale1 * bw;
}

/**
 * Calculates the inverse of a quat
 *
 * @param {quat} out the receiving quaternion
 */
void quat_invert(float* dst) {
    float a0 = dst[0], a1 = dst[1], a2 = dst[2], a3 = dst[3];
    float dot = a0*a0 + a1*a1 + a2*a2 + a3*a3;
    float invDot = dot ? 1.0/dot : 0;

    // TODO: Would be faster to return [0,0,0,0] immediately if dot == 0

    dst[0] = -a0*invDot;
    dst[1] = -a1*invDot;
    dst[2] = -a2*invDot;
    dst[3] = a3*invDot;
}

/**
 * Calculates the conjugate of a quat
 * If the quaternion is normalized, this function is faster than quat.inverse and produces the same result.
 *
 * @param {quat} out the receiving quaternion
 * @param {quat} a quat to calculate conjugate of
 */
void quat_conjugate(float* dst) {
    dst[0] = -dst[0];
    dst[1] = -dst[1];
    dst[2] = -dst[2];
    dst[3] = dst[3];
}

/**
 * Creates a quaternion from the given 3x3 rotation matrix.
 *
 * NOTE: The resultant quaternion is not normalized, so you should be sure
 * to renormalize the quaternion yourself where necessary.
 *
 * @param {quat} out the receiving quaternion
 * @param {mat3} m rotation matrix
 */
void quat_fromMat3(float* dst, float* m) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
    // article "Quaternion Calculus and Fast Animation".
    float fTrace = m[0] + m[4] + m[8];
    float fRoot;

    if ( fTrace > 0.0 ) {
        // |w| > 1/2, may as well choose w > 1/2
        fRoot = sqrtf(fTrace + 1.0);  // 2w
        dst[3] = 0.5 * fRoot;
        fRoot = 0.5/fRoot;  // 1/(4w)
        dst[0] = (m[5]-m[7])*fRoot;
        dst[1] = (m[6]-m[2])*fRoot;
        dst[2] = (m[1]-m[3])*fRoot;
    }
    else {
        // |w| <= 1/2
        uint8_t i = 0;
        if ( m[4] > m[0] )
            i = 1;
        if ( m[8] > m[i*3+i] )
            i = 2;
        uint8_t j = (i+1)%3;
        uint8_t k = (i+2)%3;

        fRoot = sqrtf(m[i*3+i]-m[j*3+j]-m[k*3+k] + 1.0);
        dst[i] = 0.5 * fRoot;
        fRoot = 0.5 / fRoot;
        dst[3] = (m[j*3+k] - m[k*3+j]) * fRoot;
        dst[j] = (m[j*3+i] + m[i*3+j]) * fRoot;
        dst[k] = (m[k*3+i] + m[i*3+k]) * fRoot;
    }
}

/**
 * Creates a quaternion from the given euler angle x, y, z.
 *
 * @param {quat} out the receiving quaternion
 * @param {x} Angle to rotate around X axis in degrees.
 * @param {y} Angle to rotate around Y axis in degrees.
 * @param {z} Angle to rotate around Z axis in degrees.
 */
void quat_fromEuler(float* dst, float x, float y, float z) {
    float halfToRad = 0.5 * M_PI / 180.0;
    x *= halfToRad;
    y *= halfToRad;
    z *= halfToRad;

    float sx = sinf(x);
    float cx = cosf(x);
    float sy = sinf(y);
    float cy = cosf(y);
    float sz = sinf(z);
    float cz = cosf(z);

    dst[0] = sx * cy * cz - cx * sy * sz;
    dst[1] = cx * sy * cz + sx * cy * sz;
    dst[2] = cx * cy * sz - sx * sy * cz;
    dst[3] = cx * cy * cz + sx * sy * sz;
}
