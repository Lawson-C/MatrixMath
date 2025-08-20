#pragma once

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
        return std::sqrt(*(daten) * *(daten) + *(daten + 1) * *(daten + 1) + *(daten + 2) * *(daten + 2));
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector3 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        *(daten) /= mag;
        *(daten + 1) /= mag;
        *(daten + 2) /= mag;
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
            *(daten) / mag,
            *(daten + 1) / mag,
            *(daten + 2) / mag};
        Vector3 v = Vector3(normalizierteDaten);
        return v;
    };

    // skalar multiplikation

    Vector3 operator*(double k)
    {
        double data[3] = {
            *(daten)*k, *(daten + 1) * k, *(daten + 2) * k};
        return Vector3(data);
    };

    Vector3 &operator*=(double k)
    {
        double *neueDaten = (double *)malloc(2 * sizeof(double));
        *(neueDaten) = *(daten)*k;
        *(neueDaten + 1) = *(daten + 1) * k;
        *(neueDaten + 2) = *(daten + 2) * k;
        free(daten);
        daten = neueDaten;
        return *this;
    };

    // mathematik addition/subtraktion

    Vector3 operator+(Vector<3> &a)
    {
        double data[3] = {
            *(daten) + a.get(0), *(daten + 1) + a.get(1), *(daten + 2) + a.get(2)};
        return Vector3(data);
    };

    Vector3 &operator+=(Vector<3> &a)
    {
        *(daten) -= a.get(0);
        *(daten + 1) -= a.get(1);
        *(daten + 2) -= a.get(2);
        return *this;
    };

    Vector3 operator-(Vector<3> &a)
    {
        double data[3] = {
            *(daten) - a.get(0), *(daten + 1) - a.get(1), *(daten + 2) - a.get(2)};
        return Vector3(data);
    };

    Vector3 &operator-=(Vector<3> &a)
    {
        *(daten) -= a.get(0);
        *(daten + 1) -= a.get(1);
        *(daten + 2) -= a.get(2);
        return *this;
    };
};