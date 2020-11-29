#include "tempest/matrix/C44Matrix.hpp"

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

    return C44Matrix(a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3, d0, d1, d2, d3);
}

float C44Matrix::Determinant() {
    return (this->b1 * this->c2 * this->d3 + this->c3 * this->b2 * this->d1 + this->b3 * this->c1 * this->d2 - this->c2 * this->b3 * this->d1 - this->d3 * (this->c1 * this->b2) - this->b1 * this->c3 * this->d2) * this->a0 - (this->c2 * this->b0 * this->d3 + this->c3 * this->b2 * this->d0 + this->b3 * this->c0 * this->d2 - this->b3 * this->c2 * this->d0 - this->d3 * (this->c0 * this->b2) - this->b0 * this->c3 * this->d2) * this->a1 + (this->c1 * this->b0 * this->d3 + this->c3 * this->b1 * this->d0 + this->b3 * this->c0 * this->d1 - this->b3 * this->c1 * this->d0 - this->d3 * (this->c0 * this->b1) - this->b0 * this->c3 * this->d1) * this->a2 - (this->c1 * this->b0 * this->d2 + this->c2 * this->b1 * this->d0 + this->b2 * this->c0 * this->d1 - this->b2 * this->c1 * this->d0 - this->d2 * (this->c0 * this->b1) - this->b0 * this->c2 * this->d1) * this->a3;
}
