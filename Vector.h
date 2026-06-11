#pragma once

#define GET(n) (*(daten + n))
#define GETD(d, n) (*(d + n))

#include <malloc.h>
#include <string>
#include <cmath>

template <int Länge>
class Vector
{
protected:
    double daten[Länge] = {}; // Einträge des Vektors

public:
    /*
     * erzeugt einen Nullvektor mit der gegebenen Länge
     */
    Vector() {};

    /*
     * erzeugt einen Vektor mit der gegebenen Länge und den gegebenen Daten
     */
    Vector(double data[Länge])
    {
        std::copy(data, data + Länge, daten);
    };

    /*
     * ergibt den Wert zur gegebenen Position des Vektors
     */
    inline double &get(int n)
    {
        return GET(n);
    };

    /*
     * ersetzt den Wert zur gegebenen Position des Vektors mit eingegebenem Wert d
     */
    inline void set(int n, double d)
    {
        GET(n) = d;
    };

    /*
     * ergibt die 1D-Länge der Matrix
     */
    inline double magnitude()
    {
        double sum = 0;
        for (int i = 0; i < Länge; i++)
        {
            sum += GET(i) * GET(i);
        };
        return std::sqrt(sum);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    inline Vector<Länge> &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        for (int i = 0; i < Länge; i++)
        {
            GET(i) /= mag;
        };
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    inline Vector<Länge> getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector<Länge>(daten);
        Vector<Länge> result = Vector<Länge>();
        for (int i = 0; i < Länge; i++)
        {
            result.set(i, GET(i) / mag);
        };
        return result;
    };

    // mathematik addition/subtraktion

    /*
     * Standardaddition zwischen zwei Vektoren mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    inline Vector<Länge> operator+(Vector<Länge> &b)
    {
        Vector<Länge> c = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            c.set(n, GET(n) + b.get(n));
        };
        return c;
    };

    /*
     * Standardaddition zwischen zwei Vektoren mit gleichen Dimensionen, wobei die Daten des linken Vektors geändert werden
     */
    inline Vector<Länge> &operator+=(Vector<Länge> &a)
    {
        for (int n = 0; n < Länge; n++)
        {
            GET(n) += a.get(n);
        };
        return *this;
    };

    /*
     * Standardsubtraktion zwischen zwei Vektoren mit gleichen Dimensionen, wobei keiner deren Daten ändert
     */
    inline Vector<Länge> operator-(Vector<Länge> &b)
    {
        Vector<Länge> c = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            c.set(n, GET(n) - b.get(n));
        };
        return c;
    };

    /*
     * Standardsubtraktion zwischen zwei Vektoren mit gleichen Dimensionen, wobei die Daten des linken Vektors geändert werden
     */
    inline Vector<Länge> &operator-=(Vector<Länge> &a)
    {
        for (int n = 0; n < Länge; n++)
        {
            GET(n) -= a.get(n);
        };
        return *this;
    };

    // skalar multiplikation

    /*
     * multipliziert jeden Eintrag des Vektors mit dem Faktor k, ohne Datenänderung
     */
    inline double operator*(double k)
    {

        Vector<Länge> v = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            v.set(n, GET(n) * k);
        };
        return v;
    };

    /*
     * multipliziert jeden Eintrag der Matrix mit dem Faktor k
     */
    inline Vector<Länge> &operator*=(double k)
    {
        for (int n = 0; n < Länge; n++)
        {
            GET(n) *= k;
        };
        return *this;
    };

    // skalar division

    inline Vector<Länge> operator/(double k)
    {
        Vector<Länge> v = Vector<Länge>();
        for (int n = 0; n < Länge; n++)
        {
            v.set(n, GET(n) / k);
        };
        return v;
    };

    inline Vector<Länge> &operator/=(double k)
    {
        for (int n; n < Länge; n++)
        {
            GET(n) /= k;
        };
        return *this;
    };

    // Vektorenmultiplikation

    /*
     * multipliziert einen Vektor mit einem anderen, ohne Datenänderung
     */
    inline double &operator*(Vector<Länge> &b)
    {
        double sum = 0;
        for (int n = 0; n < Länge; n++)
        {
            sum += GET(n) * b.get(n);
        };
        return sum;
    };

    // Vektorengleichung

    /*
     * ersetzt die Daten des Vektors mit den Daten eines anderen Vektors
     */
    inline Vector<Länge> &operator=(Vector<Länge> &b)
    {
        for (int n = 0; n < Länge; n++)
        {
            GET(n) = b.get(n);
        };
        return *this;
    };

    inline bool operator==(Vector<Länge> &b)
    {
        for (int n = 0; n < Länge; n++)
        {
            if (GET(n) != b.get(n))
                return false;
        };
        return true;
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
            out += std::to_string(GET(n)) + "\t";
        };
        out += ')';
        return out;
    };
};

#undef GET
#undef GETD