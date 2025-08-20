#pragma once

#include <cstring>
#include <malloc.h>

#include "matrixmath.h"

class Matrix44 : public Matrix<4, 4>
{
public:
    Matrix44(double data[16]) : Matrix<4, 4>(data) {
                                };

    /*
     * ergibt die Transponierung der Matrix
     */
    Matrix<4, 4> transpose()
    {
        Matrix<4, 4> m = Matrix<4, 4>(daten);
        m.set(0, 1, *(daten + 4));
        m.set(0, 2, *(daten + 8));
        m.set(0, 3, *(daten + 12));
        m.set(1, 2, *(daten + 9));
        m.set(1, 3, *(daten + 13));
        m.set(2, 3, *(daten + 14));

        m.set(1, 0, *(daten + 1));
        m.set(2, 0, *(daten + 2));
        m.set(2, 1, *(daten + 6));
        m.set(3, 0, *(daten + 3));
        m.set(3, 1, *(daten + 7));
        m.set(3, 2, *(daten + 11));
        return m;
    };

    // mathematik addition/subtraktion

    Matrix<4, 4> operator+(Matrix<4, 4> &a)
    {
        double data[16] = {
            *(daten) + a.get(0, 0), *(daten + 1) + a.get(0, 1), *(daten + 2) + a.get(0, 2), *(daten + 3) + a.get(0, 3),
            *(daten + 4) + a.get(1, 0), *(daten + 5) + a.get(1, 1), *(daten + 6) + a.get(1, 2), *(daten + 7) + a.get(1, 3),
            *(daten + 8) + a.get(2, 0), *(daten + 9) + a.get(2, 1), *(daten + 10) + a.get(2, 2), *(daten + 11) + a.get(2, 3),
            *(daten + 12) + a.get(3, 0), *(daten + 13) + a.get(3, 1), *(daten + 14) + a.get(3, 2), *(daten + 15) + a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator+=(Matrix<4, 4> &a)
    {
        *(daten) += a.get(0, 0);
        *(daten + 1) += a.get(0, 1);
        *(daten + 2) += a.get(0, 2);
        *(daten + 3) += a.get(0, 3);
        *(daten + 4) += a.get(1, 0);
        *(daten + 5) += a.get(1, 1);
        *(daten + 6) += a.get(1, 2);
        *(daten + 7) += a.get(1, 3);
        *(daten + 8) += a.get(2, 0);
        *(daten + 9) += a.get(2, 1);
        *(daten + 10) += a.get(2, 2);
        *(daten + 11) += a.get(2, 3);
        *(daten + 12) += a.get(3, 0);
        *(daten + 13) += a.get(3, 1);
        *(daten + 14) += a.get(3, 2);
        *(daten + 15) += a.get(3, 3);
        return *this;
    };

    Matrix<4, 4> operator-(Matrix<4, 4> &a)
    {
        double data[16] = {
            *(daten)-a.get(0, 0), *(daten + 1) - a.get(0, 1), *(daten + 2) - a.get(0, 2), *(daten + 3) - a.get(0, 3),
            *(daten + 4) - a.get(1, 0), *(daten + 5) - a.get(1, 1), *(daten + 6) - a.get(1, 2), *(daten + 7) - a.get(1, 3),
            *(daten + 8) - a.get(2, 0), *(daten + 9) - a.get(2, 1), *(daten + 10) - a.get(2, 2), *(daten + 11) - a.get(2, 3),
            *(daten + 12) - a.get(3, 0), *(daten + 13) - a.get(3, 1), *(daten + 14) - a.get(3, 2), *(daten + 15) - a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator-=(Matrix<4, 4> &a)
    {
        *(daten) -= a.get(0, 0);
        *(daten + 1) -= a.get(0, 1);
        *(daten + 2) -= a.get(0, 2);
        *(daten + 3) -= a.get(0, 3);
        *(daten + 4) -= a.get(1, 0);
        *(daten + 5) -= a.get(1, 1);
        *(daten + 6) -= a.get(1, 2);
        *(daten + 7) -= a.get(1, 3);
        *(daten + 8) -= a.get(2, 0);
        *(daten + 9) -= a.get(2, 1);
        *(daten + 10) -= a.get(2, 2);
        *(daten + 11) -= a.get(2, 3);
        *(daten + 12) -= a.get(3, 0);
        *(daten + 13) -= a.get(3, 1);
        *(daten + 14) -= a.get(3, 2);
        *(daten + 15) -= a.get(3, 3);
        return *this;
    };

    // skalar multiplikation

    Matrix<4, 4> operator*(double k)
    {
        double data[16] = {
            *(daten)*k, *(daten + 1) * k, *(daten + 2) * k, *(daten + 3) * k,
            *(daten + 4) * k, *(daten + 5) * k, *(daten + 6) * k, *(daten + 7) * k,
            *(daten + 8) * k, *(daten + 9) * k, *(daten + 10) * k, *(daten + 11) * k,
            *(daten + 12) * k, *(daten + 13) * k, *(daten + 14) * k, *(daten + 15) * k};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator*=(double k)
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
        *(daten + 9) *= k;
        *(daten + 10) *= k;
        *(daten + 11) *= k;
        *(daten + 12) *= k;
        *(daten + 13) *= k;
        *(daten + 14) *= k;
        *(daten + 15) *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix44 operator*(Matrix<4, 4> &m)
    {
        double neueDaten[16] =
            {
                *(neueDaten) = *(daten)*m.get(0, 0) + *(daten + 1) * m.get(1, 0) + *(daten + 2) * m.get(2, 0) + *(daten + 3) * m.get(3, 0),
                *(neueDaten + 1) = *(daten)*m.get(0, 1) + *(daten + 1) * m.get(1, 1) + *(daten)*m.get(2, 1) + *(daten + 3) * m.get(3, 1),
                *(neueDaten + 2) = *(daten)*m.get(0, 2) + *(daten + 1) * m.get(1, 2) + *(daten)*m.get(2, 2) + *(daten + 3) * m.get(3, 2),
                *(neueDaten + 3) = *(daten)*m.get(0, 3) + *(daten + 1) * m.get(1, 3) + *(daten)*m.get(2, 3) + *(daten + 3) * m.get(3, 3),

                *(neueDaten + 4) = *(daten + 4) * m.get(0, 0) + *(daten + 5) * m.get(1, 0) + *(daten + 6) * m.get(2, 0) + *(daten + 7) * m.get(3, 0),
                *(neueDaten + 5) = *(daten + 4) * m.get(0, 1) + *(daten + 5) * m.get(1, 1) + *(daten + 6) * m.get(2, 1) + *(daten + 7) * m.get(3, 1),
                *(neueDaten + 6) = *(daten + 4) * m.get(0, 2) + *(daten + 5) * m.get(1, 2) + *(daten + 6) * m.get(2, 2) + *(daten + 7) * m.get(3, 2),
                *(neueDaten + 7) = *(daten + 4) * m.get(0, 3) + *(daten + 5) * m.get(1, 3) + *(daten + 6) * m.get(2, 3) + *(daten + 7) * m.get(3, 3),

                *(neueDaten + 8) = *(daten + 8) * m.get(0, 0) + *(daten + 9) * m.get(1, 0) + *(daten + 10) * m.get(2, 0) + *(daten + 11) * m.get(3, 0),
                *(neueDaten + 9) = *(daten + 8) * m.get(0, 1) + *(daten + 9) * m.get(1, 1) + *(daten + 10) * m.get(2, 1) + *(daten + 11) * m.get(3, 1),
                *(neueDaten + 10) = *(daten + 8) * m.get(0, 2) + *(daten + 9) * m.get(1, 2) + *(daten + 10) * m.get(2, 2) + *(daten + 11) * m.get(3, 2),
                *(neueDaten + 11) = *(daten + 8) * m.get(0, 3) + *(daten + 9) * m.get(1, 3) + *(daten + 10) * m.get(2, 3) + *(daten + 11) * m.get(3, 3),

                *(neueDaten + 12) = *(daten + 12) * m.get(0, 0) + *(daten + 13) * m.get(1, 0) + *(daten + 14) * m.get(2, 0) + *(daten + 15) * m.get(3, 0),
                *(neueDaten + 13) = *(daten + 12) * m.get(0, 1) + *(daten + 13) * m.get(1, 1) + *(daten + 14) * m.get(2, 1) + *(daten + 15) * m.get(3, 1),
                *(neueDaten + 14) = *(daten + 12) * m.get(0, 2) + *(daten + 13) * m.get(1, 2) + *(daten + 14) * m.get(2, 2) + *(daten + 15) * m.get(3, 2),
                *(neueDaten + 15) = *(daten + 12) * m.get(0, 3) + *(daten + 13) * m.get(1, 3) + *(daten + 14) * m.get(2, 3) + *(daten + 15) * m.get(3, 3)};

        return Matrix44(neueDaten);
    };

    Matrix44 &operator*=(Matrix<4, 4> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));

        *(neueDaten) = *(daten)*m.get(0, 0) + *(daten + 1) * m.get(1, 0) + *(daten + 2) * m.get(2, 0) + *(daten + 3) * m.get(3, 0);
        *(neueDaten + 1) = *(daten)*m.get(0, 1) + *(daten + 1) * m.get(1, 1) + *(daten)*m.get(2, 1) + *(daten + 3) * m.get(3, 1);
        *(neueDaten + 2) = *(daten)*m.get(0, 2) + *(daten + 1) * m.get(1, 2) + *(daten)*m.get(2, 2) + *(daten + 3) * m.get(3, 2);
        *(neueDaten + 3) = *(daten)*m.get(0, 3) + *(daten + 1) * m.get(1, 3) + *(daten)*m.get(2, 3) + *(daten + 3) * m.get(3, 3);

        *(neueDaten + 4) = *(daten + 4) * m.get(0, 0) + *(daten + 5) * m.get(1, 0) + *(daten + 6) * m.get(2, 0) + *(daten + 7) * m.get(3, 0);
        *(neueDaten + 5) = *(daten + 4) * m.get(0, 1) + *(daten + 5) * m.get(1, 1) + *(daten + 6) * m.get(2, 1) + *(daten + 7) * m.get(3, 1);
        *(neueDaten + 6) = *(daten + 4) * m.get(0, 2) + *(daten + 5) * m.get(1, 2) + *(daten + 6) * m.get(2, 2) + *(daten + 7) * m.get(3, 2);
        *(neueDaten + 7) = *(daten + 4) * m.get(0, 3) + *(daten + 5) * m.get(1, 3) + *(daten + 6) * m.get(2, 3) + *(daten + 7) * m.get(3, 3);

        *(neueDaten + 8) = *(daten + 8) * m.get(0, 0) + *(daten + 9) * m.get(1, 0) + *(daten + 10) * m.get(2, 0) + *(daten + 11) * m.get(3, 0);
        *(neueDaten + 9) = *(daten + 8) * m.get(0, 1) + *(daten + 9) * m.get(1, 1) + *(daten + 10) * m.get(2, 1) + *(daten + 11) * m.get(3, 1);
        *(neueDaten + 10) = *(daten + 8) * m.get(0, 2) + *(daten + 9) * m.get(1, 2) + *(daten + 10) * m.get(2, 2) + *(daten + 11) * m.get(3, 2);
        *(neueDaten + 11) = *(daten + 8) * m.get(0, 3) + *(daten + 9) * m.get(1, 3) + *(daten + 10) * m.get(2, 3) + *(daten + 11) * m.get(3, 3);

        *(neueDaten + 12) = *(daten + 12) * m.get(0, 0) + *(daten + 13) * m.get(1, 0) + *(daten + 14) * m.get(2, 0) + *(daten + 15) * m.get(3, 0);
        *(neueDaten + 13) = *(daten + 12) * m.get(0, 1) + *(daten + 13) * m.get(1, 1) + *(daten + 14) * m.get(2, 1) + *(daten + 15) * m.get(3, 1);
        *(neueDaten + 14) = *(daten + 12) * m.get(0, 2) + *(daten + 13) * m.get(1, 2) + *(daten + 14) * m.get(2, 2) + *(daten + 15) * m.get(3, 2);
        *(neueDaten + 15) = *(daten + 12) * m.get(0, 3) + *(daten + 13) * m.get(1, 3) + *(daten + 14) * m.get(2, 3) + *(daten + 15) * m.get(3, 3);

        free(daten);
        daten = neueDaten;
        return *this;
    };

    // Vectorenmultiplikation

    /*
     * multipliziert eine Matrix mit einem Vektor und ergibt jenen Vektor
     */
    Vector4 operator*(Vector<4> &v)
    {
        double neueDaten[4] = {
            *(daten)*v.get(0) + *(daten + 1) * v.get(1) + *(daten + 2) * v.get(2) + *(daten + 3) * v.get(3),
            *(daten + 4) * v.get(0) + *(daten + 5) * v.get(1) + *(daten + 6) * v.get(2) + *(daten + 7) * v.get(3),
            *(daten + 8) * v.get(0) + *(daten + 9) * v.get(1) + *(daten + 10) * v.get(2) + *(daten + 11) * v.get(3),
            *(daten + 12) * v.get(0) + *(daten + 13) * v.get(1) + *(daten + 14) * v.get(2) + *(daten + 15) * v.get(3)};

        return Vector4(neueDaten);
    };
};