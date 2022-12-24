#include "tempest/vector/C2Vector.hpp"

bool C2Vector::operator==(const C2Vector& v) {
    return this->x == v.x && this->y == v.y;
}
