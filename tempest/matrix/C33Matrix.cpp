#include "tempest/matrix/C33Matrix.hpp"

C33Matrix C33Matrix::Transpose() const {
    return {
        a0, b0, c0,
        a1, b1, c1,
        a2, b2, c2
    };
}
