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

#include <string>
#include <malloc.h>

class Matrix33 : public Matrix<3, 3>
{
public:
    Matrix33() : Matrix<3, 3>() {};
    Matrix33(double data[9]) : Matrix<3, 3>(data) {};

    Matrix33(double m00, double m01, double m02,
             double m10, double m11, double m12,
             double m20, double m21, double m22) : Matrix<3, 3>()
    {
        M00 = m00;
        M01 = m01;
        M02 = m02;
        M10 = m10;
        M11 = m11;
        M12 = m12;
        M20 = m20;
        M21 = m21;
        M22 = m22;
    };

    /*
     * ergibt die Transponierung der Matrix
     */
    inline Matrix33 transpose()
    {
        return Matrix33(M00, M10, M20,
                        M01, M11, M21,
                        M02, M12, M22);
    };

    inline double determinant()
    {
        return M00 * (M11 * M22 - M12 * M21) - M01 * (M10 * M22 - M12 * M20) + M02 * (M10 * M21 - M11 * M20);
    }

    // mathematik addition/subtraktion

    inline Matrix33 operator+(Matrix33 &a)
    {
        return Matrix33(M00 + a.get(0, 0), M01 + a.get(0, 1), M02 + a.get(0, 2),
                        M10 + a.get(1, 0), M11 + a.get(1, 1), M12 + a.get(1, 2),
                        M20 + a.get(2, 0), M21 + a.get(2, 1), M22 + a.get(2, 2));
    };

    inline Matrix33 &operator+=(Matrix33 &a)
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

    inline Matrix33 operator-(Matrix33 &a)
    {
        return Matrix33(M00 - a.get(0, 0), M01 - a.get(0, 1), M02 - a.get(0, 2),
                        M10 - a.get(1, 0), M11 - a.get(1, 1), M12 - a.get(1, 2),
                        M20 - a.get(2, 0), M21 - a.get(2, 1), M22 - a.get(2, 2));
    };

    inline Matrix33 &operator-=(Matrix33 &a)
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

    inline Matrix33 operator*(double k)
    {
        return Matrix33(M00 * k, M01 * k, M02 * k,
                        M10 * k, M11 * k, M12 * k,
                        M20 * k, M21 * k, M22 * k);
    };

    inline Matrix33 &operator*=(double k)
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

    inline Matrix33 operator*(Matrix33 &m)
    {
        return Matrix33(M00 * m.get(0, 0) + M01 * m.get(1, 0) + M02 * m.get(2, 0),
                        M00 * m.get(0, 1) + M01 * m.get(1, 1) + M02 * m.get(2, 1),
                        M00 * m.get(0, 2) + M01 * m.get(1, 2) + M02 * m.get(2, 2),

                        M10 * m.get(0, 0) + M11 * m.get(1, 0) + M12 * m.get(2, 0),
                        M10 * m.get(0, 1) + M11 * m.get(1, 1) + M12 * m.get(2, 1),
                        M10 * m.get(0, 2) + M11 * m.get(1, 2) + M12 * m.get(2, 2),

                        M20 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0),
                        M20 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1),
                        M20 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2));
    };

    inline Matrix33 &operator*=(Matrix33 &m)
    {
        double m00 = M00, m01 = M01, m02 = M02,
               m10 = M10, m11 = M11, m12 = M12,
               m20 = M20, m21 = M21, m22 = M22;

        M00 = m00 * m.get(0, 0) + m01 * m.get(1, 0) + m02 * m.get(2, 0);
        M01 = m00 * m.get(0, 1) + m01 * m.get(1, 1) + m02 * m.get(2, 1);
        M02 = m00 * m.get(0, 2) + m01 * m.get(1, 2) + m02 * m.get(2, 2);

        M10 = m10 * m.get(0, 0) + m11 * m.get(1, 0) + m12 * m.get(2, 0);
        M11 = m10 * m.get(0, 1) + m11 * m.get(1, 1) + m12 * m.get(2, 1);
        M12 = m10 * m.get(0, 2) + m11 * m.get(1, 2) + m12 * m.get(2, 2);

        M20 = m20 * m.get(0, 0) + m21 * m.get(1, 0) + m22 * m.get(2, 0);
        M21 = m20 * m.get(0, 1) + m21 * m.get(1, 1) + m22 * m.get(2, 1);
        M22 = m20 * m.get(0, 2) + m21 * m.get(1, 2) + m22 * m.get(2, 2);

        return *this;
    };

    template <int Spalten>
    inline Matrix<Spalten, 3> operator*(Matrix<3, Spalten> &m)
    {
        Matrix<Spalten, 3> result = Matrix<Spalten, 3>();
        for (int z = 0; z < Spalten; z++)
        {
            result.set(z, 0, M00 * m.get(0, z) + M01 * m.get(1, z) + M02 * m.get(2, z));
            result.set(z, 1, M10 * m.get(0, z) + M11 * m.get(1, z) + M12 * m.get(2, z));
            result.set(z, 2, M20 * m.get(0, z) + M21 * m.get(1, z) + M22 * m.get(2, z));
        };
        return result;
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