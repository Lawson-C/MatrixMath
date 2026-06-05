#pragma once

#include "Vector.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix.h"
#include "Matrix22.h"
#include "Matrix33.h"
#include "Matrix44.h"

/*
 * multipliziert eine Matrix mit einem Vektor und ergibt jenen Vektor
 */
template <int Zeilen, int Spalten>
Vector<Spalten> operator*(Matrix<Zeilen, Spalten> &m, Vector<Spalten> &v)
{
    Vector<Spalten> result = Vector<Spalten>();
    for (int z = 0; z < Zeilen; z++)
    {
        int sum = 0;
        for (int s = 0; s < Spalten; s++)
        {
            sum += m.get(z, s) * v.get(z);
        };
        result.set(z, sum);
    };
    return result;
};

Vector2 operator*(Matrix22 &m, Vector2 &v)
{
    return Vector2(m.get(0, 0) * v.get(0) + m.get(0, 1) * v.get(1),
                   m.get(1, 0) * v.get(0) + m.get(1, 1) * v.get(1));
};

Vector3 operator*(Matrix33 &m, Vector3 &v)
{
    return Vector3(m.get(0, 0) * v.get(0) + m.get(0, 1) * v.get(1) + m.get(0, 2) * v.get(2),
                   m.get(1, 0) * v.get(0) + m.get(1, 1) * v.get(1) + m.get(1, 2) * v.get(2),
                   m.get(2, 0) * v.get(0) + m.get(2, 1) * v.get(1) + m.get(2, 2) * v.get(2));
};

Vector4 operator*(Matrix44 &m, Vector4 &v)
{
    return Vector4(m.get(0, 0) * v.get(0) + m.get(0, 1) * v.get(1) + m.get(0, 2) * v.get(2) + m.get(0, 3) * v.get(3),
                   m.get(1, 0) * v.get(0) + m.get(1, 1) * v.get(1) + m.get(1, 2) * v.get(2) + m.get(1, 3) * v.get(3),
                   m.get(2, 0) * v.get(0) + m.get(2, 1) * v.get(1) + m.get(2, 2) * v.get(2) + m.get(2, 3) * v.get(3),
                   m.get(3, 0) * v.get(0) + m.get(3, 1) * v.get(1) + m.get(3, 2) * v.get(2) + m.get(3, 3) * v.get(3));
};

/*
 * multipliziert den Vektor mit einer Matrix, wo deren Spaltenlänge gleich wie die Länge des Vektors ist
 */
template <int Länge, int Spalten>
Vector<Spalten> operator*(Vector<Länge> &v, Matrix<Länge, Spalten> &m)
{
    Vector<Spalten> result = Vector<Spalten>();
    for (int i = 0; i < Spalten; i++)
    {
        double sum = 0;
        for (int j = 0; j < Länge; j++)
        {
            sum += v.get(j) * m.get(j, i);
        };
        result.set(i, sum);
    };
    return result;
};

/*
 * multipliziert den Vektor mit einer Matrix, wo deren Spalten- und Zeilenlängen gleich wie die Länge des Vektors ist
 */
template <int Länge>
Vector<Länge> &operator*=(Vector<Länge> &v, Matrix<Länge, Länge> &m)
{
    double alteDaten[Länge];
    std::copy(v.daten, v.daten + Länge, alteDaten);
    for (int i = 0; i < Länge; i++)
    {
        double sum = 0;
        for (int j = 0; j < Länge; j++)
        {
            sum += alteDaten[j] * m.get(i, j);
        };
        v.set(i, sum);
    };
    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector2 &v, Matrix<Zeilen, 2> &m)
{
    Vector<Zeilen> result = Vector<Zeilen>();
    for (int i = 0; i < Zeilen; i++)
    {
        result.set(i, v.get(0) * m.get(0, i) + v.get(1) * m.get(1, i));
    };
    return result;
};

Vector2 &operator*=(Vector2 &v, Matrix22 &m)
{
    double v0 = v.get(0), v1 = v.get(1);

    v.set(0, v0 * m.get(0, 0) + v1 * m.get(1, 0));
    v.set(1, v0 * m.get(0, 1) + v1 * m.get(1, 1));

    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector3 &v, Matrix<Zeilen, 3> &m)
{
    Vector<Zeilen> result = Vector<Zeilen>();
    for (int i = 0; i < Zeilen; i++)
    {
        result.set(i, v.get(0) * m.get(0, i) + v.get(1) * m.get(1, i) + v.get(2) * m.get(2, i));
    };
    return result;
};

Vector3 &operator*=(Vector3 &v, Matrix33 &m)
{
    double v0 = v.get(0), v1 = v.get(1), v2 = v.get(2);

    v.set(0, v0 * m.get(0, 0) + v1 * m.get(1, 0) + v2 * m.get(2, 0));
    v.set(1, v0 * m.get(0, 1) + v1 * m.get(1, 1) + v2 * m.get(2, 1));
    v.set(2, v0 * m.get(0, 2) + v1 * m.get(1, 2) + v2 * m.get(2, 2));

    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector4 &v, Matrix<Zeilen, 4> &m)
{
    Vector<Zeilen> result = Vector<Zeilen>();
    for (int i = 0; i < Zeilen; i++)
    {
        result.set(i, v.get(0) * m.get(i, 0) + v.get(1) * m.get(i, 1) + v.get(2) * m.get(i, 2) + v.get(3) * m.get(i, 3));
    };
    return result;
};

Vector4 &operator*=(Vector4 &v, Matrix44 &m)
{
    double v0 = v.get(0), v1 = v.get(1), v2 = v.get(2), v3 = v.get(3);

    v.set(0, v0 * m.get(0, 0) + v1 * m.get(0, 1) + v2 * m.get(0, 2) + v3 * m.get(0, 3));
    v.set(1, v0 * m.get(1, 0) + v1 * m.get(1, 1) + v2 * m.get(1, 2) + v3 * m.get(1, 3));
    v.set(2, v0 * m.get(2, 0) + v1 * m.get(2, 1) + v2 * m.get(2, 2) + v3 * m.get(2, 3));
    v.set(3, v0 * m.get(3, 0) + v1 * m.get(3, 1) + v2 * m.get(3, 2) + v3 * m.get(3, 3));

    return v;
};