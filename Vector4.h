#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))
#define V2 (*(daten + 2))
#define V3 (*(daten + 3))

#include <malloc.h>
#include <string>

#include "Vector.h"

class Vector4 : public Vector<4>
{
public:
    double &x = V0;
    double &y = V1;
    double &z = V2;
    double &w = V3;

    Vector4() : Vector<4>() {};
    Vector4(double data[4]) : Vector<4>(), x(data[0]), y(data[1]), z(data[2]), w(data[3]) {};
    Vector4(double x, double y, double z, double w) : Vector<4>(), x(x), y(y), z(z), w(w) {};

    inline Vector4 &replace(double x, double y, double z, double w)
    {
        V0 = x;
        V1 = y;
        V2 = z;
        V3 = w;
        return *this;
    };

    inline double magnitude()
    {
        return std::sqrt(V0 * V0 + V1 * V1 + V2 * V2 + V3 * V3);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    inline Vector4 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V0 /= mag;
        V1 /= mag;
        V2 /= mag;
        V3 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    inline Vector4 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector4(daten);
        return Vector4(V0 / mag,
                       V1 / mag,
                       V2 / mag,
                       V3 / mag);
    };

    // skalar multiplikation

    inline Vector4 operator*(double k)
    {
        return Vector4(V0 * k,
                       V1 * k,
                       V2 * k,
                       V3 * k);
    };

    inline Vector4 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        V2 *= k;
        V3 *= k;
        return *this;
    };

    // skalar division

    inline Vector4 operator/(double k)
    {
        return Vector4(V0 / k,
                       V1 / k,
                       V2 / k,
                       V3 / k);
    };

    inline Vector4 &operator/=(double k)
    {
        V0 /= k;
        V1 /= k;
        V2 /= k;
        V3 /= k;
        return *this;
    };

    // mathematik addition/subtraktion

    inline Vector4 &add(double x, double y, double z, double w)
    {
        V0 += x;
        V1 += y;
        V2 += z;
        V3 += w;
        return *this;
    };

    inline Vector4 operator+(Vector<4> &a)
    {
        return Vector4(V0 + a.get(0),
                       V1 + a.get(1),
                       V2 + a.get(2),
                       V3 + a.get(3));
    };

    inline Vector4 &operator+=(Vector<4> &a)
    {
        V0 += a.get(0);
        V1 += a.get(1);
        V2 += a.get(2);
        V3 += a.get(3);
        return *this;
    };

    inline Vector4 operator-(Vector<4> &a)
    {
        return Vector4(V0 - a.get(0),
                       V1 - a.get(1),
                       V2 - a.get(2),
                       V3 - a.get(3));
    };

    inline Vector4 &operator-=(Vector<4> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        V3 -= a.get(3);
        return *this;
    };

    // Vectorenmultiplikation

    inline double operator*(Vector<4> &v)
    {
        return V0 * v.get(0) + V1 * v.get(1) + V2 * v.get(2) + V3 * v.get(3);
    };

    // Vektorengleichung

    inline Vector4 &operator=(Vector4 &b)
    {
        V0 = b.x;
        V1 = b.y;
        V2 = b.z;
        V3 = b.w;
        return *this;
    };

    inline bool operator==(const Vector4 &b) const
    {
        return (V0 == b.x && V1 == b.y && V2 == b.z && V3 == b.w);
    };
};

#undef V0
#undef V1
#undef V2
#undef V3
