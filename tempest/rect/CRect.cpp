#include "tempest/rect/CRect.hpp"
#include "tempest/Vector.hpp"

CRect CRect::Intersection(const CRect& l, const CRect& r) {
    CRect i;

    i.maxX = r.maxX <= l.maxX ? r.maxX : l.maxX;
    i.maxY = r.maxY <= l.maxY ? r.maxY : l.maxY;
    i.minX = r.minX >= l.minX ? r.minX : l.minX;
    i.minY = r.minY >= l.minY ? r.minY : l.minY;

    return i;
}

bool CRect::operator==(const CRect& rect) {
    return this->minX == rect.minX && this->minY == rect.minY && this->maxX == rect.maxX && this->maxY == rect.maxY;
}

bool CRect::IsPointInside(const C2Vector& pt) {
    return this->minX <= pt.x && this->maxX >= pt.x && this->minY <= pt.y && this->maxY >= pt.y;
}

bool CRect::Sub4826D0() const {
    return this->maxY < 0.0f || this->minY > 1.0f || this->maxX < 0.0f || this->minX > 1.0f;
}
