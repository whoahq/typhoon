#ifndef TEMPEST_MATRIX_C_33MATRIX_HPP
#define TEMPEST_MATRIX_C_33MATRIX_HPP

class C44Matrix;

class C33Matrix {
    public:
    // Member variables
    float a0;
    float a1;
    float a2;
    float b0;
    float b1;
    float b2;
    float c0;
    float c1;
    float c2;

    // Member functions
    C33Matrix();
    C33Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2);
    C33Matrix(const C44Matrix& m);
    C33Matrix Transpose() const;
};

#endif
