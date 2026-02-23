#ifndef TEMPEST_MATRIX_C_44MATRIX_HPP
#define TEMPEST_MATRIX_C_44MATRIX_HPP

class C33Matrix;
class C3Vector;
class C4Quaternion;
class C4Vector;

class C44Matrix {
    public:
    // Static functions
    static C44Matrix RotationAroundZ(float angle);

    // Member variables
    float a0;
    float a1;
    float a2;
    float a3;
    float b0;
    float b1;
    float b2;
    float b3;
    float c0;
    float c1;
    float c2;
    float c3;
    float d0;
    float d1;
    float d2;
    float d3;

    // Member functions
    C44Matrix();
    C44Matrix(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3);
    C44Matrix(const C33Matrix& m);
    C44Matrix(const C4Quaternion& rotation);
    C44Matrix Adjoint() const;
    C44Matrix AffineInverse() const;
    C44Matrix AffineInverse(float uniformScale) const;
    C4Vector Col0() const;
    C4Vector Col1() const;
    C4Vector Col2() const;
    C4Vector Col3() const;
    float Determinant() const;
    void Identity();
    C44Matrix Inverse(float det) const;
    void Rotate(const C4Quaternion& rotation);
    void RotateAroundZ(float angle);
    C4Vector Row0() const;
    const C3Vector* Row0AsVec3() const;
    C4Vector Row1() const;
    const C3Vector* Row1AsVec3() const;
    C4Vector Row2() const;
    const C3Vector* Row2AsVec3() const;
    C4Vector Row3() const;
    const C3Vector* Row3AsVec3() const;
    void Scale(const C3Vector& scale);
    void Scale(float scale);
    void Translate(const C3Vector& move);
    C44Matrix Transpose() const;
};

C44Matrix operator*(const C44Matrix& l, float a);

C44Matrix operator*(const C44Matrix& l, const C44Matrix& r);

#endif
