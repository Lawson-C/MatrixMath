#include <iostream>

#include "matrixmath.h"

void testAdd();
void testSub();
void testSkalarMult();
void testNormalize();

int main()
{
    std::cout << "JAAAAAA WOIIIII!!!!! MIA GHEAN MA WEIDA" << std::endl;
    double data[4] = {
        1, -2, 3, 2};
    Vector4 v = Vector4(data);
    std::cout << "v:\t" << std::endl
              << v._str() << std::endl;
    testAdd();
    testSub();
    testSkalarMult();
    testNormalize();
    return 0;
};

void testAdd()
{
    std::cout << std::endl
              << "Testen zur Vektorenaddition" << std::endl;
    double data[4] = {
        1, -2, 3, 2};
    double data2[4] = {
        6, -3, 7, 4};
    Vector4 v = Vector4(data);
    Vector4 v2 = Vector4(data2);
    std::cout << "v + v2:\t" << std::endl
              << (v + v2)._str() << std::endl;
    v += v2;
    std::cout << "v + v2:\t" << std::endl
              << v._str() << std::endl;
};

void testSub()
{
    std::cout << std::endl
              << "Testen zur Vektorensubtraktion" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
    double data2[4] = {
        1, -2, 5, 4};
    Vector4 v = Vector4(data);
    Vector4 v2 = Vector4(data2);
    std::cout << "v - v2:\t" << std::endl
              << (v - v2)._str() << std::endl;
    v -= v2;
    std::cout << "v - v2:\t" << std::endl
              << v._str() << std::endl;
};

void testSkalarMult() {
    std::cout << std::endl
              << "Testen zur Vektorenmultiplikation" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
    double data2[4] = {
        1, -2, 5, 4};
    Vector4 v = Vector4(data);
    Vector4 v2 = Vector4(data2);
    std::cout << "v * v2:\t" << std::endl
              << (v * v2)._str() << std::endl;
    v *= v2;
    std::cout << "v * v2:\t" << std::endl
              << v._str() << std::endl;
};

void testNormalize()
{
    std::cout << std::endl
              << "Testen zur Vektorennormalizierung" << std::endl;
    double data[4] = {
        3, -4, 5, -9};
    Vector2 v2 = Vector2(data);
    Vector3 v3 = Vector3(data);
    Vector4 v4 = Vector4(data);
    std::cout << "norm(v2): " << std::endl
              << v2.normalize()._str() << std::endl
              << "norm(v3): " << std::endl
              << v3.normalize()._str() << std::endl
              << "norm(v4): " << std::endl
              << v4.normalize()._str() << std::endl;
};