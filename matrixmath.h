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
    double neueDaten[Spalten];
    for (int z = 0; z < Zeilen; z++)
    {
        int sum = 0;
        for (int s = 0; s < Spalten; s++)
        {
            sum += *wertPtr(z, s) * v.get(z);
        };
        neueDaten[z] = sum;
    };
    return Vector<Spalten>(neueDaten);
};

Vector2 operator*(Matrix22 &m, Vector<2> &v)
{
    double neueDaten[2] = {
        m.get(0) * v.get(0) + m.get(1) * v.get(1),
        m.get(2) * v.get(0) + m.get(3) * v.get(1)};
    return Vector2(neueDaten);
};

Vector3 operator*(Matrix33 &m, Vector<3> &v)
{
    double neueDaten[3] = {
        m.get(0) * v.get(0) + m.get(1) * v.get(1) + m.get(2) * v.get(2),
        m.get(3) * v.get(0) + m.get(4) * v.get(1) + m.get(5) * v.get(2),
        m.get(6) * v.get(0) + m.get(7) * v.get(1) + m.get(8) * v.get(2)};
    return Vector3(neueDaten);
};

Vector4 operator*(Matrix44 &m, Vector<4> &v)
{
    double neueDaten[4] = {
        m.get(0) * v.get(0) + m.get(1) * v.get(1) + m.get(2) * v.get(2) + m.get(3) * v.get(3),
        m.get(4) * v.get(0) + m.get(5) * v.get(1) + m.get(6) * v.get(2) + m.get(7) * v.get(3),
        m.get(8) * v.get(0) + m.get(9) * v.get(1) + m.get(10) * v.get(2) + m.get(11) * v.get(3),
        m.get(12) * v.get(0) + m.get(13) * v.get(1) + m.get(14) * v.get(2) + m.get(15) * v.get(3)};
    return Vector4(neueDaten);
};

/*
 * multipliziert den Vektor mit einer Matrix, wo deren Spaltenlänge gleich wie die Länge des Vektors ist
 */
template <int Länge, int Spalten>
Vector<Spalten> operator*(Vector<Länge> &v, Matrix<Länge, Spalten> &m)
{
    double neueDaten[Spalten];
    for (int i = 0; i < Spalten; i++)
    {
        double sum = 0;
        for (int j = 0; j < Länge; j++)
        {
            sum += v.get(j) * m.get(j, i);
        };
        *(neueDaten + i) = sum;
    };
    return Vector<Spalten>(neueDaten);
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
        neueDaten[i] = v.get(0) * m.get(0, i) + v.get(1) * m.get(1, i);
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
        neueDaten[i] = v.get(0) * m.get(0, i) + v.get(1) * m.get(1, i) + v.get(2) * m.get(2, i);
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