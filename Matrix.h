#pragma once

#include <malloc.h>
#include <cstring>

#include "matrixmath.h"

template <int Zeilen, int Spalten>
class Matrix
{

protected:
    double *daten; // Einträge der Matrix

    /*
     * ergibt den Pointer eines Eintrages der Matrix, erzeugt von einem Offset des "Daten"-Pointers
     */
    double *wertPtr(int z, int s)
    {
        int offset = (z * Spalten + s);
        return daten + offset;
    };

    /*
     * ergibt den Pointer eines Eintrages der Matrix, erzeugt von einem Offset des eingegebenen "d"-Pointers
     */
    double *wertPtr(double *d, int z, int s)
    {
        int offset = (z * Spalten + s);
        return d + offset;
    };

public:
    /*
     * erzeugt eine Nullmatrix mit den gegebenen Zeilen- und Spaltenlängen
     */
    Matrix()
    {
        daten = (double *)std::malloc(Zeilen * Spalten * sizeof(double));
    };

    /*
     * erzeugt eine Matrix mit den gegebenen Zeilen- und Spaltenlängen, sowie die eingegebenen Einträge
     */
    Matrix(double data[Zeilen * Spalten])
    {
        daten = (double *)std::malloc(Zeilen * Spalten * sizeof(double));
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                *wertPtr(z, s) = *wertPtr(data, z, s);
            };
        };
    };

    /*
     * lässt den Speicherraum der Daten der Matrix frei
     */
    ~Matrix()
    {
        free(daten);
    };

    /*
     * gibt den Wert des Eintrags zur eingegebenen Position zurück
     */
    double get(int z, int s)
    {
        return *wertPtr(z, s);
    };

    /*
     * ändert den Wert des Eintrags zur eingegebenen Position
     */
    void set(int z, int s, double d)
    {
        *wertPtr(z, s) = d;
    };

    /*
     * ergibt die Transponierung der Matrix, ohne dass deren Daten geändert wird
     */
    Matrix<Spalten, Zeilen> transpose()
    {
        Matrix<Spalten, Zeilen> m = Matrix<Spalten, Zeilen>();
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                m.set(s, z, *(daten + z * Spalten + s));
                if (s == z || z >= Spalten || s >= Zeilen)
                    continue;
                m.set(z, s, *(daten + s * Spalten + z));
            };
        };
        return m;
    };

    // mathematik addition/subtraktion

    /*
     * Standardaddition zwischen zwei Matrixen mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    Matrix<Zeilen, Spalten> operator+(Matrix<Zeilen, Spalten> &a)
    {
        Matrix<Zeilen, Spalten> c = Matrix<Zeilen, Spalten>();
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                *c.wertPtr(z, s) = *wertPtr(z, s) + a.get(z, s);
            };
        };
        return c;
    };

    /*
     * Standardaddition zwischen zwei Matrixen mit gleichen Dimensionen, wobei die Daten der linken Matrix geändert werden
     */
    Matrix<Zeilen, Spalten> &operator+=(Matrix<Zeilen, Spalten> &a)
    {
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                *wertPtr(z, s) += a.get(z, s);
            };
        };
        return *this;
    };

    /*
     * Standardsubtraktion zwischen zwei Matrixen mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    Matrix<Zeilen, Spalten> operator-(Matrix<Zeilen, Spalten> &a)
    {
        Matrix<Zeilen, Spalten> c = Matrix<Zeilen, Spalten>();
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                c.set(z, s, *wertPtr(z, s) - a.get(z, s));
            };
        };
        return c;
    };

    /*
     * Standardsubtraktion zwischen zwei Matrixen mit gleichen Dimensionen, wobei die Daten der linken Matrix geändert werden
     */
    Matrix<Zeilen, Spalten> &operator-=(Matrix<Zeilen, Spalten> &a)
    {
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                *wertPtr(z, s) -= *a.wertPtr(z, s);
            };
        };
        return *this;
    };

    // skalar multiplikation

    /*
     * multipliziert jeden Eintrag der Matrix mit dem Faktor k, ohne Datenänderung
     */
    Matrix<Zeilen, Spalten> operator*(double k)
    {
        Matrix<Zeilen, Spalten> c = Matrix<Zeilen, Spalten>();
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                double d = (*wertPtr(z, s)) * k;
                c.set(z, s, d);
            };
        };
        return c;
    };

    /*
     * multipliziert jeden Eintrag der Matrix mit dem Faktor k
     */
    Matrix<Zeilen, Spalten> &operator*=(double k)
    {
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                *wertPtr(z, s) *= k;
            };
        };
        return *this;
    };

    // matrix multiplikation

    /*
     * multipliziert zwei Matrixen mit einer gemeinsamen Dimension miteinander durch Standard-Matrixenmultiplikation und ohne Datenänderung
     */
    template <int Spalten2>
    Matrix<Zeilen, Spalten2> operator*(Matrix<Spalten, Spalten2> &a)
    {
        Matrix<Zeilen, Spalten2> m = Matrix<Zeilen, Spalten2>();
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten2; s++)
            {
                double sum = 0;
                for (int i = 0; i < Spalten; i++)
                {
                    sum += (*wertPtr(z, i)) * a.get(i, s);
                };
                m.set(z, s, sum);
            };
        };
        return m;
    };

    /*
     * multipliziert diese Matrix mit einer anderen mit gleicher Spaltenlänge durch Standard-Matrixenmultiplikation und mit Datenänderung
     */
    Matrix<Zeilen, Spalten> &operator*=(Matrix<Spalten, Spalten> &m)
    {
        double *neueDaten = (double *)malloc(Zeilen * Spalten * sizeof(double));
        for (int z = 0; z < Zeilen; z++)
        {
            for (int s = 0; s < Spalten; s++)
            {
                double sum = 0;
                for (int i = 0; i < Spalten; i++)
                {
                    sum += (*wertPtr(z, i)) * m.get(i, s);
                };
                *wertPtr(neueDaten, z, s) = sum;
            };
        };
        free(daten);
        daten = neueDaten;
        return *this;
    };

    // Vectorenmultiplikation

    /*
     * multipliziert eine Matrix mit einem Vektor und ergibt jenen Vektor
     */
    Vector<Spalten> operator*(Vector<Spalten> &v)
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

    // string repräsentation

    /*
     * repräsentiert die Matrix und deren Einträge als ein String
     */
    std::string _str()
    {
        std::string out = "[\n";
        for (int z = 0; z < Zeilen; z++)
        {
            out += "\t";
            for (int s = 0; s < Spalten; s++)
            {
                out += std::to_string(*wertPtr(z, s)) + "\t";
            };
            out += '\n';
        };
        out += ']';
        return out;
    };
};