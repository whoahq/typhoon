#include "tempest/vector/C3Vector.hpp"

C3Vector& C3Vector::operator*=(float a) {
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
}

float C3Vector::SquaredMag() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}
