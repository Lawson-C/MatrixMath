#pragma once
#include "Matrix.h"

#define M00 (*(daten))
#define M01 (*(daten + 1))
#define M02 (*(daten + 2))
#define M03 (*(daten + 3))
#define M10 (*(daten + 4))
#define M11 (*(daten + 5))
#define M12 (*(daten + 6))
#define M13 (*(daten + 7))
#define M20 (*(daten + 8))
#define M21 (*(daten + 9))
#define M22 (*(daten + 10))
#define M23 (*(daten + 11))
#define M30 (*(daten + 12))
#define M31 (*(daten + 13))
#define M32 (*(daten + 14))
#define M33 (*(daten + 15))

#include <cstring>
#include <malloc.h>

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
        m.set(0, 1, M10);
        m.set(0, 2, M20);
        m.set(0, 3, M30);
        m.set(1, 2, M21);
        m.set(1, 3, M31);
        m.set(2, 3, M32);

        m.set(1, 0, M01);
        m.set(2, 0, M02);
        m.set(2, 1, M12);
        m.set(3, 0, M03);
        m.set(3, 1, M13);
        m.set(3, 2, M23);
        return m;
    };

    // mathematik addition/subtraktion

    Matrix<4, 4> operator+(Matrix<4, 4> &a)
    {
        double data[16] = {
            M00 + a.get(0, 0), M01 + a.get(0, 1), M02 + a.get(0, 2), M03 + a.get(0, 3),
            M10 + a.get(1, 0), M11 + a.get(1, 1), M12 + a.get(1, 2), M13 + a.get(1, 3),
            M20 + a.get(2, 0), M21 + a.get(2, 1), M22 + a.get(2, 2), M23 + a.get(2, 3),
            M30 + a.get(3, 0), M31 + a.get(3, 1), M32 + a.get(3, 2), M33 + a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator+=(Matrix<4, 4> &a)
    {
        M00 += a.get(0, 0);
        M01 += a.get(0, 1);
        M02 += a.get(0, 2);
        M03 += a.get(0, 3);
        M10 += a.get(1, 0);
        M11 += a.get(1, 1);
        M12 += a.get(1, 2);
        M13 += a.get(1, 3);
        M20 += a.get(2, 0);
        M21 += a.get(2, 1);
        M22 += a.get(2, 2);
        M23 += a.get(2, 3);
        M30 += a.get(3, 0);
        M31 += a.get(3, 1);
        M32 += a.get(3, 2);
        M33 += a.get(3, 3);
        return *this;
    };

    Matrix<4, 4> operator-(Matrix<4, 4> &a)
    {
        double data[16] = {
            M00 - a.get(0, 0), M01 - a.get(0, 1), M02 - a.get(0, 2), M03 - a.get(0, 3),
            M10 - a.get(1, 0), M11 - a.get(1, 1), M12 - a.get(1, 2), M13 - a.get(1, 3),
            M20 - a.get(2, 0), M21 - a.get(2, 1), M22 - a.get(2, 2), M23 - a.get(2, 3),
            M30 - a.get(3, 0), M31 - a.get(3, 1), M32 - a.get(3, 2), M33 - a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator-=(Matrix<4, 4> &a)
    {
        M00 -= a.get(0, 0);
        M01 -= a.get(0, 1);
        M02 -= a.get(0, 2);
        M03 -= a.get(0, 3);
        M10 -= a.get(1, 0);
        M11 -= a.get(1, 1);
        M12 -= a.get(1, 2);
        M13 -= a.get(1, 3);
        M20 -= a.get(2, 0);
        M21 -= a.get(2, 1);
        M22 -= a.get(2, 2);
        M23 -= a.get(2, 3);
        M30 -= a.get(3, 0);
        M31 -= a.get(3, 1);
        M32 -= a.get(3, 2);
        M33 -= a.get(3, 3);
        return *this;
    };

    // skalar multiplikation

    Matrix<4, 4> operator*(double k)
    {
        double data[16] = {
            M00 * k, M01 * k, M02 * k, M03 * k,
            M10 * k, M11 * k, M12 * k, M13 * k,
            M20 * k, M21 * k, M22 * k, M23 * k,
            M30 * k, M31 * k, M32 * k, M33 * k};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator*=(double k)
    {
        M00 *= k;
        M01 *= k;
        M02 *= k;
        M03 *= k;
        M10 *= k;
        M11 *= k;
        M12 *= k;
        M13 *= k;
        M20 *= k;
        M21 *= k;
        M22 *= k;
        M23 *= k;
        M30 *= k;
        M31 *= k;
        M32 *= k;
        M33 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix44 &operator*=(Matrix<4, 4> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));

        *(neueDaten) = M00 * m.get(0, 0) + M01 * m.get(1, 0) + M02 * m.get(2, 0) + M03 * m.get(3, 0);
        *(neueDaten + 1) = M00 * m.get(0, 1) + M01 * m.get(1, 1) + M00 * m.get(2, 1) + M03 * m.get(3, 1);
        *(neueDaten + 2) = M00 * m.get(0, 2) + M01 * m.get(1, 2) + M00 * m.get(2, 2) + M03 * m.get(3, 2);
        *(neueDaten + 3) = M00 * m.get(0, 3) + M01 * m.get(1, 3) + M00 * m.get(2, 3) + M03 * m.get(3, 3);

        *(neueDaten + 4) = M10 * m.get(0, 0) + M11 * m.get(1, 0) + M12 * m.get(2, 0) + M13 * m.get(3, 0);
        *(neueDaten + 5) = M10 * m.get(0, 1) + M11 * m.get(1, 1) + M12 * m.get(2, 1) + M13 * m.get(3, 1);
        *(neueDaten + 6) = M10 * m.get(0, 2) + M11 * m.get(1, 2) + M12 * m.get(2, 2) + M13 * m.get(3, 2);
        *(neueDaten + 7) = M10 * m.get(0, 3) + M11 * m.get(1, 3) + M12 * m.get(2, 3) + M13 * m.get(3, 3);

        *(neueDaten + 8) = M20 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0) + M23 * m.get(3, 0);
        *(neueDaten + 9) = M20 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1) + M23 * m.get(3, 1);
        *(neueDaten + 10) = M20 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2) + M23 * m.get(3, 2);
        *(neueDaten + 11) = M20 * m.get(0, 3) + M21 * m.get(1, 3) + M22 * m.get(2, 3) + M23 * m.get(3, 3);

        *(neueDaten + 12) = M30 * m.get(0, 0) + M31 * m.get(1, 0) + M32 * m.get(2, 0) + M33 * m.get(3, 0);
        *(neueDaten + 13) = M30 * m.get(0, 1) + M31 * m.get(1, 1) + M32 * m.get(2, 1) + M33 * m.get(3, 1);
        *(neueDaten + 14) = M30 * m.get(0, 2) + M31 * m.get(1, 2) + M32 * m.get(2, 2) + M33 * m.get(3, 2);
        *(neueDaten + 15) = M30 * m.get(0, 3) + M31 * m.get(1, 3) + M32 * m.get(2, 3) + M33 * m.get(3, 3);

        free(daten);
        daten = neueDaten;
        return *this;
    };
};

#undef M00
#undef M01
#undef M02
#undef M03
#undef M10
#undef M11
#undef M12
#undef M13
#undef M20
#undef M21
#undef M22
#undef M23
#undef M30
#undef M31
#undef M32
#undef M33