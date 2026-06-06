#pragma once

#define V0 (*(daten))
#define V1 (*(daten + 1))
#define V2 (*(daten + 2))

#include <malloc.h>
#include <string>

#include "Vector.h"

class Vector3 : public Vector<3>
{
public:
    double &x = V0;
    double &y = V1;
    double &z = V2;

    Vector3() : Vector<3>() {};
    Vector3(double data[3]) : Vector<3>(), x(data[0]), y(data[1]), z(data[2]) {};
    Vector3(double x, double y, double z) : Vector<3>(), x(x), y(y), z(z) {};

    inline Vector3 &replace(double x, double y, double z)
    {
        V0 = x;
        V1 = y;
        V2 = z;
        return *this;
    };

    inline double magnitude()
    {
        return std::sqrt(V0 * V0 + V1 * V1 + V2 * V2);
    };

    /*
     * normailiziert den Vector und gibt die Referenz zurück
     */
    inline Vector3 &normalize()
    {
        double mag = magnitude();
        if (mag == 1)
            return *this;
        V0 /= mag;
        V1 /= mag;
        V2 /= mag;
        return *this;
    };

    /*
     * gibt den normalizierten Vector zurück, ohne dass die Daten geändert werden
     */
    inline Vector3 getNormal()
    {
        double mag = magnitude();
        if (mag == 1)
            return Vector3(daten);
        return Vector3(V0 / mag,
                       V1 / mag,
                       V2 / mag);
    };

    /*
     * ergibt den Kreuzprodukt von zwei Vektoren
     */
    inline Vector3 cross(Vector<3> &v)
    {
        return Vector3(V1 * v.get(2) - V2 * v.get(1),
                       -(V0 * v.get(2) - V2 * v.get(0)),
                       V0 * v.get(1) - V1 * v.get(0));
    }

    // skalar multiplikation

    inline Vector3 operator*(double k)
    {
        return Vector3(V0 * k,
                       V1 * k,
                       V2 * k);
    };

    inline Vector3 &operator*=(double k)
    {
        V0 *= k;
        V1 *= k;
        V2 *= k;
        return *this;
    };

    // mathematik addition/subtraktion

    inline Vector3 &add(double x, double y, double z)
    {
        V0 += x;
        V1 += y;
        V2 += z;
        return *this;
    };

    inline Vector3 operator+(Vector<3> &a)
    {
        return Vector3(V0 + a.get(0),
                       V1 + a.get(1),
                       V2 + a.get(2));
    };

    inline Vector3 &operator+=(Vector<3> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        return *this;
    };

    inline Vector3 operator-(Vector<3> &a)
    {
        return Vector3(V0 - a.get(0),
                       V1 - a.get(1),
                       V2 - a.get(2));
    };

    inline Vector3 &operator-=(Vector<3> &a)
    {
        V0 -= a.get(0);
        V1 -= a.get(1);
        V2 -= a.get(2);
        return *this;
    };

    // Vectorenmultiplikation

    inline double operator*(Vector<3> &v)
    {
        return V0 * v.get(0) + V1 * v.get(1) + V2 * v.get(2);
    };

    // Vektorengleichung

    inline Vector3 &operator=(Vector3 &b)
    {
        V0 = b.x;
        V1 = b.y;
        V2 = b.z;
        return *this;
    };

    inline bool operator==(const Vector3 &b) const
    {
        return (V0 == b.x && V1 == b.y && V2 == b.z);
    };
};

#undef V0
#undef V1
#undef V2
