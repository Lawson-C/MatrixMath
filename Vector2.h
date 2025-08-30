#pragma once

#include <malloc.h>
#include <cstring>

#include "Vector.h"

class Vector2 : public Vector<2>
{
public:
    Vector2(double data[2]) : Vector<2>(data) {
                              };

    double magnitude()
    {
        return std::sqrt(*(daten) * *(daten) + *(daten + 1) * *(daten + 1));
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector2 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        *(daten) /= mag;
        *(daten + 1) /= mag;
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
            *(daten) / mag,
            *(daten + 1) / mag,
            *(daten + 2) / mag};
        Vector2 v = Vector2(normalizierteDaten);
        return v;
    };

    // skalar multiplikation

    Vector2 operator*(double k)
    {
        double data[2] = {
            (*daten) * k, (*(daten + 1)) * k};
        return Vector2(data);
    };

    Vector2 &operator*=(double k)
    {
        *(daten) *= k;
        *(daten + 1) *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector2 operator+(Vector<2> &a)
    {
        double data[2] = {
            *(daten) + a.get(0), *(daten + 1) + a.get(1)};
        return Vector2(data);
    };

    Vector2 &operator+=(Vector<2> &a)
    {
        *(daten) += a.get(0);
        *(daten + 1) += a.get(1);
        return *this;
    };

    Vector2 operator-(Vector<2> &a)
    {
        double data[2] = {
            *(daten)-a.get(0), *(daten + 1) - a.get(1)};
        return Vector2(data);
    };

    Vector2 &operator-=(Vector<2> &a)
    {
        *(daten) -= a.get(0);
        *(daten + 1) -= a.get(1);
        return *this;
    };

    // Vectorenmultiplikation

    Vector2 operator*(Vector<2> &v)
    {
        double neueDaten[2] = {
            *(daten)*v.get(0),
            *(daten + 1) * v.get(1)};
        return Vector2(neueDaten);
    };

    Vector2 &operator*=(Vector<2> &v)
    {
        *(daten) *= v.get(0);
        *(daten + 1) *= v.get(1);
        return *this;
    };
};