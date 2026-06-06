#pragma once

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

#include <string>
#include <malloc.h>

class Matrix44 : public Matrix<4, 4>
{
public:
    Matrix44() : Matrix<4, 4>() {};
    Matrix44(double data[16]) : Matrix<4, 4>(data) {};
    Matrix44(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33) : Matrix<4, 4>(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33) {};

    /*
     * ergibt die Transponierung der Matrix
     */
    inline Matrix44 transpose()
    {
        Matrix44 m = Matrix44(daten);
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

    inline Matrix44 operator+(Matrix44 &a)
    {
        return Matrix44(M00 + a.get(0, 0), M01 + a.get(0, 1), M02 + a.get(0, 2), M03 + a.get(0, 3),
                        M10 + a.get(1, 0), M11 + a.get(1, 1), M12 + a.get(1, 2), M13 + a.get(1, 3),
                        M20 + a.get(2, 0), M21 + a.get(2, 1), M22 + a.get(2, 2), M23 + a.get(2, 3),
                        M30 + a.get(3, 0), M31 + a.get(3, 1), M32 + a.get(3, 2), M33 + a.get(3, 3));
    };

    inline Matrix44 &operator+=(Matrix44 &a)
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

    inline Matrix44 operator-(Matrix44 &a)
    {
        return Matrix44(M00 - a.get(0, 0), M01 - a.get(0, 1), M02 - a.get(0, 2), M03 - a.get(0, 3),
                        M10 - a.get(1, 0), M11 - a.get(1, 1), M12 - a.get(1, 2), M13 - a.get(1, 3),
                        M20 - a.get(2, 0), M21 - a.get(2, 1), M22 - a.get(2, 2), M23 - a.get(2, 3),
                        M30 - a.get(3, 0), M31 - a.get(3, 1), M32 - a.get(3, 2), M33 - a.get(3, 3));
    };

    inline Matrix44 &operator-=(Matrix44 &a)
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

    inline Matrix44 operator*(double k)
    {
        return Matrix44(M00 * k, M01 * k, M02 * k, M03 * k,
                        M10 * k, M11 * k, M12 * k, M13 * k,
                        M20 * k, M21 * k, M22 * k, M23 * k,
                        M30 * k, M31 * k, M32 * k, M33 * k);
    };

    inline Matrix44 &operator*=(double k)
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

    inline Matrix44 operator*(Matrix44 &m)
    {
        Matrix44 result = Matrix44();

        result.set(0, 0, M00 * m.get(0, 0) + M01 * m.get(1, 0) + M02 * m.get(2, 0) + M03 * m.get(3, 0));
        result.set(0, 1, M00 * m.get(0, 1) + M01 * m.get(1, 1) + M02 * m.get(2, 1) + M03 * m.get(3, 1));
        result.set(0, 2, M00 * m.get(0, 2) + M01 * m.get(1, 2) + M02 * m.get(2, 2) + M03 * m.get(3, 2));
        result.set(0, 3, M00 * m.get(0, 3) + M01 * m.get(1, 3) + M02 * m.get(2, 3) + M03 * m.get(3, 3));

        result.set(1, 0, M10 * m.get(0, 0) + M11 * m.get(1, 0) + M12 * m.get(2, 0) + M13 * m.get(3, 0));
        result.set(1, 1, M10 * m.get(0, 1) + M11 * m.get(1, 1) + M12 * m.get(2, 1) + M13 * m.get(3, 1));
        result.set(1, 2, M10 * m.get(0, 2) + M11 * m.get(1, 2) + M12 * m.get(2, 2) + M13 * m.get(3, 2));
        result.set(1, 3, M10 * m.get(0, 3) + M11 * m.get(1, 3) + M12 * m.get(2, 3) + M13 * m.get(3, 3));

        result.set(2, 0, M20 * m.get(0, 0) + M21 * m.get(1, 0) + M22 * m.get(2, 0) + M23 * m.get(3, 0));
        result.set(2, 1, M20 * m.get(0, 1) + M21 * m.get(1, 1) + M22 * m.get(2, 1) + M23 * m.get(3, 1));
        result.set(2, 2, M20 * m.get(0, 2) + M21 * m.get(1, 2) + M22 * m.get(2, 2) + M23 * m.get(3, 2));
        result.set(2, 3, M20 * m.get(0, 3) + M21 * m.get(1, 3) + M22 * m.get(2, 3) + M23 * m.get(3, 3));

        result.set(3, 0, M30 * m.get(0, 0) + M31 * m.get(1, 0) + M32 * m.get(2, 0) + M33 * m.get(3, 0));
        result.set(3, 1, M30 * m.get(0, 1) + M31 * m.get(1, 1) + M32 * m.get(2, 1) + M33 * m.get(3, 1));
        result.set(3, 2, M30 * m.get(0, 2) + M31 * m.get(1, 2) + M32 * m.get(2, 2) + M33 * m.get(3, 2));
        result.set(3, 3, M30 * m.get(0, 3) + M31 * m.get(1, 3) + M32 * m.get(2, 3) + M33 * m.get(3, 3));

        return result;
    };

    inline Matrix44 &operator*=(Matrix44 &m)
    {
        double m00 = M00, m01 = M01, m02 = M02, m03 = M03,
               m10 = M10, m11 = M11, m12 = M12, m13 = M13,
               m20 = M20, m21 = M21, m22 = M22, m23 = M23,
               m30 = M30, m31 = M31, m32 = M32, m33 = M33;

        M00 = m00 * m.get(0, 0) + m01 * m.get(1, 0) + m02 * m.get(2, 0) + m03 * m.get(3, 0);
        M01 = m00 * m.get(0, 1) + m01 * m.get(1, 1) + m02 * m.get(2, 1) + m03 * m.get(3, 1);
        M02 = m00 * m.get(0, 2) + m01 * m.get(1, 2) + m02 * m.get(2, 2) + m03 * m.get(3, 2);
        M03 = m00 * m.get(0, 3) + m01 * m.get(1, 3) + m02 * m.get(2, 3) + m03 * m.get(3, 3);

        M10 = m10 * m.get(0, 0) + m11 * m.get(1, 0) + m12 * m.get(2, 0) + m13 * m.get(3, 0);
        M11 = m10 * m.get(0, 1) + m11 * m.get(1, 1) + m12 * m.get(2, 1) + m13 * m.get(3, 1);
        M12 = m10 * m.get(0, 2) + m11 * m.get(1, 2) + m12 * m.get(2, 2) + m13 * m.get(3, 2);
        M13 = m10 * m.get(0, 3) + m11 * m.get(1, 3) + m12 * m.get(2, 3) + m13 * m.get(3, 3);

        M20 = m20 * m.get(0, 0) + m21 * m.get(1, 0) + m22 * m.get(2, 0) + m23 * m.get(3, 0);
        M21 = m20 * m.get(0, 1) + m21 * m.get(1, 1) + m22 * m.get(2, 1) + m23 * m.get(3, 1);
        M22 = m20 * m.get(0, 2) + m21 * m.get(1, 2) + m22 * m.get(2, 2) + m23 * m.get(3, 2);
        M23 = m20 * m.get(0, 3) + m21 * m.get(1, 3) + m22 * m.get(2, 3) + m23 * m.get(3, 3);

        M30 = m30 * m.get(0, 0) + m31 * m.get(1, 0) + m32 * m.get(2, 0) + m33 * m.get(3, 0);
        M31 = m30 * m.get(0, 1) + m31 * m.get(1, 1) + m32 * m.get(2, 1) + m33 * m.get(3, 1);
        M32 = m30 * m.get(0, 2) + m31 * m.get(1, 2) + m32 * m.get(2, 2) + m33 * m.get(3, 2);
        M33 = m30 * m.get(0, 3) + m31 * m.get(1, 3) + m32 * m.get(2, 3) + m33 * m.get(3, 3);

        return *this;
    };

    template <int Spalten>
    inline Matrix<Spalten, 4> operator*(Matrix<4, Spalten> &m)
    {
        Matrix<Spalten, 4> result = Matrix<Spalten, 4>();
        for (int z = 0; z < Spalten; z++)
        {
            result.set(0, z, M00 * m.get(0, z) + M01 * m.get(1, z) + M02 * m.get(2, z) + M03 * m.get(3, z));
            result.set(1, z, M10 * m.get(0, z) + M11 * m.get(1, z) + M12 * m.get(2, z) + M13 * m.get(3, z));
            result.set(2, z, M20 * m.get(0, z) + M21 * m.get(1, z) + M22 * m.get(2, z) + M23 * m.get(3, z));
            result.set(3, z, M30 * m.get(0, z) + M31 * m.get(1, z) + M32 * m.get(2, z) + M33 * m.get(3, z));
        };
        return result;
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