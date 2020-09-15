#include "mat2.h"
#include "epsilon.h"
#include <math.h>
#include <float.h>
#include <stdio.h>

void mat4_dump(float dst[16]) {
    if (!dst) {
        fprintf(stderr, "mat4_dump(): undefined matrix\n");
        return;
    }
    fprintf(stderr, "+----------+----------+----------+----------+\n");
    fprintf(stderr, "| %8.4f | %8.4f | %8.4f | %8.4f |\n", dst[0], dst[1], dst[2], dst[3]);
    fprintf(stderr, "| %8.4f | %8.4f | %8.4f | %8.4f |\n", dst[4], dst[5], dst[6], dst[7]);
    fprintf(stderr, "| %8.4f | %8.4f | %8.4f | %8.4f |\n", dst[8], dst[9], dst[10], dst[11]);
    fprintf(stderr, "| %8.4f | %8.4f | %8.4f | %8.4f |\n", dst[12], dst[13], dst[14], dst[15]);
    fprintf(stderr, "+----------+----------+----------+----------+\n");
    fprintf(stderr, "   trans1     trans2     trans3\n");
    fprintf(stderr, "\n");
}

void mat4_identity(float dst[16]) {
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 1;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[10] = 1;
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_copy(float* dst, float* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
    dst[12] = src[12];
    dst[13] = src[13];
    dst[14] = src[14];
    dst[15] = src[15];
}

void mat4_set(float* dst, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
    dst[0] = m00;
    dst[1] = m01;
    dst[2] = m02;
    dst[3] = m03;
    dst[4] = m10;
    dst[5] = m11;
    dst[6] = m12;
    dst[7] = m13;
    dst[8] = m20;
    dst[9] = m21;
    dst[10] = m22;
    dst[11] = m23;
    dst[12] = m30;
    dst[13] = m31;
    dst[14] = m32;
    dst[15] = m33;
}

void mat4_transpose(float* dst) {
    float a01 = dst[1], a02 = dst[2], a03 = dst[3];
    float a12 = dst[6], a13 = dst[7];
    float a23 = dst[11];

    dst[1] = dst[4];
    dst[2] = dst[8];
    dst[3] = dst[12];
    dst[4] = a01;
    dst[6] = dst[9];
    dst[7] = dst[13];
    dst[8] = a02;
    dst[9] = a12;
    dst[11] = dst[14];
    dst[12] = a03;
    dst[13] = a13;
    dst[14] = a23;
}

void mat4_invert(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2], a03 = dst[3];
    float a10 = dst[4], a11 = dst[5], a12 = dst[6], a13 = dst[7];
    float a20 = dst[8], a21 = dst[9], a22 = dst[10], a23 = dst[11];
    float a30 = dst[12], a31 = dst[13], a32 = dst[14], a33 = dst[15];

    float b00 = (a00 * a11) - (a01 * a10);
    float b01 = (a00 * a12) - (a02 * a10);
    float b02 = (a00 * a13) - (a03 * a10);
    float b03 = (a01 * a12) - (a02 * a11);
    float b04 = (a01 * a13) - (a03 * a11);
    float b05 = (a02 * a13) - (a03 * a12);
    float b06 = (a20 * a31) - (a21 * a30);
    float b07 = (a20 * a32) - (a22 * a30);
    float b08 = (a20 * a33) - (a23 * a30);
    float b09 = (a21 * a32) - (a22 * a31);
    float b10 = (a21 * a33) - (a23 * a31);
    float b11 = (a22 * a33) - (a23 * a32);

    float det = (b00 * b11) - (b01 * b10) + (b02 * b09) + (b03 * b08) - (b04 * b07) + (b05 * b06);

    if (!det) {
        return;
    }
    det = 1.0 / det;

    dst[0] = (a11 * b11 - a12 * b10 + a13 * b09) * det;
    dst[1] = (a02 * b10 - a01 * b11 - a03 * b09) * det;
    dst[2] = (a31 * b05 - a32 * b04 + a33 * b03) * det;
    dst[3] = (a22 * b04 - a21 * b05 - a23 * b03) * det;
    dst[4] = (a12 * b08 - a10 * b11 - a13 * b07) * det;
    dst[5] = (a00 * b11 - a02 * b08 + a03 * b07) * det;
    dst[6] = (a32 * b02 - a30 * b05 - a33 * b01) * det;
    dst[7] = (a20 * b05 - a22 * b02 + a23 * b01) * det;
    dst[8] = (a10 * b10 - a11 * b08 + a13 * b06) * det;
    dst[9] = (a01 * b08 - a00 * b10 - a03 * b06) * det;
    dst[10] = (a30 * b04 - a31 * b02 + a33 * b00) * det;
    dst[11] = (a21 * b02 - a20 * b04 - a23 * b00) * det;
    dst[12] = (a11 * b07 - a10 * b09 - a12 * b06) * det;
    dst[13] = (a00 * b09 - a01 * b07 + a02 * b06) * det;
    dst[14] = (a31 * b01 - a30 * b03 - a32 * b00) * det;
    dst[15] = (a20 * b03 - a21 * b01 + a22 * b00) * det;
}

void mat4_adjoint(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2], a03 = dst[3];
    float a10 = dst[4], a11 = dst[5], a12 = dst[6], a13 = dst[7];
    float a20 = dst[8], a21 = dst[9], a22 = dst[10], a23 = dst[11];
    float a30 = dst[12], a31 = dst[13], a32 = dst[14], a33 = dst[15];

    dst[0]  =  (a11 * (a22 * a33 - a23 * a32) - a21 * (a12 * a33 - a13 * a32) + a31 * (a12 * a23 - a13 * a22));
    dst[1]  = -(a01 * (a22 * a33 - a23 * a32) - a21 * (a02 * a33 - a03 * a32) + a31 * (a02 * a23 - a03 * a22));
    dst[2]  =  (a01 * (a12 * a33 - a13 * a32) - a11 * (a02 * a33 - a03 * a32) + a31 * (a02 * a13 - a03 * a12));
    dst[3]  = -(a01 * (a12 * a23 - a13 * a22) - a11 * (a02 * a23 - a03 * a22) + a21 * (a02 * a13 - a03 * a12));
    dst[4]  = -(a10 * (a22 * a33 - a23 * a32) - a20 * (a12 * a33 - a13 * a32) + a30 * (a12 * a23 - a13 * a22));
    dst[5]  =  (a00 * (a22 * a33 - a23 * a32) - a20 * (a02 * a33 - a03 * a32) + a30 * (a02 * a23 - a03 * a22));
    dst[6]  = -(a00 * (a12 * a33 - a13 * a32) - a10 * (a02 * a33 - a03 * a32) + a30 * (a02 * a13 - a03 * a12));
    dst[7]  =  (a00 * (a12 * a23 - a13 * a22) - a10 * (a02 * a23 - a03 * a22) + a20 * (a02 * a13 - a03 * a12));
    dst[8]  =  (a10 * (a21 * a33 - a23 * a31) - a20 * (a11 * a33 - a13 * a31) + a30 * (a11 * a23 - a13 * a21));
    dst[9]  = -(a00 * (a21 * a33 - a23 * a31) - a20 * (a01 * a33 - a03 * a31) + a30 * (a01 * a23 - a03 * a21));
    dst[10] =  (a00 * (a11 * a33 - a13 * a31) - a10 * (a01 * a33 - a03 * a31) + a30 * (a01 * a13 - a03 * a11));
    dst[11] = -(a00 * (a11 * a23 - a13 * a21) - a10 * (a01 * a23 - a03 * a21) + a20 * (a01 * a13 - a03 * a11));
    dst[12] = -(a10 * (a21 * a32 - a22 * a31) - a20 * (a11 * a32 - a12 * a31) + a30 * (a11 * a22 - a12 * a21));
    dst[13] =  (a00 * (a21 * a32 - a22 * a31) - a20 * (a01 * a32 - a02 * a31) + a30 * (a01 * a22 - a02 * a21));
    dst[14] = -(a00 * (a11 * a32 - a12 * a31) - a10 * (a01 * a32 - a02 * a31) + a30 * (a01 * a12 - a02 * a11));
    dst[15] =  (a00 * (a11 * a22 - a12 * a21) - a10 * (a01 * a22 - a02 * a21) + a20 * (a01 * a12 - a02 * a11));
}

float mat4_determinant(float* dst) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2], a03 = dst[3];
    float a10 = dst[4], a11 = dst[5], a12 = dst[6], a13 = dst[7];
    float a20 = dst[8], a21 = dst[9], a22 = dst[10], a23 = dst[11];
    float a30 = dst[12], a31 = dst[13], a32 = dst[14], a33 = dst[15];

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

    return b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
}

void mat4_multiply(float* dst, float* b) {
    float a00 = dst[0], a01 = dst[1], a02 = dst[2], a03 = dst[3];
    float a10 = dst[4], a11 = dst[5], a12 = dst[6], a13 = dst[7];
    float a20 = dst[8], a21 = dst[9], a22 = dst[10], a23 = dst[11];
    float a30 = dst[12], a31 = dst[13], a32 = dst[14], a33 = dst[15];

    // Cache only the current line of the second matrix
    float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3];
    dst[0] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    dst[1] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    dst[2] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    dst[3] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[4]; b1 = b[5]; b2 = b[6]; b3 = b[7];
    dst[4] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    dst[5] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    dst[6] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    dst[7] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[8]; b1 = b[9]; b2 = b[10]; b3 = b[11];
    dst[8] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    dst[9] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    dst[10] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    dst[11] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[12]; b1 = b[13]; b2 = b[14]; b3 = b[15];
    dst[12] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    dst[13] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    dst[14] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    dst[15] = b0*a03 + b1*a13 + b2*a23 + b3*a33;
}

void mat4_translate(float dst[16], float v[3]) {
    float x = v[0], y = v[1], z = v[2];
    dst[12] = dst[0] * x + dst[4] * y + dst[8] * z + dst[12];
    dst[13] = dst[1] * x + dst[5] * y + dst[9] * z + dst[13];
    dst[14] = dst[2] * x + dst[6] * y + dst[10] * z + dst[14];
    dst[15] = dst[3] * x + dst[7] * y + dst[11] * z + dst[15];
}

void mat4_translatef(float dst[16], float x, float y, float z) {
    dst[12] = dst[0] * x + dst[4] * y + dst[8] * z + dst[12];
    dst[13] = dst[1] * x + dst[5] * y + dst[9] * z + dst[13];
    dst[14] = dst[2] * x + dst[6] * y + dst[10] * z + dst[14];
    dst[15] = dst[3] * x + dst[7] * y + dst[11] * z + dst[15];
}

void mat4_scale(float* dst, float* v) {
    float x = v[0], y = v[1], z = v[2];

    dst[0] = dst[0] * x;
    dst[1] = dst[1] * x;
    dst[2] = dst[2] * x;
    dst[3] = dst[3] * x;
    dst[4] = dst[4] * y;
    dst[5] = dst[5] * y;
    dst[6] = dst[6] * y;
    dst[7] = dst[7] * y;
    dst[8] = dst[8] * z;
    dst[9] = dst[9] * z;
    dst[10] = dst[10] * z;
    dst[11] = dst[11] * z;
    dst[12] = dst[12];
    dst[13] = dst[13];
    dst[14] = dst[14];
    dst[15] = dst[15];
}

void mat4_rotate(float* dst, float rad, float* axis) {
    float x = axis[0], y = axis[1], z = axis[2];
    float len = sqrtf(x * x + y * y + z * z);
    float s, c, t;
    float a00, a01, a02, a03;
    float a10, a11, a12, a13;
    float a20, a21, a22, a23;
    float b00, b01, b02;
    float b10, b11, b12;
    float b20, b21, b22;

    if (len < EPSILON) { return; }

    len = 1 / len;
    x *= len;
    y *= len;
    z *= len;

    s = sinf(rad);
    c = cosf(rad);
    t = 1 - c;

    a00 = dst[0]; a01 = dst[1]; a02 = dst[2]; a03 = dst[3];
    a10 = dst[4]; a11 = dst[5]; a12 = dst[6]; a13 = dst[7];
    a20 = dst[8]; a21 = dst[9]; a22 = dst[10]; a23 = dst[11];

    // Construct the elements of the rotation matrix
    b00 = x * x * t + c; b01 = y * x * t + z * s; b02 = z * x * t - y * s;
    b10 = x * y * t - z * s; b11 = y * y * t + c; b12 = z * y * t + x * s;
    b20 = x * z * t + y * s; b21 = y * z * t - x * s; b22 = z * z * t + c;

    // Perform rotation-specific matrix multiplication
    dst[0] = a00 * b00 + a10 * b01 + a20 * b02;
    dst[1] = a01 * b00 + a11 * b01 + a21 * b02;
    dst[2] = a02 * b00 + a12 * b01 + a22 * b02;
    dst[3] = a03 * b00 + a13 * b01 + a23 * b02;
    dst[4] = a00 * b10 + a10 * b11 + a20 * b12;
    dst[5] = a01 * b10 + a11 * b11 + a21 * b12;
    dst[6] = a02 * b10 + a12 * b11 + a22 * b12;
    dst[7] = a03 * b10 + a13 * b11 + a23 * b12;
    dst[8] = a00 * b20 + a10 * b21 + a20 * b22;
    dst[9] = a01 * b20 + a11 * b21 + a21 * b22;
    dst[10] = a02 * b20 + a12 * b21 + a22 * b22;
    dst[11] = a03 * b20 + a13 * b21 + a23 * b22;
}

void mat4_rotateX(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);
    float a10 = dst[4];
    float a11 = dst[5];
    float a12 = dst[6];
    float a13 = dst[7];
    float a20 = dst[8];
    float a21 = dst[9];
    float a22 = dst[10];
    float a23 = dst[11];

    // Perform axis-specific matrix multiplication
    dst[4] = a10 * c + a20 * s;
    dst[5] = a11 * c + a21 * s;
    dst[6] = a12 * c + a22 * s;
    dst[7] = a13 * c + a23 * s;
    dst[8] = a20 * c - a10 * s;
    dst[9] = a21 * c - a11 * s;
    dst[10] = a22 * c - a12 * s;
    dst[11] = a23 * c - a13 * s;
}

void mat4_rotateY(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);
    float a00 = dst[0];
    float a01 = dst[1];
    float a02 = dst[2];
    float a03 = dst[3];
    float a20 = dst[8];
    float a21 = dst[9];
    float a22 = dst[10];
    float a23 = dst[11];

    // Perform axis-specific matrix multiplication
    dst[0] = a00 * c - a20 * s;
    dst[1] = a01 * c - a21 * s;
    dst[2] = a02 * c - a22 * s;
    dst[3] = a03 * c - a23 * s;
    dst[8] = a00 * s + a20 * c;
    dst[9] = a01 * s + a21 * c;
    dst[10] = a02 * s + a22 * c;
    dst[11] = a03 * s + a23 * c;
}

void mat4_rotateZ(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);
    float a00 = dst[0];
    float a01 = dst[1];
    float a02 = dst[2];
    float a03 = dst[3];
    float a10 = dst[4];
    float a11 = dst[5];
    float a12 = dst[6];
    float a13 = dst[7];

    // Perform axis-specific matrix multiplication
    dst[0] = a00 * c + a10 * s;
    dst[1] = a01 * c + a11 * s;
    dst[2] = a02 * c + a12 * s;
    dst[3] = a03 * c + a13 * s;
    dst[4] = a10 * c - a00 * s;
    dst[5] = a11 * c - a01 * s;
    dst[6] = a12 * c - a02 * s;
    dst[7] = a13 * c - a03 * s;
}

void mat4_fromTranslation(float* dst, float* v) {
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 1;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[10] = 1;
    dst[11] = 0;
    dst[12] = v[0];
    dst[13] = v[1];
    dst[14] = v[2];
    dst[15] = 1;
}

void mat4_fromScaling(float* dst, float* v) {
    dst[0] = v[0];
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = v[1];
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[10] = v[2];
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_fromRotation(float* dst, float rad, float* axis) {
    float x = axis[0], y = axis[1], z = axis[2];
    float len = sqrtf(x * x + y * y + z * z);
    float s, c, t;

    if (len < EPSILON) { return; }

    len = 1 / len;
    x *= len;
    y *= len;
    z *= len;

    s = sinf(rad);
    c = cosf(rad);
    t = 1 - c;

    // Perform rotation-specific matrix multiplication
    dst[0] = x * x * t + c;
    dst[1] = y * x * t + z * s;
    dst[2] = z * x * t - y * s;
    dst[3] = 0;
    dst[4] = x * y * t - z * s;
    dst[5] = y * y * t + c;
    dst[6] = z * y * t + x * s;
    dst[7] = 0;
    dst[8] = x * z * t + y * s;
    dst[9] = y * z * t - x * s;
    dst[10] = z * z * t + c;
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_fromXRotation(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);

    // Perform axis-specific matrix multiplication
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = c;
    dst[6] = s;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = -s;
    dst[10] = c;
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_fromYRotation(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);

    // Perform axis-specific matrix multiplication
    dst[0] = c;
    dst[1] = 0;
    dst[2] = -s;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 1;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = s;
    dst[9] = 0;
    dst[10] = c;
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_fromZRotation(float* dst, float rad) {
    float s = sinf(rad);
    float c = cosf(rad);

    // Perform axis-specific matrix multiplication
    dst[0]  = c;
    dst[1]  = s;
    dst[2]  = 0;
    dst[3]  = 0;
    dst[4] = -s;
    dst[5] = c;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[10] = 1;
    dst[11] = 0;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_fromRotationTranslation(float* dst, float* q, float* v) {
    // Quaternion math
    float x = q[0], y = q[1], z = q[2], w = q[3];
    float x2 = x + x;
    float y2 = y + y;
    float z2 = z + z;

    float xx = x * x2;
    float xy = x * y2;
    float xz = x * z2;
    float yy = y * y2;
    float yz = y * z2;
    float zz = z * z2;
    float wx = w * x2;
    float wy = w * y2;
    float wz = w * z2;

    dst[0] = 1 - (yy + zz);
    dst[1] = xy + wz;
    dst[2] = xz - wy;
    dst[3] = 0;
    dst[4] = xy - wz;
    dst[5] = 1 - (xx + zz);
    dst[6] = yz + wx;
    dst[7] = 0;
    dst[8] = xz + wy;
    dst[9] = yz - wx;
    dst[10] = 1 - (xx + yy);
    dst[11] = 0;
    dst[12] = v[0];
    dst[13] = v[1];
    dst[14] = v[2];
    dst[15] = 1;
}

void mat4_getTranslation(float* dst, float* mat) {
    dst[0] = mat[12];
    dst[1] = mat[13];
    dst[2] = mat[14];
}

void mat4_getScaling(float* dst, float* mat) {
    float m11 = mat[0];
    float m12 = mat[1];
    float m13 = mat[2];
    float m21 = mat[4];
    float m22 = mat[5];
    float m23 = mat[6];
    float m31 = mat[8];
    float m32 = mat[9];
    float m33 = mat[10];

    dst[0] = sqrtf(m11 * m11 + m12 * m12 + m13 * m13);
    dst[1] = sqrtf(m21 * m21 + m22 * m22 + m23 * m23);
    dst[2] = sqrtf(m31 * m31 + m32 * m32 + m33 * m33);
}

void mat4_getRotation(float* dst, float* mat) {
    // Algorithm taken from http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
    float trace = mat[0] + mat[5] + mat[10];
    float S = 0;

    if (trace > 0) {
        S = sqrtf(trace + 1.0) * 2;
        dst[3] = 0.25 * S;
        dst[0] = (mat[6] - mat[9]) / S;
        dst[1] = (mat[8] - mat[2]) / S;
        dst[2] = (mat[1] - mat[4]) / S;
    }
    else if ((mat[0] > mat[5]) && (mat[0] > mat[10])) {
        S = sqrtf(1.0 + mat[0] - mat[5] - mat[10]) * 2;
        dst[3] = (mat[6] - mat[9]) / S;
        dst[0] = 0.25 * S;
        dst[1] = (mat[1] + mat[4]) / S;
        dst[2] = (mat[8] + mat[2]) / S;
    }
    else if (mat[5] > mat[10]) {
        S = sqrtf(1.0 + mat[5] - mat[0] - mat[10]) * 2;
        dst[3] = (mat[8] - mat[2]) / S;
        dst[0] = (mat[1] + mat[4]) / S;
        dst[1] = 0.25 * S;
        dst[2] = (mat[6] + mat[9]) / S;
    }
    else {
        S = sqrtf(1.0 + mat[10] - mat[0] - mat[5]) * 2;
        dst[3] = (mat[1] - mat[4]) / S;
        dst[0] = (mat[8] + mat[2]) / S;
        dst[1] = (mat[6] + mat[9]) / S;
        dst[2] = 0.25 * S;
    }
}

void mat4_fromRotationTranslationScale(float* dst, float* q, float* v, float* s) {
    // Quaternion math
    float x = q[0], y = q[1], z = q[2], w = q[3];
    float x2 = x + x;
    float y2 = y + y;
    float z2 = z + z;

    float xx = x * x2;
    float xy = x * y2;
    float xz = x * z2;
    float yy = y * y2;
    float yz = y * z2;
    float zz = z * z2;
    float wx = w * x2;
    float wy = w * y2;
    float wz = w * z2;
    float sx = s[0];
    float sy = s[1];
    float sz = s[2];

    dst[0] = (1 - (yy + zz)) * sx;
    dst[1] = (xy + wz) * sx;
    dst[2] = (xz - wy) * sx;
    dst[3] = 0;
    dst[4] = (xy - wz) * sy;
    dst[5] = (1 - (xx + zz)) * sy;
    dst[6] = (yz + wx) * sy;
    dst[7] = 0;
    dst[8] = (xz + wy) * sz;
    dst[9] = (yz - wx) * sz;
    dst[10] = (1 - (xx + yy)) * sz;
    dst[11] = 0;
    dst[12] = v[0];
    dst[13] = v[1];
    dst[14] = v[2];
    dst[15] = 1;
}

void mat4_fromRotationTranslationScaleOrigin(float* dst, float* q, float* v, float* s, float* o) {
    // Quaternion math
    float x = q[0], y = q[1], z = q[2], w = q[3];
    float x2 = x + x;
    float y2 = y + y;
    float z2 = z + z;

    float xx = x * x2;
    float xy = x * y2;
    float xz = x * z2;
    float yy = y * y2;
    float yz = y * z2;
    float zz = z * z2;
    float wx = w * x2;
    float wy = w * y2;
    float wz = w * z2;

    float sx = s[0];
    float sy = s[1];
    float sz = s[2];

    float ox = o[0];
    float oy = o[1];
    float oz = o[2];

    float out0 = (1 - (yy + zz)) * sx;
    float out1 = (xy + wz) * sx;
    float out2 = (xz - wy) * sx;
    float out4 = (xy - wz) * sy;
    float out5 = (1 - (xx + zz)) * sy;
    float out6 = (yz + wx) * sy;
    float out8 = (xz + wy) * sz;
    float out9 = (yz - wx) * sz;
    float out10 = (1 - (xx + yy)) * sz;

    dst[0] = out0;
    dst[1] = out1;
    dst[2] = out2;
    dst[3] = 0;
    dst[4] = out4;
    dst[5] = out5;
    dst[6] = out6;
    dst[7] = 0;
    dst[8] = out8;
    dst[9] = out9;
    dst[10] = out10;
    dst[11] = 0;
    dst[12] = v[0] + ox - (out0 * ox + out4 * oy + out8 * oz);
    dst[13] = v[1] + oy - (out1 * ox + out5 * oy + out9 * oz);
    dst[14] = v[2] + oz - (out2 * ox + out6 * oy + out10 * oz);
    dst[15] = 1;
}

void mat4_fromQuat(float* dst, float* q) {
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
    dst[1] = yx + wz;
    dst[2] = zx - wy;
    dst[3] = 0;

    dst[4] = yx - wz;
    dst[5] = 1 - xx - zz;
    dst[6] = zy + wx;
    dst[7] = 0;

    dst[8] = zx + wy;
    dst[9] = zy - wx;
    dst[10] = 1 - xx - yy;
    dst[11] = 0;

    dst[12] = 0;
    dst[13] = 0;
    dst[14] = 0;
    dst[15] = 1;
}

void mat4_frustum(float* dst, float left, float right, float bottom, float top, float near, float far) {
    float rl = 1 / (right - left);
    float tb = 1 / (top - bottom);
    float nf = 1 / (near - far);
    dst[0] = (near * 2) * rl;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = (near * 2) * tb;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = (right + left) * rl;
    dst[9] = (top + bottom) * tb;
    dst[10] = (far + near) * nf;
    dst[11] = -1;
    dst[12] = 0;
    dst[13] = 0;
    dst[14] = (far * near * 2) * nf;
    dst[15] = 0;
}

void mat4_perspective(float* dst, float fovy, float aspect, float near, float far) {
    float f = 1.0 / tanf(fovy / 2), nf;
    dst[0] = f / aspect;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = f;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[11] = -1;
    dst[12] = 0;
    dst[13] = 0;
    dst[15] = 0;
    if (far != 0 && far != FLT_MAX) {
        nf = 1 / (near - far);
        dst[10] = (far + near) * nf;
        dst[14] = (2 * far * near) * nf;
    }
    else {
        dst[10] = -1;
        dst[14] = -2 * near;
    }
}

void mat4_ortho(float* dst, float left, float right, float bottom, float top, float near, float far) {
    float lr = 1 / (left - right);
    float bt = 1 / (bottom - top);
    float nf = 1 / (near - far);
    dst[0] = -2 * lr;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = -2 * bt;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[10] = 2 * nf;
    dst[11] = 0;
    dst[12] = (left + right) * lr;
    dst[13] = (top + bottom) * bt;
    dst[14] = (far + near) * nf;
    dst[15] = 1;
}

void mat4_lookAt(float* dst, float* eye, float* center, float* up) {
    float x0, x1, x2, y0, y1, y2, z0, z1, z2, len;
    float eyex = eye[0];
    float eyey = eye[1];
    float eyez = eye[2];
    float upx = up[0];
    float upy = up[1];
    float upz = up[2];
    float centerx = center[0];
    float centery = center[1];
    float centerz = center[2];

    if (fabs(eyex - centerx) < EPSILON &&
        fabs(eyey - centery) < EPSILON &&
        fabs(eyez - centerz) < EPSILON) {
        return mat4_identity(dst);
    }

    z0 = eyex - centerx;
    z1 = eyey - centery;
    z2 = eyez - centerz;

    len = 1 / sqrtf(z0 * z0 + z1 * z1 + z2 * z2);
    z0 *= len;
    z1 *= len;
    z2 *= len;

    x0 = upy * z2 - upz * z1;
    x1 = upz * z0 - upx * z2;
    x2 = upx * z1 - upy * z0;
    len = sqrtf(x0 * x0 + x1 * x1 + x2 * x2);
    if (!len) {
        x0 = 0;
        x1 = 0;
        x2 = 0;
    }
    else {
        len = 1 / len;
        x0 *= len;
        x1 *= len;
        x2 *= len;
    }

    y0 = z1 * x2 - z2 * x1;
    y1 = z2 * x0 - z0 * x2;
    y2 = z0 * x1 - z1 * x0;

    len = sqrtf(y0 * y0 + y1 * y1 + y2 * y2);
    if (!len) {
        y0 = 0;
        y1 = 0;
        y2 = 0;
    } else {
        len = 1 / len;
        y0 *= len;
        y1 *= len;
        y2 *= len;
    }

    dst[0] = x0;
    dst[1] = y0;
    dst[2] = z0;
    dst[3] = 0;
    dst[4] = x1;
    dst[5] = y1;
    dst[6] = z1;
    dst[7] = 0;
    dst[8] = x2;
    dst[9] = y2;
    dst[10] = z2;
    dst[11] = 0;
    dst[12] = -(x0 * eyex + x1 * eyey + x2 * eyez);
    dst[13] = -(y0 * eyex + y1 * eyey + y2 * eyez);
    dst[14] = -(z0 * eyex + z1 * eyey + z2 * eyez);
    dst[15] = 1;
}

void mat4_targetTo(float* dst, float* eye, float* target, float* up) {
    float eyex = eye[0],
        eyey = eye[1],
        eyez = eye[2],
        upx = up[0],
        upy = up[1],
        upz = up[2];

    float z0 = eyex - target[0],
        z1 = eyey - target[1],
        z2 = eyez - target[2];

    float len = z0*z0 + z1*z1 + z2*z2;
    if (len > 0) {
        len = 1 / sqrtf(len);
        z0 *= len;
        z1 *= len;
        z2 *= len;
    }

    float x0 = upy * z2 - upz * z1,
        x1 = upz * z0 - upx * z2,
        x2 = upx * z1 - upy * z0;

    len = x0*x0 + x1*x1 + x2*x2;
    if (len > 0) {
        len = 1 / sqrtf(len);
        x0 *= len;
        x1 *= len;
        x2 *= len;
    }

    dst[0] = x0;
    dst[1] = x1;
    dst[2] = x2;
    dst[3] = 0;
    dst[4] = z1 * x2 - z2 * x1;
    dst[5] = z2 * x0 - z0 * x2;
    dst[6] = z0 * x1 - z1 * x0;
    dst[7] = 0;
    dst[8] = z0;
    dst[9] = z1;
    dst[10] = z2;
    dst[11] = 0;
    dst[12] = eyex;
    dst[13] = eyey;
    dst[14] = eyez;
    dst[15] = 1;
};

float mat4_frob(float* a) {
    return (sqrtf(powf(a[0], 2) + powf(a[1], 2) + powf(a[2], 2) + powf(a[3], 2) + powf(a[4], 2) + powf(a[5], 2) + powf(a[6], 2) + powf(a[7], 2) + powf(a[8], 2) + powf(a[9], 2) + powf(a[10], 2) + powf(a[11], 2) + powf(a[12], 2) + powf(a[13], 2) + powf(a[14], 2) + powf(a[15], 2) ));
}

void mat4_add(float* dst, float* b) {
    dst[0] = dst[0] + b[0];
    dst[1] = dst[1] + b[1];
    dst[2] = dst[2] + b[2];
    dst[3] = dst[3] + b[3];
    dst[4] = dst[4] + b[4];
    dst[5] = dst[5] + b[5];
    dst[6] = dst[6] + b[6];
    dst[7] = dst[7] + b[7];
    dst[8] = dst[8] + b[8];
    dst[9] = dst[9] + b[9];
    dst[10] = dst[10] + b[10];
    dst[11] = dst[11] + b[11];
    dst[12] = dst[12] + b[12];
    dst[13] = dst[13] + b[13];
    dst[14] = dst[14] + b[14];
    dst[15] = dst[15] + b[15];
}

void mat4_subtract(float* dst, float* b) {
    dst[0] = dst[0] - b[0];
    dst[1] = dst[1] - b[1];
    dst[2] = dst[2] - b[2];
    dst[3] = dst[3] - b[3];
    dst[4] = dst[4] - b[4];
    dst[5] = dst[5] - b[5];
    dst[6] = dst[6] - b[6];
    dst[7] = dst[7] - b[7];
    dst[8] = dst[8] - b[8];
    dst[9] = dst[9] - b[9];
    dst[10] = dst[10] - b[10];
    dst[11] = dst[11] - b[11];
    dst[12] = dst[12] - b[12];
    dst[13] = dst[13] - b[13];
    dst[14] = dst[14] - b[14];
    dst[15] = dst[15] - b[15];
}

void mat4_multiplyScalar(float* dst, float b) {
    dst[0] = dst[0] * b;
    dst[1] = dst[1] * b;
    dst[2] = dst[2] * b;
    dst[3] = dst[3] * b;
    dst[4] = dst[4] * b;
    dst[5] = dst[5] * b;
    dst[6] = dst[6] * b;
    dst[7] = dst[7] * b;
    dst[8] = dst[8] * b;
    dst[9] = dst[9] * b;
    dst[10] = dst[10] * b;
    dst[11] = dst[11] * b;
    dst[12] = dst[12] * b;
    dst[13] = dst[13] * b;
    dst[14] = dst[14] * b;
    dst[15] = dst[15] * b;
}

void mat4_multiplyScalarAndAdd(float* dst, float* b, float scale) {
    dst[0] = dst[0] + (b[0] * scale);
    dst[1] = dst[1] + (b[1] * scale);
    dst[2] = dst[2] + (b[2] * scale);
    dst[3] = dst[3] + (b[3] * scale);
    dst[4] = dst[4] + (b[4] * scale);
    dst[5] = dst[5] + (b[5] * scale);
    dst[6] = dst[6] + (b[6] * scale);
    dst[7] = dst[7] + (b[7] * scale);
    dst[8] = dst[8] + (b[8] * scale);
    dst[9] = dst[9] + (b[9] * scale);
    dst[10] = dst[10] + (b[10] * scale);
    dst[11] = dst[11] + (b[11] * scale);
    dst[12] = dst[12] + (b[12] * scale);
    dst[13] = dst[13] + (b[13] * scale);
    dst[14] = dst[14] + (b[14] * scale);
    dst[15] = dst[15] + (b[15] * scale);
}

uint8_t mat4_equals(float* a, float* b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3] &&
        a[4] == b[4] && a[5] == b[5] && a[6] == b[6] && a[7] == b[7] &&
        a[8] == b[8] && a[9] == b[9] && a[10] == b[10] && a[11] == b[11] &&
        a[12] == b[12] && a[13] == b[13] && a[14] == b[14] && a[15] == b[15];
}
