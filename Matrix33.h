#pragma once

#define M00 (*(daten))
#define M01 (*(daten + 1))
#define M02 (*(daten + 2))
#define M10 (*(daten + 3))
#define M11 (*(daten + 4))
#define M12 (*(daten + 5))
#define M20 (*(daten + 6))
#define M21 (*(daten + 7))
#define M22 (*(daten + 8))

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
    Matrix33 transpose()
    {
        Matrix33 m = Matrix33(daten);
        m.set(0, 1, M10);
        m.set(0, 2, M20);
        m.set(1, 2, M21);
        m.set(1, 0, M01);
        m.set(2, 0, M02);
        m.set(2, 1, M12);
        return m;
    };

    // mathematik addition/subtraktion

    Matrix33 operator+(Matrix33 &a)
    {
        double data[9] = {
            M00 + a.get(0, 0), M01 + a.get(0, 1), M02 + a.get(0, 2),
            M10 + a.get(1, 0), M11 + a.get(1, 1), M12 + a.get(1, 2),
            M20 + a.get(2, 0), M21 + a.get(2, 1), M22 + a.get(2, 2)};
        return Matrix33(data);
    };

    Matrix33 &operator+=(Matrix33 &a)
    {
        M00 += a.get(0, 0);
        M01 += a.get(0, 1);
        M02 += a.get(0, 2);
        M10 += a.get(1, 0);
        M11 += a.get(1, 1);
        M12 += a.get(1, 2);
        M20 += a.get(2, 0);
        M21 += a.get(2, 1);
        M22 += a.get(2, 2);
        return *this;
    };

    Matrix33 operator-(Matrix33 &a)
    {
        double data[9] = {
            M00 - a.get(0, 0), M01 - a.get(0, 1), M02 - a.get(0, 2),
            M10 - a.get(1, 0), M11 - a.get(1, 1), M12 - a.get(1, 2),
            M20 - a.get(2, 0), M21 - a.get(2, 1), M22 - a.get(2, 2)};
        return Matrix33(data);
    };

    Matrix33 &operator-=(Matrix33 &a)
    {
        M00 -= a.get(0, 0);
        M01 -= a.get(0, 1);
        M02 -= a.get(0, 2);
        M10 -= a.get(1, 0);
        M11 -= a.get(1, 1);
        M12 -= a.get(1, 2);
        M20 -= a.get(2, 0);
        M21 -= a.get(2, 1);
        M22 -= a.get(2, 2);
        return *this;
    };

    // skalar multiplikation

    Matrix33 operator*(double k)
    {
        double data[9] = {
            M00 * k, M01 * k, M02 * k,
            M10 * k, M11 * k, M12 * k,
            M20 * k, M21 * k, M22 * k};
        return Matrix33(data);
    };

    Matrix33 &operator*=(double k)
    {
        M00 *= k;
        M01 *= k;
        M02 *= k;
        M10 *= k;
        M11 *= k;
        M12 *= k;
        M20 *= k;
        M21 *= k;
        M22 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix33 operator*(Matrix33 &m)
    {
        double neueDaten[9] =
            {
                M00 * m.get(0, 0) + M01 * m.get(1, 0) + M02 * m.get(2, 0),
                M00 * m.get(0, 1) + M01 * m.get(1, 1) + M02 * m.get(2, 1),
                M00 * m.get(0, 2) + M01 * m.get(1, 2) + M02 * m.get(2, 2),

                M10 * m.get(0, 0) + M11 * m.get(1, 0) + M12 * m.get(2, 0),
                M10 * m.get(0, 1) + M11 * m.get(1, 1) + M12 * m.get(2, 1),
                M10 * m.get(0, 2) + M11 * m.get(1, 2) + M12 * m.get(2, 2),

                M20 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0),
                M20 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1),
                M20 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2)};

        return Matrix33(neueDaten);
    };

    Matrix33 &operator*=(Matrix33 &m)
    {
        double *neueDaten = (double *)malloc(9 * sizeof(double));

        *(neueDaten) = M00 * m.get(0, 0) + M01 * m.get(1, 0) + M02 * m.get(2, 0);
        *(neueDaten + 1) = M00 * m.get(0, 1) + M01 * m.get(1, 1) + M02 * m.get(2, 1);
        *(neueDaten + 2) = M00 * m.get(0, 2) + M01 * m.get(1, 2) + M02 * m.get(2, 2);

        *(neueDaten + 3) = M10 * m.get(0, 0) + M11 * m.get(1, 0) + M12 * m.get(2, 0);
        *(neueDaten + 4) = M10 * m.get(0, 1) + M11 * m.get(1, 1) + M12 * m.get(2, 1);
        *(neueDaten + 5) = M10 * m.get(0, 2) + M11 * m.get(1, 2) + M12 * m.get(2, 2);

        *(neueDaten + 6) = M20 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0);
        *(neueDaten + 7) = M20 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1);
        *(neueDaten + 8) = M20 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2);

        free(daten);
        daten = neueDaten;
        return *this;
    };
};

#undef M00
#undef M01
#undef M02
#undef M10
#undef M11
#undef M12
#undef M20
#undef M21
#undef M22