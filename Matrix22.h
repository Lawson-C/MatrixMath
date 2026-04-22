#pragma once

#define M00 (*(daten))
#define M01 (*(daten + 1))
#define M10 (*(daten + 2))
#define M11 (*(daten + 3))

#include "Matrix.h"

#include <cstring>
#include <malloc.h>

class Matrix22 : public Matrix<2, 2>
{
public:
    Matrix22(double data[4]) : Matrix<2, 2>(data) {
                               };

    /*
     * ergibt die Transponierung der Matrix
     */
    Matrix22 transpose()
    {
        Matrix22 m = Matrix22(daten);
        m.set(0, 1, M10);
        m.set(1, 0, M01);
        return m;
    };

    inline double determinant()
    {
        return (M00 * M11) - (M01 * M10);
    };

    Matrix22 inverse()
    {
        double d = determinant();
        double neueDaten[4] = {
            M11 / d, -M01 / d,
            -M10 / d, M00 / d};
        return Matrix22(neueDaten);
    };

    // mathematik addition/subtraktion

    Matrix22 operator+(Matrix22 &a)
    {
        double data[4] = {
            M00 + a.get(0, 0), M01 + a.get(0, 1),
            M10 + a.get(1, 0), M11 + a.get(1, 1)};
        return Matrix22(data);
    };

    Matrix22 &operator+=(Matrix22 &a)
    {
        M00 += a.get(0, 0);
        M01 += a.get(0, 1);
        M10 += a.get(1, 0);
        M11 += a.get(1, 1);
        return *this;
    };

    Matrix22 operator-(Matrix22 &a)
    {
        double data[4] = {
            M00 - a.get(0, 0), M01 - a.get(0, 1),
            M10 - a.get(1, 0), M11 - a.get(1, 1)};
        return Matrix22(data);
    };

    Matrix22 &operator-=(Matrix22 &a)
    {
        M00 -= a.get(0, 0);
        M01 -= a.get(0, 1);
        M10 -= a.get(1, 0);
        M11 -= a.get(1, 1);
        return *this;
    };

    // skalar multiplikation

    Matrix22 operator*(double k)
    {
        double data[4] = {
            M00 * k, M01 * k,
            M10 * k, M11 * k};
        return Matrix22(data);
    };

    Matrix22 &operator*=(double k)
    {
        M00 *= k;
        M01 *= k;
        M10 *= k;
        M11 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix22 operator*(Matrix22 &m)
    {
        double neueDaten[4] =
            {
                M00 * m.get(0, 0) + M01 * m.get(1, 0),
                M00 * m.get(0, 1) + M01 * m.get(1, 1),

                M10 * m.get(0, 0) + M11 * m.get(1, 0),
                M10 * m.get(0, 1) + M11 * m.get(1, 1)};

        return Matrix22(neueDaten);
    };

    Matrix22 &operator*=(Matrix22 &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));
        *(neueDaten) = M00 * m.get(0, 0) + M01 * m.get(1, 0);
        *(neueDaten + 1) = M00 * m.get(0, 1) + M01 * m.get(1, 1);
        *(neueDaten + 2) = M10 * m.get(0, 0) + M11 * m.get(1, 0);
        *(neueDaten + 3) = M10 * m.get(0, 1) + M11 * m.get(1, 1);
        free(daten);
        daten = neueDaten;
        return *this;
    };

    template <int Spalten>
    Matrix<Spalten, 2> operator*(Matrix<2, Spalten> &m)
    {
        double *neueDaten = malloc(2 * Spalten * sizeof(double));
        for (int z = 0; z < Spalten; z++)
        {
            *(neueDaten + 2 * z) = M00 * m.get(0, z) + M01 * m.get(1, z);
            *(neueDaten + 2 * z + 1) = M10 * m.get(0, z) + M11 * m.get(1, z);
        };
        return Matrix<Spalten, 2>(neueDaten);
    };
};

#undef M00
#undef M01
#undef M10
#undef M11