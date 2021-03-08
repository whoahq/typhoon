#include "tempest/matrix/C34Matrix.hpp"

void C34Matrix::Translate(const C3Vector& move) {
    this->d0 = this->a0 * move.x + this->b0 * move.y + this->c0 * move.z + this->d0;
    this->d1 = this->a1 * move.x + this->b1 * move.y + this->c1 * move.z + this->d1;
    this->d2 = this->a2 * move.x + this->b2 * move.y + this->c2 * move.z + this->d2;
}

C34Matrix& C34Matrix::operator+=(const C34Matrix& a) {
    C34Matrix& l = *this;
    *this = l + a;
    return *this;
}

C34Matrix& C34Matrix::operator-=(const C34Matrix& a) {
    C34Matrix& l = *this;
    *this = l - a;
    return *this;
}

C34Matrix operator+(const C34Matrix& l, const C34Matrix& r) {
    float a0 = l.a0 + r.a0;
    float a1 = l.a1 + r.a1;
    float a2 = l.a2 + r.a2;

    float b0 = l.b0 + r.b0;
    float b1 = l.b1 + r.b1;
    float b2 = l.b2 + r.b2;

    float c0 = l.c0 + r.c0;
    float c1 = l.c1 + r.c1;
    float c2 = l.c2 + r.c2;

    float d0 = l.d0 + r.d0;
    float d1 = l.d1 + r.d1;
    float d2 = l.d2 + r.d2;

    return { a0, a1, a2, b0, b1, b2, c0, c1, c2, d0, d1, d2 };
}

C34Matrix operator-(const C34Matrix& l, const C34Matrix& r) {
    float a0 = l.a0 - r.a0;
    float a1 = l.a1 - r.a1;
    float a2 = l.a2 - r.a2;

    float b0 = l.b0 - r.b0;
    float b1 = l.b1 - r.b1;
    float b2 = l.b2 - r.b2;

    float c0 = l.c0 - r.c0;
    float c1 = l.c1 - r.c1;
    float c2 = l.c2 - r.c2;

    float d0 = l.d0 - r.d0;
    float d1 = l.d1 - r.d1;
    float d2 = l.d2 - r.d2;

    return { a0, a1, a2, b0, b1, b2, c0, c1, c2, d0, d1, d2 };
}

C34Matrix operator*(const C34Matrix& l, const C34Matrix& r) {
    float a0 = l.a0 * r.a0 + l.a1 * r.b0 + l.a2 * r.c0;
    float a1 = l.a0 * r.a1 + l.a1 * r.b1 + l.a2 * r.c1;
    float a2 = l.a0 * r.a2 + l.a1 * r.b2 + l.a2 * r.c2;

    float b0 = l.b0 * r.a0 + l.b1 * r.b0 + l.b2 * r.c0;
    float b1 = l.b0 * r.a1 + l.b1 * r.b1 + l.b2 * r.c1;
    float b2 = l.b0 * r.a2 + l.b1 * r.b2 + l.b2 * r.c2;

    float c0 = l.c0 * r.a0 + l.c1 * r.b0 + l.c2 * r.c0;
    float c1 = l.c0 * r.a1 + l.c1 * r.b1 + l.c2 * r.c1;
    float c2 = l.c0 * r.a2 + l.c1 * r.b2 + l.c2 * r.c2;

    float d0 = l.d0 * r.a0 + l.d1 * r.b0 + l.d2 * r.c0 + r.d0;
    float d1 = l.d0 * r.a1 + l.d1 * r.b1 + l.d2 * r.c1 + r.d1;
    float d2 = l.d0 * r.a2 + l.d1 * r.b2 + l.d2 * r.c2 + r.d2;

    return { a0, a1, a2, b0, b1, b2, c0, c1, c2, d0, d1, d2 };
}

C34Matrix operator*(const C34Matrix& l, float a) {
    float a0 = l.a0 * a;
    float a1 = l.a1 * a;
    float a2 = l.a2 * a;

    float b0 = l.b0 * a;
    float b1 = l.b1 * a;
    float b2 = l.b2 * a;

    float c0 = l.c0 * a;
    float c1 = l.c1 * a;
    float c2 = l.c2 * a;

    float d0 = l.d0 * a;
    float d1 = l.d1 * a;
    float d2 = l.d2 * a;

    return { a0, a1, a2, b0, b1, b2, c0, c1, c2, d0, d1, d2 };
}

C3Vector operator*(const C34Matrix& l, const C3Vector& r) {
    float x = l.a0 * r.x + l.a1 * r.y + l.a2 * r.z;
    float y = l.b0 * r.x + l.b1 * r.y + l.b2 * r.z;
    float z = l.c0 * r.x + l.c1 * r.y + l.c2 * r.z;
    return { x, y, z };
}
