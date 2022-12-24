#ifndef TEMPEST_MATRIX_C_44MATRIX_HPP
#define TEMPEST_MATRIX_C_44MATRIX_HPP

class C3Vector;

class C44Matrix {
    public:
    // Static functions
    static C44Matrix RotationAroundZ(float angle);

    // Member variables
    float a0 = 1.0f;
    float a1 = 0.0f;
    float a2 = 0.0f;
    float a3 = 0.0f;
    float b0 = 0.0f;
    float b1 = 1.0f;
    float b2 = 0.0f;
    float b3 = 0.0f;
    float c0 = 0.0f;
    float c1 = 0.0f;
    float c2 = 1.0f;
    float c3 = 0.0f;
    float d0 = 0.0f;
    float d1 = 0.0f;
    float d2 = 0.0f;
    float d3 = 1.0f;

    // Member functions
    C44Matrix() = default;
    C44Matrix(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3)
        : a0(a0)
        , a1(a1)
        , a2(a2)
        , a3(a3)
        , b0(b0)
        , b1(b1)
        , b2(b2)
        , b3(b3)
        , c0(c0)
        , c1(c1)
        , c2(c2)
        , c3(c3)
        , d0(d0)
        , d1(d1)
        , d2(d2)
        , d3(d3) {};
    C44Matrix Adjoint() const;
    float Determinant() const;
    C44Matrix Inverse(float det) const;
    void RotateAroundZ(float angle);
    void Scale(const C3Vector& scale);
    void Scale(float scale);
    void Translate(const C3Vector& move);
};

C44Matrix operator*(const C44Matrix& l, float a);

C44Matrix operator*(const C44Matrix& l, const C44Matrix& r);

#endif
