#include "tempest/matrix/C33Matrix.hpp"
#include "tempest/math/CMath.hpp"
#include "tempest/matrix/C44Matrix.hpp"

C33Matrix::C33Matrix() {
    this->a0 = 1.0f;
    this->a1 = 0.0f;
    this->a2 = 0.0f;

    this->b0 = 0.0f;
    this->b1 = 1.0f;
    this->b2 = 0.0f;

    this->c0 = 0.0f;
    this->c1 = 0.0f;
    this->c2 = 1.0f;
}

C33Matrix::C33Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2) {
    this->a0 = a0;
    this->a1 = a1;
    this->a2 = a2;

    this->b0 = b0;
    this->b1 = b1;
    this->b2 = b2;

    this->c0 = c0;
    this->c1 = c1;
    this->c2 = c2;
}

C33Matrix::C33Matrix(const C44Matrix& m) {
    this->a0 = m.a0;
    this->a1 = m.a1;
    this->a2 = m.a2;

    this->b0 = m.b0;
    this->b1 = m.b1;
    this->b2 = m.b2;

    this->c0 = m.c0;
    this->c1 = m.c1;
    this->c2 = m.c2;
}

void C33Matrix::FromEulerAnglesZYX(float yaw, float pitch, float roll) {
    float cos_ = CMath::cos(yaw);
    float sin_ = CMath::sin(yaw);

    auto z = C33Matrix(
        cos_, -sin_, 0.0f,
        sin_,  cos_, 0.0f,
        0.0f,  0.0f, 1.0f
    );

    cos_ = CMath::cos(pitch);
    sin_ = CMath::sin(pitch);

    auto y = C33Matrix(
         cos_, 0.0f, sin_,
         0.0f, 1.0f, 0.0f,
        -sin_, 0.0f, cos_
    );

    cos_ = CMath::cos(roll);
    sin_ = CMath::sin(roll);

    auto x = C33Matrix(
        1.0f, 0.0f, 0.0f,
        0.0f, cos_, -sin_,
        0.0f, sin_,  cos_
    );

    *this = (z * (y * x)).Transpose();
}

C33Matrix C33Matrix::Transpose() const {
    return {
        this->a0, this->b0, this->c0,
        this->a1, this->b1, this->c1,
        this->a2, this->b2, this->c2
    };
}

C33Matrix operator*(const C33Matrix& l, const C33Matrix& r) {
    float a0 = l.a0 * r.a0 + l.a1 * r.b0 + l.a2 * r.c0;
    float a1 = l.a0 * r.a1 + l.a1 * r.b1 + l.a2 * r.c1;
    float a2 = l.a0 * r.a2 + l.a1 * r.b2 + l.a2 * r.c2;

    float b0 = l.b0 * r.a0 + l.b1 * r.b0 + l.b2 * r.c0;
    float b1 = l.b0 * r.a1 + l.b1 * r.b1 + l.b2 * r.c1;
    float b2 = l.b0 * r.a2 + l.b1 * r.b2 + l.b2 * r.c2;

    float c0 = l.c0 * r.a0 + l.c1 * r.b0 + l.c2 * r.c0;
    float c1 = l.c0 * r.a1 + l.c1 * r.b1 + l.c2 * r.c1;
    float c2 = l.c0 * r.a2 + l.c1 * r.b2 + l.c2 * r.c2;

    return { a0, a1, a2, b0, b1, b2, c0, c1, c2 };
}
