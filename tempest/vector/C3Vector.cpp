#include "tempest/vector/C3Vector.hpp"
#include "tempest/Math.hpp"
#include "tempest/Matrix.hpp"

C3Vector C3Vector::operator-() const {
    return { -this->x, -this->y, -this->z };
}

C3Vector& C3Vector::operator*=(float a) {
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
}

C3Vector C3Vector::Cross(const C3Vector& l, const C3Vector& r) {
    return {
        (l.y * r.z) - (l.z * r.y),
        (l.z * r.x) - (l.x * r.z),
        (l.x * r.y) - (l.y * r.x)
    };
}

float C3Vector::Mag() const {
    return CMath::sqrt(this->SquaredMag());
}

void C3Vector::Normalize() {
    this->operator*=(1.0f / this->Mag());
}

float C3Vector::SquaredMag() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}

C3Vector operator+(const C3Vector& l, const C3Vector& r) {
    float x = l.x + r.x;
    float y = l.y + r.y;
    float z = l.z + r.z;

    return { x, y, z };
}

C3Vector operator*(const C3Vector& l, const C44Matrix& r) {
    float x = r.c0 * l.z + r.b0 * l.y + r.a0 * l.x + r.d0;
    float y = r.c1 * l.z + r.b1 * l.y + r.a1 * l.x + r.d1;
    float z = r.c2 * l.z + r.b2 * l.y + r.a2 * l.x + r.d2;

    return { x, y, z };
}

bool operator!=(const C3Vector& l, const C3Vector& r) {
    return l.x != r.x || l.y != r.y || l.z != r.z;
}
