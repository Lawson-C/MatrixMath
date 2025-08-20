#pragma once
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
        m.set(0, 1, *(daten + 2));
        m.set(1, 0, *(daten + 1));
        return m;
    };

    double determinant() {
        return (*(daten) * *(daten + 3)) - (*(daten + 1) * *(daten + 2));
    };

    Matrix<2, 2> inverse() {
        double d = determinant();
        double neueDaten[4] = {
            *(daten + 3) / d, -*(daten + 1) / d,
            -*(daten + 2) / d, *(daten) / d
        };
        return Matrix<2, 2>(neueDaten);
    };

    // mathematik addition/subtraktion

    Matrix<2, 2> operator+(Matrix<2, 2> &a)
    {
        double data[4] = {
            *(daten) + a.get(0, 0), *(daten + 1) + a.get(0, 1),
            *(daten + 2) + a.get(1, 0), *(daten + 3) + a.get(1, 1)};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator+=(Matrix<2, 2> &a)
    {
        *(daten) += a.get(0, 0);
        *(daten + 1) += a.get(0, 1);
        *(daten + 2) += a.get(1, 0);
        *(daten + 3) += a.get(1, 1);
        return *this;
    };

    Matrix<2, 2> operator-(Matrix<2, 2> &a)
    {
        double data[4] = {
            *(daten)-a.get(0, 0), *(daten + 1) - a.get(0, 1),
            *(daten + 2) - a.get(1, 0), *(daten + 3) - a.get(1, 1)};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator-=(Matrix<2, 2> &a)
    {
        *(daten) -= a.get(0, 0);
        *(daten + 1) -= a.get(0, 1);
        *(daten + 2) -= a.get(1, 0);
        *(daten + 3) -= a.get(1, 1);
        return *this;
    };

    // skalar multiplikation

    Matrix<2, 2> operator*(double k)
    {
        double data[4] = {
            *(daten)*k, *(daten + 1) * k,
            *(daten + 2) * k, *(daten + 3) * k};
        return Matrix<2, 2>(data);
    };

    Matrix22 &operator*=(double k)
    {
        *(daten) *= k;
        *(daten + 1) *= k;
        *(daten + 2) *= k;
        *(daten + 3) *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix22 &operator*=(Matrix<2, 2> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));
        *(neueDaten) = *(daten)*m.get(0, 0) + *(daten + 1) * m.get(1, 0);
        *(neueDaten + 1) = *(daten)*m.get(0, 1) + *(daten + 1) * m.get(0, 1);
        *(neueDaten + 2) = *(daten + 2) * m.get(0, 1) + *(daten + 3) * m.get(1, 1);
        *(neueDaten + 3) = *(daten + 2) * m.get(0, 1) + *(daten + 3) * m.get(1, 1);
        free(daten);
        daten = neueDaten;
        return *this;
    };
};