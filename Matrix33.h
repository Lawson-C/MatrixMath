#pragma once

#define M11 (*(daten))
#define M12 (*(daten + 1))
#define M13 (*(daten + 2))
#define M21 (*(daten + 3))
#define M22 (*(daten + 4))
#define M23 (*(daten + 5))
#define M31 (*(daten + 6))
#define M32 (*(daten + 7))
#define M33 (*(daten + 8))

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
        m.set(0, 1, M21);
        m.set(0, 2, M31);
        m.set(1, 2, M32);
        m.set(1, 0, M12);
        m.set(2, 0, M13);
        m.set(2, 1, M23);
        return m;
    };

    // mathematik addition/subtraktion

    Matrix<3, 3> operator+(Matrix<3, 3> &a)
    {
        double data[9] = {
            M11 + a.get(0, 0), M12 + a.get(0, 1), M13 + a.get(0, 2),
            M21 + a.get(1, 0), M22 + a.get(1, 1), M23 + a.get(1, 2),
            M31 + a.get(2, 0), M32 + a.get(2, 1), M33 + a.get(2, 2)};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator+=(Matrix<3, 3> &a)
    {
        M11 += a.get(0, 0);
        M12 += a.get(0, 1);
        M13 += a.get(0, 2);
        M21 += a.get(1, 0);
        M22 += a.get(1, 1);
        M23 += a.get(1, 2);
        M31 += a.get(2, 0);
        M32 += a.get(2, 1);
        M33 += a.get(2, 2);
        return *this;
    };

    Matrix<3, 3> operator-(Matrix<3, 3> &a)
    {
        double data[9] = {
            M11-a.get(0, 0), M12 - a.get(0, 1), M13 - a.get(0, 2),
            M21 - a.get(1, 0), M22 - a.get(1, 1), M23 - a.get(1, 2),
            M31 - a.get(2, 0), M32 - a.get(2, 1), M33 - a.get(2, 2)};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator-=(Matrix<3, 3> &a)
    {
        M11 -= a.get(0, 0);
        M12 -= a.get(0, 1);
        M13 -= a.get(0, 2);
        M21 -= a.get(1, 0);
        M22 -= a.get(1, 1);
        M23 -= a.get(1, 2);
        M31 -= a.get(2, 0);
        M32 -= a.get(2, 1);
        M33 -= a.get(2, 2);
        return *this;
    };

    // skalar multiplikation

    Matrix<3, 3> operator*(double k)
    {
        double data[9] = {
            M11*k, M12 * k, M13 * k,
            M21 * k, M22 * k, M23 * k,
            M31 * k, M32 * k, M33 * k};
        return Matrix<3, 3>(data);
    };

    Matrix33 &operator*=(double k)
    {
        M11 *= k;
        M12 *= k;
        M13 *= k;
        M21 *= k;
        M22 *= k;
        M23 *= k;
        M31 *= k;
        M32 *= k;
        M33 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix33 &operator*=(Matrix<3, 3> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));

        *(neueDaten) = M11*m.get(0, 0) + M12 * m.get(1, 0) + M13 * m.get(2, 0);
        *(neueDaten + 1) = M11*m.get(0, 1) + M12 * m.get(1, 1) + M11*m.get(2, 1);
        *(neueDaten + 2) = M11*m.get(0, 2) + M12 * m.get(1, 2) + M11*m.get(2, 2);

        *(neueDaten + 3) = M21 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0);
        *(neueDaten + 4) = M21 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1);
        *(neueDaten + 5) = M21 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2);

        *(neueDaten + 6) = M31 * m.get(0, 0) + M32 * m.get(1, 0) + M33 * m.get(2, 0);
        *(neueDaten + 7) = M31 * m.get(0, 1) + M32 * m.get(1, 1) + M33 * m.get(2, 1);
        *(neueDaten + 8) = M31 * m.get(0, 2) + M32 * m.get(1, 2) + M33 * m.get(2, 2);

        free(daten);
        daten = neueDaten;
        return *this;
    };
};

#undef M11
#undef M12
#undef M13
#undef M21
#undef M22
#undef M23
#undef M31
#undef M32
#undef M33