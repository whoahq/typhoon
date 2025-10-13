#include "tempest/matrix/C44Matrix.hpp"
#include "tempest/Quaternion.hpp"
#include "tempest/Vector.hpp"
#include "tempest/math/CMath.hpp"
#include "tempest/matrix/C33Matrix.hpp"
#include <cmath>

C44Matrix C44Matrix::RotationAroundZ(float angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);

    float a0 = cosAngle;
    float a1 = sinAngle;
    float a2 = 0.0f;
    float a3 = 0.0f;

    float b0 = -sinAngle;
    float b1 = cosAngle;
    float b2 = 0.0f;
    float b3 = 0.0f;

    float c0 = 0.0f;
    float c1 = 0.0f;
    float c2 = 1.0f;
    float c3 = 0.0f;

    float d0 = 0.0f;
    float d1 = 0.0f;
    float d2 = 0.0f;
    float d3 = 1.0f;

    return { a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3, d0, d1, d2, d3 };
}

C44Matrix::C44Matrix() {
    this->a0 = 1.0f;
    this->a1 = 0.0f;
    this->a2 = 0.0f;
    this->a3 = 0.0f;

    this->b0 = 0.0f;
    this->b1 = 1.0f;
    this->b2 = 0.0f;
    this->b3 = 0.0f;

    this->c0 = 0.0f;
    this->c1 = 0.0f;
    this->c2 = 1.0f;
    this->c3 = 0.0f;

    this->d0 = 0.0f;
    this->d1 = 0.0f;
    this->d2 = 0.0f;
    this->d3 = 1.0f;
}

C44Matrix::C44Matrix(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3) {
    this->a0 = a0;
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;

    this->b0 = b0;
    this->b1 = b1;
    this->b2 = b2;
    this->b3 = b3;

    this->c0 = c0;
    this->c1 = c1;
    this->c2 = c2;
    this->c3 = c3;

    this->d0 = d0;
    this->d1 = d1;
    this->d2 = d2;
    this->d3 = d3;
}

C44Matrix::C44Matrix(const C33Matrix& m) {
    this->a0 = m.a0;
    this->a1 = m.a1;
    this->a2 = m.a2;
    this->a3 = 0.0f;

    this->b0 = m.b0;
    this->b1 = m.b1;
    this->b2 = m.b2;
    this->b3 = 0.0f;

    this->c0 = m.c0;
    this->c1 = m.c1;
    this->c2 = m.c2;
    this->c3 = 0.0f;

    this->d0 = 0.0f;
    this->d1 = 0.0f;
    this->d2 = 0.0f;
    this->d3 = 1.0f;
}

C44Matrix::C44Matrix(const C4Quaternion& rotation) {
    this->a3 = 0.0f;
    this->b3 = 0.0f;
    this->c3 = 0.0f;

    this->d0 = 0.0f;
    this->d1 = 0.0f;
    this->d2 = 0.0f;
    this->d3 = 1.0f;

    float v3 = rotation.x * 2.0f;
    float v4 = rotation.y * 2.0f;
    float v5 = rotation.z * 2.0f;

    float v6 = rotation.w * v3;
    float v7 = rotation.w * v4;
    float v8 = rotation.w * v5;

    float v10 = rotation.x * v3;
    float v11 = rotation.x * v4;
    float v19 = rotation.x * v5;
    float v12 = rotation.y * v4;
    float v17 = rotation.y * v5;
    float v16 = rotation.z * v5;

    this->a0 = 1.0f - (v16 + v12);
    this->a1 = v11 + v8;
    this->a2 = v19 - v7;
    this->b0 = v11 - v8;
    this->b1 = 1.0f - (v16 + v10);
    this->b2 = v17 + v6;
    this->c0 = v7 + v19;
    this->c1 = v17 - v6;
    this->c2 = 1.0f - (v10 + v12);
}

C44Matrix C44Matrix::Adjoint() const {
    float a0 = this->b2 * this->c3 * this->d1 + this->b3 * this->c1 * this->d2 + this->b1 * this->c2 * this->d3 - this->b3 * this->c2 * this->d1 - this->b2 * this->c1 * this->d3 - this->b1 * this->c3 * this->d2;
    float a1 = -(this->a2 * this->c3 * this->d1 + this->a3 * this->c1 * this->d2 + this->a1 * this->c2 * this->d3 - this->a3 * this->c2 * this->d1 - this->a2 * this->c1 * this->d3 - this->a1 * this->c3 * this->d2);
    float a2 = this->a1 * this->b2 * this->d3 + this->a2 * this->b3 * this->d1 + this->a3 * this->b1 * this->d2 - this->a3 * this->b2 * this->d1 - this->a2 * this->b1 * this->d3 - this->a1 * this->b3 * this->d2;
    float a3 = -(this->a2 * this->b3 * this->c1 + this->a3 * this->b1 * this->c2 + this->a1 * this->b2 * this->c3 - this->a3 * this->b2 * this->c1 - this->a2 * this->b1 * this->c3 - this->a1 * this->b3 * this->c2);

    float b0 = -(this->b3 * this->c0 * this->d2 + this->b0 * this->c2 * this->d3 + this->b2 * this->c3 * this->d0 - this->b3 * this->c2 * this->d0 - this->b2 * this->c0 * this->d3 - this->b0 * this->c3 * this->d2);
    float b1 = this->a2 * this->c3 * this->d0 + this->a3 * this->c0 * this->d2 + this->a0 * this->c2 * this->d3 - this->a3 * this->c2 * this->d0 - this->a2 * this->c0 * this->d3 - this->a0 * this->c3 * this->d2;
    float b2 = -(this->a2 * this->b3 * this->d0 + this->a3 * this->b0 * this->d2 + this->a0 * this->b2 * this->d3 - this->a3 * this->b2 * this->d0 - this->a2 * this->b0 * this->d3 - this->a0 * this->b3 * this->d2);
    float b3 = this->a2 * this->b3 * this->c0 + this->a3 * this->b0 * this->c2 + this->a0 * this->b2 * this->c3 - this->a3 * this->b2 * this->c0 - this->a2 * this->b0 * this->c3 - this->a0 * this->b3 * this->c2;

    float c0 = this->b1 * this->c3 * this->d0 + this->b3 * this->c0 * this->d1 + this->b0 * this->c1 * this->d3 - this->b3 * this->c1 * this->d0 - this->b1 * this->c0 * this->d3 - this->b0 * this->c3 * this->d1;
    float c1 = -(this->a1 * this->c3 * this->d0 + this->a3 * this->c0 * this->d1 + this->a0 * this->c1 * this->d3 - this->a3 * this->c1 * this->d0 - this->a1 * this->c0 * this->d3 - this->a0 * this->c3 * this->d1);
    float c2 = this->a1 * this->b3 * this->d0 + this->a3 * this->b0 * this->d1 + this->a0 * this->b1 * this->d3 - this->a3 * this->b1 * this->d0 - this->a1 * this->b0 * this->d3 - this->a0 * this->b3 * this->d1;
    float c3 = -(this->a1 * this->b3 * this->c0 + this->a3 * this->b0 * this->c1 + this->a0 * this->b1 * this->c3 - this->a3 * this->b1 * this->c0 - this->a1 * this->b0 * this->c3 - this->a0 * this->b3 * this->c1);

    float d0 = -(this->b2 * this->c0 * this->d1 + this->b0 * this->c1 * this->d2 + this->b1 * this->c2 * this->d0 - this->b2 * this->c1 * this->d0 - this->b1 * this->c0 * this->d2 - this->b0 * this->c2 * this->d1);
    float d1 = this->a1 * this->c2 * this->d0 + this->a2 * this->c0 * this->d1 + this->a0 * this->c1 * this->d2 - this->a2 * this->c1 * this->d0 - this->a1 * this->c0 * this->d2 - this->a0 * this->c2 * this->d1;
    float d2 = -(this->a1 * this->b2 * this->d0 + this->a2 * this->b0 * this->d1 + this->a0 * this->b1 * this->d2 - this->a2 * this->b1 * this->d0 - this->a1 * this->b0 * this->d2 - this->a0 * this->b2 * this->d1);
    float d3 = this->a0 * this->b1 * this->c2 + this->a1 * this->b2 * this->c0 + this->a2 * this->b0 * this->c1 - this->b1 * this->a2 * this->c0 - this->c2 * this->b0 * this->a1 - this->a0 * this->b2 * this->c1;

    return { a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3, d0, d1, d2, d3 };
}

C44Matrix C44Matrix::AffineInverse() const {
    auto matrix = C44Matrix(C33Matrix(*this).Transpose());
    matrix.Translate(C3Vector(-this->d0, -this->d1, -this->d2));

    return matrix;
}

C44Matrix C44Matrix::AffineInverse(float uniformScale) const {
    if (CMath::fequal(uniformScale, 1.0f)) {
        return this->AffineInverse();
    }

    auto matrix = C44Matrix(C33Matrix(*this).Transpose());
    matrix.Scale(1.0f / (uniformScale * uniformScale));
    matrix.Translate(C3Vector(-this->d0, -this->d1, -this->d2));

    return matrix;
}

float C44Matrix::Determinant() const {
    return (this->b1 * this->c2 * this->d3 + this->c3 * this->b2 * this->d1 + this->b3 * this->c1 * this->d2 - this->c2 * this->b3 * this->d1 - this->d3 * (this->c1 * this->b2) - this->b1 * this->c3 * this->d2) * this->a0 - (this->c2 * this->b0 * this->d3 + this->c3 * this->b2 * this->d0 + this->b3 * this->c0 * this->d2 - this->b3 * this->c2 * this->d0 - this->d3 * (this->c0 * this->b2) - this->b0 * this->c3 * this->d2) * this->a1 + (this->c1 * this->b0 * this->d3 + this->c3 * this->b1 * this->d0 + this->b3 * this->c0 * this->d1 - this->b3 * this->c1 * this->d0 - this->d3 * (this->c0 * this->b1) - this->b0 * this->c3 * this->d1) * this->a2 - (this->c1 * this->b0 * this->d2 + this->c2 * this->b1 * this->d0 + this->b2 * this->c0 * this->d1 - this->b2 * this->c1 * this->d0 - this->d2 * (this->c0 * this->b1) - this->b0 * this->c2 * this->d1) * this->a3;
}

void C44Matrix::Identity() {
    this->a0 = 1.0f;
    this->a1 = 0.0f;
    this->a2 = 0.0f;
    this->a3 = 0.0f;

    this->b0 = 0.0f;
    this->b1 = 1.0f;
    this->b2 = 0.0f;
    this->b3 = 0.0f;

    this->c0 = 0.0f;
    this->c1 = 0.0f;
    this->c2 = 1.0f;
    this->c3 = 0.0f;

    this->d0 = 0.0f;
    this->d1 = 0.0f;
    this->d2 = 0.0f;
    this->d3 = 1.0f;
}

C44Matrix C44Matrix::Inverse(float det) const {
    return this->Adjoint() * (1.0f / det);
}

void C44Matrix::RotateAroundZ(float angle) {
    *this = C44Matrix::RotationAroundZ(angle) * *this;
}

void C44Matrix::Scale(const C3Vector& scale) {
    this->a0 *= scale.x;
    this->a1 *= scale.x;
    this->a2 *= scale.x;

    this->b0 *= scale.y;
    this->b1 *= scale.y;
    this->b2 *= scale.y;

    this->c0 *= scale.z;
    this->c1 *= scale.z;
    this->c2 *= scale.z;
}

void C44Matrix::Scale(float scale) {
    this->a0 *= scale;
    this->a1 *= scale;
    this->a2 *= scale;

    this->b0 *= scale;
    this->b1 *= scale;
    this->b2 *= scale;

    this->c0 *= scale;
    this->c1 *= scale;
    this->c2 *= scale;
}

void C44Matrix::Translate(const C3Vector& move) {
    this->d0 = this->a0 * move.x + this->b0 * move.y + this->c0 * move.z + this->d0;
    this->d1 = this->a1 * move.x + this->b1 * move.y + this->c1 * move.z + this->d1;
    this->d2 = this->a2 * move.x + this->b2 * move.y + this->c2 * move.z + this->d2;
}

C44Matrix C44Matrix::Transpose() const {
    float a0 = this->a0;
    float a1 = this->a1;
    float a2 = this->a2;
    float a3 = this->a3;

    float b0 = this->b0;
    float b1 = this->b1;
    float b2 = this->b2;
    float b3 = this->b3;

    float c0 = this->c0;
    float c1 = this->c1;
    float c2 = this->c2;
    float c3 = this->c3;

    float d0 = this->d0;
    float d1 = this->d1;
    float d2 = this->d2;
    float d3 = this->d3;

    return { a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3 };
}

C44Matrix operator*(const C44Matrix& l, float a) {
    float a0 = l.a0 * a;
    float a1 = l.a1 * a;
    float a2 = l.a2 * a;
    float a3 = l.a3 * a;

    float b0 = l.b0 * a;
    float b1 = l.b1 * a;
    float b2 = l.b2 * a;
    float b3 = l.b3 * a;

    float c0 = l.c0 * a;
    float c1 = l.c1 * a;
    float c2 = l.c2 * a;
    float c3 = l.c3 * a;

    float d0 = l.d0 * a;
    float d1 = l.d1 * a;
    float d2 = l.d2 * a;
    float d3 = l.d3 * a;

    return { a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3, d0, d1, d2, d3 };
}

C44Matrix operator*(const C44Matrix& l, const C44Matrix& r) {
    float a0 = l.a0 * r.a0 + l.a1 * r.b0 + l.a2 * r.c0 + l.a3 * r.d0;
    float a1 = l.a0 * r.a1 + l.a1 * r.b1 + l.a2 * r.c1 + l.a3 * r.d1;
    float a2 = l.a0 * r.a2 + l.a1 * r.b2 + l.a2 * r.c2 + l.a3 * r.d2;
    float a3 = l.a0 * r.a3 + l.a1 * r.b3 + l.a2 * r.c3 + l.a3 * r.d3;

    float b0 = l.b0 * r.a0 + l.b1 * r.b0 + l.b2 * r.c0 + l.b3 * r.d0;
    float b1 = l.b0 * r.a1 + l.b1 * r.b1 + l.b2 * r.c1 + l.b3 * r.d1;
    float b2 = l.b0 * r.a2 + l.b1 * r.b2 + l.b2 * r.c2 + l.b3 * r.d2;
    float b3 = l.b0 * r.a3 + l.b1 * r.b3 + l.b2 * r.c3 + l.b3 * r.d3;

    float c0 = l.c0 * r.a0 + l.c1 * r.b0 + l.c2 * r.c0 + l.c3 * r.d0;
    float c1 = l.c0 * r.a1 + l.c1 * r.b1 + l.c2 * r.c1 + l.c3 * r.d1;
    float c2 = l.c0 * r.a2 + l.c1 * r.b2 + l.c2 * r.c2 + l.c3 * r.d2;
    float c3 = l.c0 * r.a3 + l.c1 * r.b3 + l.c2 * r.c3 + l.c3 * r.d3;

    float d0 = l.d0 * r.a0 + l.d1 * r.b0 + l.d2 * r.c0 + l.d3 * r.d0;
    float d1 = l.d0 * r.a1 + l.d1 * r.b1 + l.d2 * r.c1 + l.d3 * r.d1;
    float d2 = l.d0 * r.a2 + l.d1 * r.b2 + l.d2 * r.c2 + l.d3 * r.d2;
    float d3 = l.d0 * r.a3 + l.d1 * r.b3 + l.d2 * r.c3 + l.d3 * r.d3;

    return { a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3, d0, d1, d2, d3 };
}
