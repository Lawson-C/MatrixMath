#pragma once
#include <malloc.h>
#include <cstring>
#include <cmath>

template <int Länge>
class Vector
{
protected:
    double *daten; // Einträge des Vektors

public:
    /*
     * erzeugt einen Nullvektor mit der gegebenen Länge
     */
    Vector()
    {
        daten = std::malloc(Länge * sizeof(double));
    };

    /*
     * erzeugt einen Vektor mit der gegebenen Länge und den gegebenen Daten
     */
    Vector(double data[Länge])
    {
        daten = (double *)std::malloc(Länge * sizeof(double));
        for (int n = 0; n < Länge; n++)
        {
            *(daten + n) = *(data + n);
        };
    };

    /*
     * lässt den Speicherraum des Vektors frei
     */
    ~Vector()
    {
        free(daten);
    };

    /*
     * ersetzt die alten Daten mit den eingegebenen neuen Daten
     */
    void replace(double *neueDaten)
    {
        free(daten);
        daten = neueDaten;
    };

    /*
     * ergibt den Wert zur gegebenen Position des Vektors
     */
    double get(int n)
    {
        return *(daten + n);
    };

    /*
     * ersetzt den Wert zur gegebenen Position des Vektors mit eingegebenem Wert d
     */
    void set(int n, double d)
    {
        *(daten + n) = d;
    };

    /*
     * ergibt die 1D-Länge der Matrix
     */
    double magnitude()
    {
        double sum = 0;
        for (int i = 0; i < Länge; i++)
        {
            sum += *(daten + i) * *(daten + 1);
        };
        return std::sqrt(sum);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    Vector<Länge> &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        for (int i = 0; i < Länge; i++)
        {
            *(daten + i) /= mag;
        };
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    Vector<Länge> getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector<Länge>(daten);
        double normalizierteDaten[Länge] = {};
        for (int i = 0; i < Länge; i++)
        {
            normalizierteDaten[i] = *(daten + i) / mag;
        };
        Vector<Länge> v = Vector<Länge>(normalizierteDaten);
        return v;
    };

    // mathematik addition/subtraktion

    /*
     * Standardaddition zwischen zwei Vektoren mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    Vector<Länge> operator+(Vector<Länge> &b)
    {
        Vector<Länge> c = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            c.set(n, this->get(n) + b.get(n));
        };
        return c;
    };

    /*
     * Standardaddition zwischen zwei Vektoren mit gleichen Dimensionen, wobei die Daten des linken Vektors geändert werden
     */
    Vector<Länge> &operator+=(Vector<Länge> &a)
    {
        for (int n = 0; n < Länge; n++)
        {
            *(daten + n) += *a.get(n);
        };
        return a;
    };

    /*
     * Standardsubtraktion zwischen zwei Vektoren mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    Vector<Länge> operator-(Vector<Länge> &b)
    {
        Vector<Länge> c = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            *c.set(n, this->get(n) - b.get(n));
        };
        return c;
    };

    /*
     * Standardsubtraktion zwischen zwei Vektoren mit gleichen Dimensionen, wobei die Daten des linken Vektors geändert werden
     */
    Vector<Länge> &operator-=(Vector<Länge> &a)
    {
        for (int n = 0; n < Länge; n++)
        {
            *(daten + n) -= a.get(n);
        };
        return a;
    };

    // skalar multiplikation

    /*
     * multipliziert jeden Eintrag des Vektors mit dem Faktor k, ohne Datenänderung
     */
    Vector<Länge> operator*(double k)
    {

        Vector<Länge> v = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            *v.set(n, this->get(n) * k);
        };
        return v;
    };

    /*
     * multipliziert jeden Eintrag der Matrix mit dem Faktor k
     */
    Vector<Länge> &operator*=(double k)
    {
        for (int n = 0; n < Länge; n++)
        {
            *(daten + n) *= *(daten + n) * k;
        };
        return *this;
    };

    // Vektorenmultiplikation

    /*
     * multipliziert einen Vektor mit einem anderen, ohne Datenänderung
     */
    Vector<Länge> &operator*(Vector<Länge> &v)
    {
        double data[Länge];
        for (int i = 0; i < Länge; i++) {
            data[i] = *(daten + i) * v.get(i);
        };
        return Vector<Länge>(data);
    };

    /*
     * multipliziert einen Vektor mit einem anderen, mit Datenänderung
     */
    Vector<Länge> &operator*(Vector<Länge> &v)
    {
        for (int i = 0; i < Länge; i++) {
            *(daten + i) *= v.get(i);
        };
        return *this;
    };

    // string repräsentation

    /*
     * repräsentiert den Vektor und deren Einträge als ein String
     */
    std::string _str()
    {
        std::string out = "(\t";
        for (int n = 0; n < Länge; n++)
        {
            out += std::to_string(*(daten + n)) + "\t";
        };
        out += ')';
        return out;
    };
};