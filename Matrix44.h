#pragma once
#include "Matrix.h"

#define M11 (*(daten))
#define M12 (*(daten + 1))
#define M13 (*(daten + 2))
#define M14 (*(daten + 3))
#define M21 (*(daten + 4))
#define M22 (*(daten + 5))
#define M23 (*(daten + 6))
#define M24 (*(daten + 7))
#define M31 (*(daten + 8))
#define M32 (*(daten + 9))
#define M33 (*(daten + 10))
#define M34 (*(daten + 11))
#define M41 (*(daten + 12))
#define M42 (*(daten + 13))
#define M43 (*(daten + 14))
#define M44 (*(daten + 15))

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
        m.set(0, 1, M21);
        m.set(0, 2, M31);
        m.set(0, 3, M41);
        m.set(1, 2, M32);
        m.set(1, 3, M42);
        m.set(2, 3, M43);

        m.set(1, 0, M12);
        m.set(2, 0, M13);
        m.set(2, 1, M23);
        m.set(3, 0, M14);
        m.set(3, 1, M24);
        m.set(3, 2, M34);
        return m;
    };

    // mathematik addition/subtraktion

    Matrix<4, 4> operator+(Matrix<4, 4> &a)
    {
        double data[16] = {
            M11 + a.get(0, 0), M12 + a.get(0, 1), M13 + a.get(0, 2), M14 + a.get(0, 3),
            M21 + a.get(1, 0), M22 + a.get(1, 1), M23 + a.get(1, 2), M24 + a.get(1, 3),
            M31 + a.get(2, 0), M32 + a.get(2, 1), M33 + a.get(2, 2), M34 + a.get(2, 3),
            M41 + a.get(3, 0), M42 + a.get(3, 1), M43 + a.get(3, 2), M44 + a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator+=(Matrix<4, 4> &a)
    {
        M11 += a.get(0, 0);
        M12 += a.get(0, 1);
        M13 += a.get(0, 2);
        M14 += a.get(0, 3);
        M21 += a.get(1, 0);
        M22 += a.get(1, 1);
        M23 += a.get(1, 2);
        M24 += a.get(1, 3);
        M31 += a.get(2, 0);
        M32 += a.get(2, 1);
        M33 += a.get(2, 2);
        M34 += a.get(2, 3);
        M41 += a.get(3, 0);
        M42 += a.get(3, 1);
        M43 += a.get(3, 2);
        M44 += a.get(3, 3);
        return *this;
    };

    Matrix<4, 4> operator-(Matrix<4, 4> &a)
    {
        double data[16] = {
            M11-a.get(0, 0), M12 - a.get(0, 1), M13 - a.get(0, 2), M14 - a.get(0, 3),
            M21 - a.get(1, 0), M22 - a.get(1, 1), M23 - a.get(1, 2), M24 - a.get(1, 3),
            M31 - a.get(2, 0), M32 - a.get(2, 1), M33 - a.get(2, 2), M34 - a.get(2, 3),
            M41 - a.get(3, 0), M42 - a.get(3, 1), M43 - a.get(3, 2), M44 - a.get(3, 3)};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator-=(Matrix<4, 4> &a)
    {
        M11 -= a.get(0, 0);
        M12 -= a.get(0, 1);
        M13 -= a.get(0, 2);
        M14 -= a.get(0, 3);
        M21 -= a.get(1, 0);
        M22 -= a.get(1, 1);
        M23 -= a.get(1, 2);
        M24 -= a.get(1, 3);
        M31 -= a.get(2, 0);
        M32 -= a.get(2, 1);
        M33 -= a.get(2, 2);
        M34 -= a.get(2, 3);
        M41 -= a.get(3, 0);
        M42 -= a.get(3, 1);
        M43 -= a.get(3, 2);
        M44 -= a.get(3, 3);
        return *this;
    };

    // skalar multiplikation

    Matrix<4, 4> operator*(double k)
    {
        double data[16] = {
            M11*k, M12 * k, M13 * k, M14 * k,
            M21 * k, M22 * k, M23 * k, M24 * k,
            M31 * k, M32 * k, M33 * k, M34 * k,
            M41 * k, M42 * k, M43 * k, M44 * k};
        return Matrix<4, 4>(data);
    };

    Matrix44 &operator*=(double k)
    {
        M11 *= k;
        M12 *= k;
        M13 *= k;
        M14 *= k;
        M21 *= k;
        M22 *= k;
        M23 *= k;
        M24 *= k;
        M31 *= k;
        M32 *= k;
        M33 *= k;
        M34 *= k;
        M41 *= k;
        M42 *= k;
        M43 *= k;
        M44 *= k;
        return *this;
    };

    // matrix multiplikation

    Matrix44 &operator*=(Matrix<4, 4> &m)
    {
        double *neueDaten = (double *)malloc(4 * sizeof(double));
        
        *(neueDaten) = M11*m.get(0, 0) + M12 * m.get(1, 0) + M13 * m.get(2, 0) + M14 * m.get(3, 0);
        *(neueDaten + 1) = M11*m.get(0, 1) + M12 * m.get(1, 1) + M11*m.get(2, 1) + M14 * m.get(3, 1);
        *(neueDaten + 2) = M11*m.get(0, 2) + M12 * m.get(1, 2) + M11*m.get(2, 2) + M14 * m.get(3, 2);
        *(neueDaten + 3) = M11*m.get(0, 3) + M12 * m.get(1, 3) + M11*m.get(2, 3) + M14 * m.get(3, 3);

        *(neueDaten + 4) = M21 * m.get(0, 0) + M22 * m.get(1, 0) + M23 * m.get(2, 0) + M24 * m.get(3, 0);
        *(neueDaten + 5) = M21 * m.get(0, 1) + M22 * m.get(1, 1) + M23 * m.get(2, 1) + M24 * m.get(3, 1);
        *(neueDaten + 6) = M21 * m.get(0, 2) + M22 * m.get(1, 2) + M23 * m.get(2, 2) + M24 * m.get(3, 2);
        *(neueDaten + 7) = M21 * m.get(0, 3) + M22 * m.get(1, 3) + M23 * m.get(2, 3) + M24 * m.get(3, 3);
        
        *(neueDaten + 8) = M31 * m.get(0, 0) + M32 * m.get(1, 0) + M33 * m.get(2, 0) + M34 * m.get(3, 0);
        *(neueDaten + 9) = M31 * m.get(0, 1) + M32 * m.get(1, 1) + M33 * m.get(2, 1) + M34 * m.get(3, 1);
        *(neueDaten + 10) = M31 * m.get(0, 2) + M32 * m.get(1, 2) + M33 * m.get(2, 2) + M34 * m.get(3, 2);
        *(neueDaten + 11) = M31 * m.get(0, 3) + M32 * m.get(1, 3) + M33 * m.get(2, 3) + M34 * m.get(3, 3);
        
        *(neueDaten + 12) = M41 * m.get(0, 0) + M42 * m.get(1, 0) + M43 * m.get(2, 0) + M44 * m.get(3, 0);
        *(neueDaten + 13) = M41 * m.get(0, 1) + M42 * m.get(1, 1) + M43 * m.get(2, 1) + M44 * m.get(3, 1);
        *(neueDaten + 14) = M41 * m.get(0, 2) + M42 * m.get(1, 2) + M43 * m.get(2, 2) + M44 * m.get(3, 2);
        *(neueDaten + 15) = M41 * m.get(0, 3) + M42 * m.get(1, 3) + M43 * m.get(2, 3) + M44 * m.get(3, 3);

        free(daten);
        daten = neueDaten;
        return *this;
    };
};

#undef M11
#undef M12
#undef M13
#undef M14
#undef M21
#undef M22
#undef M23
#undef M24
#undef M31
#undef M32
#undef M33
#undef M34
#undef M41
#undef M42
#undef M43
#undef M44