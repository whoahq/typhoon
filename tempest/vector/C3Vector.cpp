#include "tempest/vector/C3Vector.hpp"
#include "tempest/Math.hpp"

C3Vector& C3Vector::operator*=(float a) {
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
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

bool operator!=(const C3Vector& l, const C3Vector& r) {
    return l.x != r.x || l.y != r.y || l.z != r.z;
}
