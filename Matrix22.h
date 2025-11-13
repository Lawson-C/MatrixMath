#pragma once

#define M11 (*(daten))
#define M12 (*(daten + 1))
#define M21 (*(daten + 2))
#define M22 (*(daten + 3))

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
    Matrix<2, 2> transpose()
    {
        Matrix<2, 2> m = Matrix<2, 2>(daten);
        m.set(0, 1, M21);
        m.set(1, 0, M12);
        return m;
    };

    inline double determinant()
    {
        return (M11 * M22) - (M12 * M21);
    };

    Matrix<2, 2> inverse()
    {
        double d = determinant();
        double neueDaten[4] = {
            M22 / d, -M12 / d,
            -M21 / d, M11 / d};
        return Matrix<2, 2>(neueDaten);
    };

    // mathematik addition/subtraktion

    Matrix<2, 2> operator+(Matrix<2, 2> &a)
    {
        double data[4] = {
            M11 + a.get(0, 0), M12 + a.get(0, 1),
            M21 + a.get(1, 0), M22 + a.get(1, 1)};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator+=(Matrix<2, 2> &a)
    {
        M11 += a.get(0, 0);
        M12 += a.get(0, 1);
        M21 += a.get(1, 0);
        M22 += a.get(1, 1);
        return *this;
    };

    Matrix<2, 2> operator-(Matrix<2, 2> &a)
    {
        double data[4] = {
            M11 - a.get(0, 0), M12 - a.get(0, 1),
            M21 - a.get(1, 0), M22 - a.get(1, 1)};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator-=(Matrix<2, 2> &a)
    {
        M11 -= a.get(0, 0);
        M12 -= a.get(0, 1);
        M21 -= a.get(1, 0);
        M22 -= a.get(1, 1);
        return *this;
    };

    // skalar multiplikation

    Matrix<2, 2> operator*(double k)
    {
        double data[4] = {
            M11 * k, M12 * k,
            M21 * k, M22 * k};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator*=(double k)
    {
        M11 *= k;
        M12 *= k;
        M21 *= k;
        M22 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix22 &operator*=(Matrix<2, 2> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));
        M11 = M11 * m.get(0, 0) + M12 * m.get(1, 0);
        M12 = M11 * m.get(0, 1) + M12 * m.get(0, 1);
        M21 = M21 * m.get(0, 1) + M22 * m.get(1, 1);
        M22 = M21 * m.get(0, 1) + M22 * m.get(1, 1);
        free(daten);
        daten = neueDaten;
        return *this;
    };
};

#undef M11
#undef M12
#undef M21
#undef M22