#pragma once

#define V1 (*(daten))
#define V2 (*(daten + 1))

#include <malloc.h>
#include <cstring>

#include "Vector.h"

class Vector2 : public Vector<2>
{
public:
    Vector2(double data[2]) : Vector<2>(data) {
                              };

    inline double magnitude()
    {
        return std::sqrt(V1 * V1 + V2 * V2);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector2 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V1 /= mag;
        V2 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    Vector2 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector2(daten);
        double normalizierteDaten[3] = {
            V1 / mag,
            V2 / mag};
        Vector2 v = Vector2(normalizierteDaten);
        return v;
    };

    // skalar multiplikation

    Vector2 operator*(double k)
    {
        double data[2] = {
            (V1)*k, (V2)*k};
        return Vector2(data);
    };

    Vector2 &operator*=(double k)
    {
        V1 *= k;
        V2 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector2 operator+(Vector<2> &a)
    {
        double data[2] = {
            V1 + a.get(0), V2 + a.get(1)};
        return Vector2(data);
    };

    Vector2 &operator+=(Vector<2> &a)
    {
        V1 += a.get(0);
        V2 += a.get(1);
        return *this;
    };

    Vector2 operator-(Vector<2> &a)
    {
        double data[2] = {
            V1 - a.get(0),
            V2 - a.get(1)};
        return Vector2(data);
    };

    Vector2 &operator-=(Vector<2> &a)
    {
        V1 -= a.get(0);
        V2 -= a.get(1);
        return *this;
    };

    // Vectorenmultiplikation

    Vector2 operator*(Vector<2> &v)
    {
        double neueDaten[2] = {
            V1 * v.get(0),
            V2 * v.get(1)};
        return Vector2(neueDaten);
    };

    Vector2 &operator*=(Vector<2> &v)
    {
        V1 *= v.get(0);
        V2 *= v.get(1);
        return *this;
    };
};

#undef V1
#undef V2
