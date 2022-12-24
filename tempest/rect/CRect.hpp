#ifndef TEMPEST_RECT_C_RECT_HPP
#define TEMPEST_RECT_C_RECT_HPP

class C2Vector;

class CRect {
    public:
    // Static functions
    static CRect Intersection(const CRect& l, const CRect& r);

    // Member variables
    float minY = 0.0f; // t
    float minX = 0.0f; // l
    float maxY = 0.0f; // b
    float maxX = 0.0f; // r

    // Member functions
    CRect() = default;
    CRect(float minY, float minX, float maxY, float maxX)
        : minY(minY)
        , minX(minX)
        , maxY(maxY)
        , maxX(maxX) {};
    bool operator==(const CRect& r);
    bool IsPointInside(const C2Vector& pt);
    bool Sub4826D0() const;
};

#endif
