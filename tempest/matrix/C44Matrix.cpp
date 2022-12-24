#include "tempest/matrix/C44Matrix.hpp"
#include "tempest/Vector.hpp"
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

float C44Matrix::Determinant() const {
    return (this->b1 * this->c2 * this->d3 + this->c3 * this->b2 * this->d1 + this->b3 * this->c1 * this->d2 - this->c2 * this->b3 * this->d1 - this->d3 * (this->c1 * this->b2) - this->b1 * this->c3 * this->d2) * this->a0 - (this->c2 * this->b0 * this->d3 + this->c3 * this->b2 * this->d0 + this->b3 * this->c0 * this->d2 - this->b3 * this->c2 * this->d0 - this->d3 * (this->c0 * this->b2) - this->b0 * this->c3 * this->d2) * this->a1 + (this->c1 * this->b0 * this->d3 + this->c3 * this->b1 * this->d0 + this->b3 * this->c0 * this->d1 - this->b3 * this->c1 * this->d0 - this->d3 * (this->c0 * this->b1) - this->b0 * this->c3 * this->d1) * this->a2 - (this->c1 * this->b0 * this->d2 + this->c2 * this->b1 * this->d0 + this->b2 * this->c0 * this->d1 - this->b2 * this->c1 * this->d0 - this->d2 * (this->c0 * this->b1) - this->b0 * this->c2 * this->d1) * this->a3;
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
