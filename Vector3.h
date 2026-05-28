#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))
#define V2 (*(daten + 2))

#include <malloc.h>
#include <string>

#include "Vector.h"

class Vector3 : public Vector<3>
{
public:
    Vector3(double data[3]) : Vector<3>(data) {
                              };

    Vector3(double x, double y, double z) : Vector<3>() {
        daten[0] = x;
        daten[1] = y;
        daten[2] = z;
    };

    inline double magnitude()
    {
        return std::sqrt(V0 * V0 + V1 * V1 + V2 * V2);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    inline Vector3 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V0 /= mag;
        V1 /= mag;
        V2 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    inline Vector3 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector3(daten);
        double normalizierteDaten[3] = {
            V0 / mag,
            V1 / mag,
            V2 / mag};
        Vector3 v = Vector3(normalizierteDaten);
        return v;
    };

    /*
    * ergibt den Kreuzprodukt von zwei Vektoren
    */
   inline Vector3 cross(Vector<3>& v) {
    double data[3] = {
        V1 * v.get(2) - V2 * v.get(1),
        -(V0 * v.get(2) - V2 * v.get(0)),
        V0 * v.get(1) - V1 * v.get(0)
    };
    return Vector3(data);
   }

    // skalar multiplikation

    inline Vector3 operator*(double k)
    {
        double data[3] = {
            V0 * k, V1 * k, V2 * k};
        return Vector3(data);
    };

    inline Vector3 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        V2 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    inline Vector3 operator+(Vector<3> &a)
    {
        double data[3] = {
            V0 + a.get(0), V1 + a.get(1), V2 + a.get(2)};
        return Vector3(data);
    };

    inline Vector3 &operator+=(Vector<3> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        return *this;
    };

    inline Vector3 operator-(Vector<3> &a)
    {
        double data[3] = {
            V0 - a.get(0), V1 - a.get(1), V2 - a.get(2)};
        return Vector3(data);
    };

    inline Vector3 &operator-=(Vector<3> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        return *this;
    };

    // Vectorenmultiplikation

    inline double operator*(Vector<3> &v)
    {
        return V0 * v.get(0) + V1 * v.get(1) + V2 * v.get(2);
    };
};

#undef V0
#undef V1
#undef V2
