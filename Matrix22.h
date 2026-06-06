#pragma once

#define M00 (*(daten))
#define M01 (*(daten + 1))
#define M10 (*(daten + 2))
#define M11 (*(daten + 3))

#include "Matrix.h"

#include <string>
#include <malloc.h>

class Matrix22 : public Matrix<2, 2>
{
public:
    Matrix22() : Matrix<2, 2>() {};
    Matrix22(double data[4]) : Matrix<2, 2>(data) {};
    Matrix22(double m00, double m01, double m10, double m11) : Matrix<2, 2>(m00, m01, m10, m11) {};

    /*
     * ergibt die Transponierung der Matrix
     */
    inline Matrix22 transpose()
    {
        return Matrix22(M00, M10, M01, M11);
    };

    inline double determinant()
    {
        return (M00 * M11) - (M01 * M10);
    };

    inline Matrix22 inverse()
    {
        double d = determinant();
        return Matrix22(M11 / d, -M01 / d,
                        -M10 / d, M00 / d);
    };

    // mathematik addition/subtraktion

    inline Matrix22 operator+(Matrix22 &a)
    {
        return Matrix22(M00 + a.get(0, 0), M01 + a.get(0, 1),
                        M10 + a.get(1, 0), M11 + a.get(1, 1));
    };

    inline Matrix22 &operator+=(Matrix22 &a)
    {
        M00 += a.get(0, 0);
        M01 += a.get(0, 1);
        M10 += a.get(1, 0);
        M11 += a.get(1, 1);
        return *this;
    };

    inline Matrix22 operator-(Matrix22 &a)
    {
        return Matrix22(M00 - a.get(0, 0), M01 - a.get(0, 1),
                        M10 - a.get(1, 0), M11 - a.get(1, 1));
    };

    inline Matrix22 &operator-=(Matrix22 &a)
    {
        M00 -= a.get(0, 0);
        M01 -= a.get(0, 1);
        M10 -= a.get(1, 0);
        M11 -= a.get(1, 1);
        return *this;
    };

    // skalar multiplikation

    inline Matrix22 operator*(double k)
    {
        return Matrix22(M00 * k, M01 * k, M10 * k, M11 * k);
    };

    inline Matrix22 &operator*=(double k)
    {
        M00 *= k;
        M01 *= k;
        M10 *= k;
        M11 *= k;
        return *this;
    };

    // matrix multiplikation

    inline Matrix22 operator*(Matrix22 &m)
    {

        return Matrix22(M00 * m.get(0, 0) + M01 * m.get(1, 0), M00 * m.get(0, 1) + M01 * m.get(1, 1),
                        M10 * m.get(0, 0) + M11 * m.get(1, 0), M10 * m.get(0, 1) + M11 * m.get(1, 1));
    };

    inline Matrix22 &operator*=(Matrix22 &m)
    {
        double m00 = M00, m01 = M01, m10 = M10, m11 = M11;
        M00 = m00 * m.get(0, 0) + m01 * m.get(1, 0);
        M01 = m00 * m.get(0, 1) + m01 * m.get(1, 1);
        M10 = m10 * m.get(0, 0) + m11 * m.get(1, 0);
        M11 = m10 * m.get(0, 1) + m11 * m.get(1, 1);
        return *this;
    };

    template <int Spalten>
    inline Matrix<Spalten, 2> operator*(Matrix<2, Spalten> &m)
    {
        Matrix<Spalten, 2> result = Matrix<Spalten, 2>();
        for (int z = 0; z < Spalten; z++)
        {
            result.set(z, 0, M00 * m.get(0, z) + M01 * m.get(1, z));
            result.set(z, 1, M10 * m.get(0, z) + M11 * m.get(1, z));
        };
        return result;
    };
};

#undef M00
#undef M01
#undef M10
#undef M11