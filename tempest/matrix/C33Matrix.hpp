#ifndef TEMPEST_MATRIX_C_33MATRIX_HPP
#define TEMPEST_MATRIX_C_33MATRIX_HPP

class C3Vector;
class C44Matrix;

class C33Matrix {
    public:
    // Static functions
    static C33Matrix Rotation(float angle, const C3Vector& axis, bool isNormalized);
    static C33Matrix RotationAroundZ(float angle);

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
    void FromEulerAnglesZYX(float yaw, float pitch, float roll);
    void Rotate(float angle, const C3Vector& axis, bool isNormalized);
    C33Matrix Transpose() const;
};

C33Matrix operator*(const C33Matrix& l, const C33Matrix& r);

#endif
