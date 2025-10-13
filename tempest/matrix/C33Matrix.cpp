#include "tempest/matrix/C33Matrix.hpp"
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

C33Matrix C33Matrix::Transpose() const {
    return {
        this->a0, this->b0, this->c0,
        this->a1, this->b1, this->c1,
        this->a2, this->b2, this->c2
    };
}
