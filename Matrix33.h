#pragma once
#include "Matrix.h"

#include <cstring>
#include <malloc.h>

class Matrix33 : public Matrix<3, 3>
{
public:
    Matrix33(double data[9]) : Matrix<3, 3>(data) {
                               };

    /*
     * ergibt die Transponierung der Matrix
     */
    Matrix<3, 3> transpose()
    {
        Matrix<3, 3> m = Matrix<3, 3>(daten);
        m.set(0, 1, *(daten + 3));
        m.set(0, 2, *(daten + 6));
        m.set(1, 2, *(daten + 7));
        m.set(1, 0, *(daten + 1));
        m.set(2, 0, *(daten + 2));
        m.set(2, 1, *(daten + 5));
        return m;
    };

    // mathematik addition/subtraktion

    Matrix<3, 3> operator+(Matrix<3, 3> &a)
    {
        double data[9] = {
            *(daten) + a.get(0, 0), *(daten + 1) + a.get(0, 1), *(daten + 2) + a.get(0, 2),
            *(daten + 3) + a.get(1, 0), *(daten + 4) + a.get(1, 1), *(daten + 5) + a.get(1, 2),
            *(daten + 6) + a.get(2, 0), *(daten + 7) + a.get(2, 1), *(daten + 8) + a.get(2, 2)};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator+=(Matrix<3, 3> &a)
    {
        *(daten) += a.get(0, 0);
        *(daten + 1) += a.get(0, 1);
        *(daten + 2) += a.get(0, 2);
        *(daten + 3) += a.get(1, 0);
        *(daten + 4) += a.get(1, 1);
        *(daten + 5) += a.get(1, 2);
        *(daten + 6) += a.get(2, 0);
        *(daten + 7) += a.get(2, 1);
        *(daten + 8) += a.get(2, 2);
        return *this;
    };

    Matrix<3, 3> operator-(Matrix<3, 3> &a)
    {
        double data[9] = {
            *(daten)-a.get(0, 0), *(daten + 1) - a.get(0, 1), *(daten + 2) - a.get(0, 2),
            *(daten + 3) - a.get(1, 0), *(daten + 4) - a.get(1, 1), *(daten + 5) - a.get(1, 2),
            *(daten + 6) - a.get(2, 0), *(daten + 7) - a.get(2, 1), *(daten + 8) - a.get(2, 2)};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator-=(Matrix<3, 3> &a)
    {
        *(daten) -= a.get(0, 0);
        *(daten + 1) -= a.get(0, 1);
        *(daten + 2) -= a.get(0, 2);
        *(daten + 3) -= a.get(1, 0);
        *(daten + 4) -= a.get(1, 1);
        *(daten + 5) -= a.get(1, 2);
        *(daten + 6) -= a.get(2, 0);
        *(daten + 7) -= a.get(2, 1);
        *(daten + 8) -= a.get(2, 2);
        return *this;
    };

    // skalar multiplikation

    Matrix<3, 3> operator*(double k)
    {
        double data[9] = {
            *(daten)*k, *(daten + 1) * k, *(daten + 2) * k,
            *(daten + 3) * k, *(daten + 4) * k, *(daten + 5) * k,
            *(daten + 6) * k, *(daten + 7) * k, *(daten + 8) * k};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator*=(double k)
    {
        *(daten) *= k;
        *(daten + 1) *= k;
        *(daten + 2) *= k;
        *(daten + 3) *= k;
        *(daten + 4) *= k;
        *(daten + 5) *= k;
        *(daten + 6) *= k;
        *(daten + 7) *= k;
        *(daten + 8) *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix33 &operator*=(Matrix<3, 3> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));

        *(neueDaten) = *(daten)*m.get(0, 0) + *(daten + 1) * m.get(1, 0) + *(daten + 2) * m.get(2, 0);
        *(neueDaten + 1) = *(daten)*m.get(0, 1) + *(daten + 1) * m.get(1, 1) + *(daten)*m.get(2, 1);
        *(neueDaten + 2) = *(daten)*m.get(0, 2) + *(daten + 1) * m.get(1, 2) + *(daten)*m.get(2, 2);

        *(neueDaten + 3) = *(daten + 3) * m.get(0, 0) + *(daten + 3) * m.get(1, 0) + *(daten + 4) * m.get(2, 0);
        *(neueDaten + 4) = *(daten + 3) * m.get(0, 1) + *(daten + 3) * m.get(1, 1) + *(daten + 4) * m.get(2, 1);
        *(neueDaten + 5) = *(daten + 3) * m.get(0, 2) + *(daten + 3) * m.get(1, 2) + *(daten + 4) * m.get(2, 2);

        *(neueDaten + 6) = *(daten + 6) * m.get(0, 0) + *(daten + 7) * m.get(1, 0) + *(daten + 8) * m.get(2, 0);
        *(neueDaten + 7) = *(daten + 6) * m.get(0, 1) + *(daten + 7) * m.get(1, 1) + *(daten + 8) * m.get(2, 1);
        *(neueDaten + 8) = *(daten + 6) * m.get(0, 2) + *(daten + 7) * m.get(1, 2) + *(daten + 8) * m.get(2, 2);

        free(daten);
        daten = neueDaten;
        return *this;
    };
};