//
// Created by arzeo on 1/12/2021.
//

#ifndef VEC2_VEC2_HPP
#define VEC2_VEC2_HPP

#include <ostream>
#define _USE_MATH_DEFINES
#include <cmath>

template<class t>
class Vec2
{
    public:
    explicit Vec2(t x = 0, t y = 0): x(x), y(y){};

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &vec2)
    {
        os << "x: " << vec2.x << " y: " << vec2.y;
        return os;
    };

    bool operator==(const Vec2 &rhs) const
    {
        return x == rhs.x && y == rhs.y;
    };

    bool operator!=(const Vec2 &rhs) const
    {
        return rhs != *this;
    };

    bool operator<(const Vec2 &rhs) const
    {
        if (x < rhs.x && y < rhs.y)
            return true;
        else
            return false;
    };

    bool operator>(const Vec2 &rhs) const
    {
        return rhs < *this;
    };

    bool operator<=(const Vec2 &rhs) const
    {
        return rhs >= *this;
    };

    bool operator>=(const Vec2 &rhs) const
    {
        return *this >= rhs;
    };

    void operator+=(const Vec2 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
    };
    void operator/=(const Vec2 &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
    };
    void operator-=(const Vec2 &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    };
    void operator*=(const Vec2 &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
    };

    Vec2 operator+(const Vec2 &rhs) const
    {
        return Vec2<t>(x + rhs.y, x + rhs.y);
    };

    Vec2 operator-(const Vec2 &rhs) const
    {
        return Vec2<t>(x - rhs.y, x - rhs.y);
    };

    Vec2 operator*(const Vec2 &rhs) const
    {
        return Vec2<t>(x * rhs.y, x * rhs.y);
    };

    Vec2 operator/(const Vec2 &rhs) const
    {
        return Vec2<t>(x / rhs.y, x / rhs.y);
    };

    float dist(const Vec2 &rhs) const
    {
        return abs(sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2)));
    };

    float angle(const Vec2 &rhs) const
    {
        float tmp = atan2(rhs.y - y, rhs.x - x);
        tmp = tmp * 180 / 3.14159265358979323846;
        if (tmp < 0)
            tmp += 360;
        return tmp;
    };

    t x;
    t y;

};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;

#endif //VEC2_VEC2_HPP
