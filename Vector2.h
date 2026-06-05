#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))

#include <malloc.h>
#include <string>

#include "Vector.h"

class Vector2 : public Vector<2>
{
public:
    double &x = V0;
    double &y = V1;

    Vector2() : Vector<2>() {};

    Vector2(double data[2]) : Vector<2>()
    {
        V0 = data[0];
        V1 = data[1];
    };

    Vector2(double x, double y) : Vector<2>()
    {
        daten[0] = x;
        daten[1] = y;
    };

    inline Vector2 &replace(double x, double y)
    {
        V0 = x;
        V1 = y;
        return *this;
    };

    inline double magnitude()
    {
        return std::sqrt(V0 * V0 + V1 * V1);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    inline Vector2 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V0 /= mag;
        V1 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    inline Vector2 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector2(daten);
        return Vector2(V0 / mag, V1 / mag);
    };

    /*
     * ergibt den Kreuzprodukt von zwei Vektoren
     */
    inline double cross(Vector<2> &v)
    {
        return V0 * v.get(0) - V1 * v.get(1);
    }

    // skalar multiplikation

    inline Vector2 operator*(double k)
    {
        return Vector2((V0)*k, (V1)*k);
    };

    inline Vector2 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    inline Vector2 &add(double x, double y)
    {
        V0 += x;
        V1 += y;
        return *this;
    };

    inline Vector2 operator+(Vector<2> &a)
    {
        return Vector2(V0 + a.get(0),
                       V1 + a.get(1));
    };

    inline Vector2 &operator+=(Vector<2> &a)
    {
        V0 += a.get(0);
        V1 += a.get(1);
        return *this;
    };

    inline Vector2 operator-(Vector<2> &a)
    {
        return Vector2(V0 - a.get(0),
                       V1 - a.get(1));
    };

    inline Vector2 &operator-=(Vector<2> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        return *this;
    };

    // Vectorenmultiplikation

    inline double operator*(Vector<2> &v)
    {
        return V0 * v.get(0) + V1 * v.get(1);
    };

    // Vektorengleichung

    inline Vector2 &operator=(Vector2 &b)
    {
        V0 = b.x;
        V1 = b.y;
        return *this;
    };

    inline bool operator==(const Vector2 &b) const
    {
        return (V0 == b.x && V1 == b.y);
    };
};

#undef V0
#undef V1
