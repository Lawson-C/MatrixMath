#pragma once

#include <malloc.h>
#include <cstring>

#include "Vector.h"

class Vector4 : public Vector<4>
{
public:
    Vector4(double data[4]) : Vector<4>(data) {
                              };

    double magnitude()
    {
        return std::sqrt(*(daten) * *(daten) + *(daten + 1) * *(daten + 1) + *(daten + 2) * *(daten + 2) + *(daten + 3) * *(daten + 3));
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector4 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        *(daten) /= mag;
        *(daten + 1) /= mag;
        *(daten + 2) /= mag;
        *(daten + 3) /= mag;
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
            *(daten) / mag,
            *(daten + 1) / mag,
            *(daten + 2) / mag,
            *(daten + 3) / mag};
        Vector4 v = Vector4(normalizierteDaten);
        return v;
    };

    // skalar multiplikation

    Vector4 operator*(double k)
    {
        double data[4] = {
            *(daten)*k, *(daten + 1) * k, *(daten + 2) * k, *(daten + 3) * k};
        return Vector4(data);
    };

    Vector4 &operator*=(double k)
    {
        *(daten) *= k;
        *(daten + 1) *= k;
        *(daten + 2) *= k;
        *(daten + 3) *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector4 operator+(Vector<4> &a)
    {
        double data[4] = {
            *(daten) + a.get(0),
            *(daten + 1) + a.get(1),
            *(daten + 2) + a.get(2),
            *(daten + 3) + a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator+=(Vector<4> &a)
    {
        *(daten) += a.get(0);
        *(daten + 1) += a.get(1);
        *(daten + 2) += a.get(2);
        *(daten + 3) += a.get(3);
        return *this;
    };

    Vector4 operator-(Vector<4> &a)
    {
        double data[4] = {
            *(daten)-a.get(0),
            *(daten + 1) - a.get(1),
            *(daten + 2) - a.get(2),
            *(daten + 3) - a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator-=(Vector<4> &a)
    {
        *(daten) -= a.get(0);
        *(daten + 1) -= a.get(1);
        *(daten + 2) -= a.get(2);
        *(daten + 3) -= a.get(3);
        return *this;
    };

    // Vectorenmultiplikation

    Vector4 operator*(Vector<4> &v)
    {
        double neueDaten[4] = {
            *(daten)*v.get(0),
            *(daten + 1) * v.get(1),
            *(daten + 2) * v.get(2),
            *(daten + 3) * v.get(3)};
        return Vector4(neueDaten);
    };

    Vector4 &operator*=(Vector<4> &v)
    {
        *(daten) *= v.get(0);
        *(daten + 1) *= v.get(1);
        *(daten + 2) *= v.get(2);
        *(daten + 3) *= v.get(3);
        return *this;
    };
};