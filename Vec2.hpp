//
// Created by arzeo on 1/12/2021.
//

#ifndef VEC2_VEC2_HPP
#define VEC2_VEC2_HPP

#include <ostream>
#define PI 3.14159265358979323846
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

    void operator+=(t nb)
    {
        x += nb;
        y += nb;
    };
    void operator-=(t nb)
    {
        x -= nb;
        y -= nb;
    };
    void operator*=(t nb)
    {
        x *= nb;
        y *= nb;
    };
    void operator/=(t nb)
    {
        x /= nb;
        y /= nb;
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

    Vec2 operator+(t nb) const
    {
        return Vec2<t>(x + nb, x + nb);
    };

    Vec2 operator-(t nb) const
    {
        return Vec2<t>(x - nb, x - nb);
    };

    Vec2 operator*(t nb) const
    {
        return Vec2<t>(x * nb, x * nb);
    };

    Vec2 operator/(t nb) const
    {
        return Vec2<t>(x / nb, x / nb);
    };

    float dist(const Vec2 &rhs) const
    {
        return abs(sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2)));
    };

    void rotateAround(const Vec2 &rhs, float radiant)
    {
        Vec2 cpy = rhs;
        Vec2 diff = this - rhs;
        float _cos = cos(radiant);
        float _sin = sin(radiant);
        x = cpy.x + diff.x * _cos - diff.y * _sin;
        y = cpy.x + diff.x * _sin + diff.y * _cos;
    }

    void GetCoordinaterotatedAround(const Vec2 &rhs, float radiant) const
    {
        Vec2 cpy = rhs;
        Vec2 diff = this - rhs;
        float _cos = cos(radiant);
        float _sin = sin(radiant);
        return cpy + Vec2(diff.x * _cos - diff.y * _sin, diff.x * _sin + diff.y * _cos);
    }

    Vec2 linearInterpolation(const Vec2 &rhs, t percent) // percent must be a value between 0 and 1
    {
        if (percent < 0 || percent > 1)
            return Vec2(0,0);
        return this + ((rhs - this) * percent);
    }

    float angle(const Vec2 &rhs) const
    {
        float tmp = atan2(rhs.y - y, rhs.x - x);
        tmp = tmp * 180 / PI;
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
