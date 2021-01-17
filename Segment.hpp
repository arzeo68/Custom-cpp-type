//
// Created by arzeo on 1/17/2021.
//

#ifndef VEC2_SEGMENT_HPP
#define VEC2_SEGMENT_HPP

#include <ostream>
#include "Vec2.hpp"

template<class T>
class Segment
{
    public:
    Segment(Vec2<T> &A, Vec2<T> &B): _a(A), _b(B){};
    Segment(Vec2<T> A, Vec2<T> B): _a(A), _b(B){};
    Segment()
    {
        _a = Vec2<T>(0,0);
        _b = Vec2<T>(0,0);
    };

    friend std::ostream &operator<<(std::ostream &os, const Segment &segment)
    {
        os << "A: " << "{"  << segment._a.x << ", " << segment._a.y<< "}" << "  B: " << "{"  << segment._b.x << ", " << segment._b.y<< "}";
        return os;
    }

//    Vec2<T> linearInterpolation(T percent)  // todo FIXME issue with template
//    {
//        if (percent < 0 || percent > 1)
//            return Vec2<T>(0,0);
//        return _a + (percent * (_b - _a));
//    }

    float length() const
    {
        return _a.dist(_b);
    }

    const Vec2<T> &getA() const
    {
        return _a;
    }

    bool operator<(const Segment &rhs) const
    {
        if (_a < rhs._a)
            return true;
        if (rhs._a < _a)
            return false;
        return _b < rhs._b;
    }

    bool operator>(const Segment &rhs) const
    {
        return rhs < *this;
    }

    bool operator<=(const Segment &rhs) const
    {
        if (_a <= rhs._a)
            return true;
        if (rhs._a <= _a)
            return false;
        return _b <= rhs._b;
    }

    bool operator>=(const Segment &rhs) const
    {
        return *this >= rhs;
    }

    void setA(const Vec2<T> &a)
    {
        _a = a;
    }

    const Vec2<T> &getB() const
    {
        return _b;
    }

    void setB(const Vec2<T> &b)
    {
        _b = b;
    }

    bool operator==(const Segment &rhs) const
    {
        return _a == rhs._a && _b == rhs._b;
    }

    bool operator!=(const Segment &rhs) const
    {
        return _a != rhs._a || _b != rhs._b;
    }

    private:
        Vec2<T> _a;
        Vec2<T> _b;
};

#endif //VEC2_SEGMENT_HPP
