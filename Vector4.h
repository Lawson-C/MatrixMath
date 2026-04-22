#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))
#define V2 (*(daten + 2))
#define V3 (*(daten + 3))

#include <malloc.h>
#include <cstring>

#include "Vector.h"

class Vector4 : public Vector<4>
{
public:
    Vector4(double data[4]) : Vector<4>(data) {
                              };

    inline double magnitude()
    {
        return std::sqrt(V0 * V0 + V1 * V1 + V2 * V2 + V3 * V3);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector4 &normalize()
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
    Vector4 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector4(daten);
        double normalizierteDaten[4] = {
            V0 / mag,
            V1 / mag,
            V2 / mag,
            V3 / mag};
        Vector4 v = Vector4(normalizierteDaten);
        return v;
    };

    /*
     * ersetzt jeden Wert mit f(Wert) und ergibt den Vektor
     */
    template <typename Function>
    Vector4 &map(Function f) {
        V0 = f(V0);
        V1 = f(V1);
        V2 = f(V2);
        V3 = f(V3);
        return *this;
    };

    template <typename Function>
    Vector4 map(Function f)
    {
        double data[4] = {f(V0),
                          f(V1),
                          f(V2),
                          f(V3)};
        return Vector4(data);
    };

    // skalar multiplikation

    Vector4 operator*(double k)
    {
        double data[4] = {
            V0 * k, V1 * k, V2 * k, V3 * k};
        return Vector4(data);
    };

    Vector4 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        V2 *= k;
        V3 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector4 operator+(Vector<4> &a)
    {
        double data[4] = {
            V0 + a.get(0),
            V1 + a.get(1),
            V2 + a.get(2),
            V3 + a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator+=(Vector<4> &a)
    {
        V0 += a.get(0);
        V1 += a.get(1);
        V2 += a.get(2);
        V3 += a.get(3);
        return *this;
    };

    Vector4 operator-(Vector<4> &a)
    {
        double data[4] = {
            V0 - a.get(0),
            V1 - a.get(1),
            V2 - a.get(2),
            V3 - a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator-=(Vector<4> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        V3 -= a.get(3);
        return *this;
    };

    // Vectorenmultiplikation

    Vector4 operator*(Vector<4> &v)
    {
        double neueDaten[4] = {
            V0 * v.get(0),
            V1 * v.get(1),
            V2 * v.get(2),
            V3 * v.get(3)};
        return Vector4(neueDaten);
    };

    Vector4 &operator*=(Vector<4> &v)
    {
        V0 *= v.get(0);
        V1 *= v.get(1);
        V2 *= v.get(2);
        V3 *= v.get(3);
        return *this;
    };
};

#undef V0
#undef V1
#undef V2
#undef V3
