#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))

#include <malloc.h>
#include <string>

#include "Vector.h"

class Vector2 : public Vector<2>
{
public:
    Vector2() : Vector<2>() {};

    Vector2(double data[2]) : Vector<2>(data) {};

    Vector2(double x, double y) : Vector<2>()
    {
        daten[0] = x;
        daten[1] = y;
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
        double normalizierteDaten[3] = {
            V0 / mag,
            V1 / mag};
        Vector2 v = Vector2(normalizierteDaten);
        return v;
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
        double data[2] = {
            (V0)*k, (V1)*k};
        return Vector2(data);
    };

    inline Vector2 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    inline Vector2 operator+(Vector<2> &a)
    {
        double data[2] = {
            V0 + a.get(0), V1 + a.get(1)};
        return Vector2(data);
    };

    inline Vector2 &operator+=(Vector<2> &a)
    {
        V0 += a.get(0);
        V1 += a.get(1);
        return *this;
    };

    inline Vector2 operator-(Vector<2> &a)
    {
        double data[2] = {
            V0 - a.get(0),
            V1 - a.get(1)};
        return Vector2(data);
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
};

#undef V0
#undef V1
