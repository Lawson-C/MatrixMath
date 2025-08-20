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

    // Vectorenmultiplikation

    Vector3 operator*(Vector<3> &v)
    {
        double neueDaten[3] = {
            *(daten)*v.get(0),
            *(daten + 1) * v.get(1),
            *(daten + 2) * v.get(2)};
        return Vector3(neueDaten);
    };

    Vector3 &operator*=(Vector<3> &v)
    {
        *(daten) *= v.get(0);
        *(daten + 1) *= v.get(1);
        *(daten + 2) *= v.get(2);
        return *this;
    };

    template <int Zeilen>
    Vector3 operator*(Matrix<Zeilen, 3> &v)
    {
        double neueDaten[Zeilen];
        for (int i = 0; i < Zeilen; i++)
        {
            neueDaten[i] = *(daten)*v.get(i, 0) + *(daten + 1) * v.get(i, 1) + *(daten + 2) * v.get(i, 2);
        };
        return Vector3(neueDaten);
    };

    Vector3 &operator*=(Matrix<3, 3> &v)
    {
        double *neueDaten = (double *)malloc(2 * sizeof(double));
        *(neueDaten) = *(daten)*v.get(0, 0) + *(daten + 1) * v.get(1, 0) + *(daten + 2) * v.get(2, 0);
        *(neueDaten + 1) = *(daten)*v.get(0, 1) + *(daten + 1) * v.get(1, 1) + *(daten + 2) * v.get(2, 1);
        *(neueDaten + 2) = *(daten)*v.get(0, 2) + *(daten + 1) * v.get(1, 2) + *(daten + 2) * v.get(2, 2);
        free(daten);
        daten = neueDaten;
        return *this;
    };
};