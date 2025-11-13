#pragma once


#define V1 (*(daten))
#define V2 (*(daten + 1))
#define V3 (*(daten + 2))
#define V4 (*(daten + 3))

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
        return std::sqrt(V1 * V1 + V2 * V2 + V3 * V3 + V4 * V4);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector4 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V1 /= mag;
        V2 /= mag;
        V3 /= mag;
        V4 /= mag;
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
            V1 / mag,
            V2 / mag,
            V3 / mag,
            V4 / mag};
        Vector4 v = Vector4(normalizierteDaten);
        return v;
    };

    // skalar multiplikation

    Vector4 operator*(double k)
    {
        double data[4] = {
            V1*k, V2 * k, V3 * k, V4 * k};
        return Vector4(data);
    };

    Vector4 &operator*=(double k)
    {
        double *neueDaten = (double *)malloc(2 * sizeof(double));
        *(neueDaten) = V1*k;
        *(neueDaten + 1) = V2 * k;
        *(neueDaten + 2) = V3 * k;
        *(neueDaten + 3) = V4 * k;
        free(daten);
        daten = neueDaten;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector4 operator+(Vector<4> &a)
    {
        double data[4] = {
            V1 + a.get(0),
            V2 + a.get(1),
            V3 + a.get(2),
            V4 + a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator+=(Vector<4> &a)
    {
        V1 += a.get(0);
        V2 += a.get(1);
        V3 += a.get(2);
        V4 += a.get(3);
        return *this;
    };

    Vector4 operator-(Vector<4> &a)
    {
        double data[4] = {
            V1-a.get(0),
            V2 - a.get(1),
            V3 - a.get(2),
            V4 - a.get(3)};
        return Vector4(data);
    };

    Vector4 &operator-=(Vector<4> &a)
    {
        V1 -= a.get(0);
        V2 -= a.get(1);
        V3 -= a.get(2);
        V4 -= a.get(3);
        return *this;
    };
};

#undef V1
#undef V2
#undef V3
#undef V4