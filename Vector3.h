#pragma once

#define V1 (*(daten))
#define V2 (*(daten + 1))
#define V3 (*(daten + 2))

#include <malloc.h>
#include <cstring>

#include "Vector.h"

class Vector3 : public Vector<3>
{
public:
    Vector3(double data[3]) : Vector<3>(data) {
                              };

    double magnitude()
    {
        return std::sqrt(V1 * V1 + V2 * V2 + V3 * V3);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector3 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V1 /= mag;
        V2 /= mag;
        V3 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    Vector3 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector3(daten);
        double normalizierteDaten[3] = {
            V1 / mag,
            V2 / mag,
            V3 / mag};
        Vector3 v = Vector3(normalizierteDaten);
        return v;
    };

    /*
    * ergibt den Kreuzprodukt von zwei Vektoren
    */
   Vector3 cross(Vector<3>& v) {
    double data[3] = {
        V2 * v.get(2) - V3 * v.get(1),
        -(V1 * v.get(2) - V3 * v.get(0)),
        V1 * v.get(1) - V2 * v.get(0)
    };
    return Vector3(data);
   }

    // skalar multiplikation

    Vector3 operator*(double k)
    {
        double data[3] = {
            V1 * k, V2 * k, V3 * k};
        return Vector3(data);
    };

    Vector3 &operator*=(double k)
    {
        V1 *= k;
        V2 *= k;
        V3 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector3 operator+(Vector<3> &a)
    {
        double data[3] = {
            V1 + a.get(0), V2 + a.get(1), V3 + a.get(2)};
        return Vector3(data);
    };

    Vector3 &operator+=(Vector<3> &a)
    {
        V1 -= a.get(0);
        V2 -= a.get(1);
        V3 -= a.get(2);
        return *this;
    };

    Vector3 operator-(Vector<3> &a)
    {
        double data[3] = {
            V1 - a.get(0), V2 - a.get(1), V3 - a.get(2)};
        return Vector3(data);
    };

    Vector3 &operator-=(Vector<3> &a)
    {
        V1 -= a.get(0);
        V2 -= a.get(1);
        V3 -= a.get(2);
        return *this;
    };

    // Vectorenmultiplikation

    Vector3 operator*(Vector<3> &v)
    {
        double neueDaten[3] = {
            V1 * v.get(0),
            V2 * v.get(1),
            V3 * v.get(2)};
        return Vector3(neueDaten);
    };

    Vector3 &operator*=(Vector<3> &v)
    {
        V1 *= v.get(0);
        V2 *= v.get(1);
        V3 *= v.get(2);
        return *this;
    };
};

#undef V1
#undef V2
#undef V3
