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
 * multipliziert den Vektor mit einer Matrix, wo deren Spaltenlänge gleich wie die Länge des Vektors ist
 */
template <int Länge, int Zeilen>
Vector<Zeilen> operator*(Vector<Länge> &v, Matrix<Zeilen, Länge> &m)
{
    double neueDaten[Länge];
    for (int i = 0; i < Länge; i++)
    {
        double sum = 0;
        for (int j = 0; j < Zeilen; j++)
        {
            sum += v.get(j) * m.get(j, i);
        };
        *(neueDaten + i) = sum;
    };
    return Vector<Zeilen>(neueDaten);
};

/*
 * multipliziert den Vektor mit einer Matrix, wo deren Spalten- und Zeilenlängen gleich wie die Länge des Vektors ist
 */
template <int Länge>
Vector<Länge> &operator*=(Vector<Länge> &v, Matrix<Länge, Länge> &m)
{
    double *neueDaten = malloc(Länge * sizeof(double));
    for (int i = 0; i < Länge; i++)
    {
        double sum = 0;
        for (int j = 0; j < Länge; j++)
        {
            sum += v.get(j) * m.get(i, j);
        };
        *(neueDaten + i) = sum;
    };
    v.replace(neueDaten);
    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector2 &v, Matrix<Zeilen, 2> &m)
{
    double neueDaten[Zeilen];
    for (int i = 0; i < Zeilen; i++)
    {
        neueDaten[i] = v.get(0)*m.get(i, 0) + v.get(1) * m.get(i, 1);
    };
    return Vector<Zeilen>(neueDaten);
};

Vector2 &operator*=(Vector2 &v, Matrix<2, 2> &m)
{
    double *neueDaten = (double *)malloc(2 * sizeof(double));
    *(neueDaten) = v.get(0) * m.get(0, 0) + v.get(1) * m.get(1, 0);
    *(neueDaten + 1) = v.get(0) * m.get(0, 1) + v.get(1) * m.get(1, 1);
    v.replace(neueDaten);
    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector3 &v, Matrix<Zeilen, 3> &m)
{
    double neueDaten[Zeilen];
    for (int i = 0; i < Zeilen; i++)
    {
        neueDaten[i] = v.get(0) * m.get(i, 0) + v.get(1) * m.get(i, 1) + v.get(2) * m.get(i, 2);
    };
    return Vector<Zeilen>(neueDaten);
};

Vector3 &operator*=(Vector3 &v, Matrix<3, 3> &m)
{
    double *neueDaten = (double *)malloc(3 * sizeof(double));
    *(neueDaten) = v.get(0) * m.get(0, 0) + v.get(1) * m.get(1, 0) + v.get(2) * m.get(2, 0);
    *(neueDaten + 1) = v.get(0) * m.get(0, 1) + v.get(1) * m.get(1, 1) + v.get(2) * m.get(2, 1);
    *(neueDaten + 2) = v.get(0) * m.get(0, 2) + v.get(1) * m.get(1, 2) + v.get(2) * m.get(2, 2);
    v.replace(neueDaten);
    return v;
};

template <int Zeilen>
Vector<Zeilen> operator*(Vector4 &v, Matrix<Zeilen, 4> &m)
{
    double neueDaten[Zeilen];
    for (int i = 0; i < Zeilen; i++)
    {
        neueDaten[i] = v.get(0) * m.get(i, 0) + v.get(1) * m.get(i, 1) + v.get(2) * m.get(i, 2) + v.get(3) * m.get(i, 3);
    };
    return Vector<Zeilen>(neueDaten);
};

Vector4 &operator*=(Vector4 &v, Matrix<4, 4> &m)
{
    double *neueDaten = (double *)malloc(4 * sizeof(double));
    *(neueDaten) = v.get(0) * m.get(0, 0) + v.get(1) * m.get(0, 1) + v.get(2) * m.get(0, 2) + v.get(3) * m.get(0, 3);
    *(neueDaten + 1) = v.get(0) * m.get(1, 0) + v.get(1) * m.get(1, 1) + v.get(2) * m.get(1, 2) + v.get(3) * m.get(1, 3);
    *(neueDaten + 2) = v.get(0) * m.get(2, 0) + v.get(1) * m.get(2, 1) + v.get(2) * m.get(2, 2) + v.get(3) * m.get(2, 3);
    *(neueDaten + 3) = v.get(0) * m.get(3, 0) + v.get(1) * m.get(3, 1) + v.get(2) * m.get(3, 2) + v.get(3) * m.get(3, 3);
    v.replace(neueDaten);
    return v;
};