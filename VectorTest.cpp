#include <iostream>

#include "matrixmath.h"

void testAdd();
void testSub();
void testSkalarMult();
void testVectorMult();
void testMatrixMult();
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
    testVectorMult();
    testMatrixMult();
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
              << "Testen zur Skalarenmultiplikation" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
        double k = 4;
    Vector4 v = Vector4(data);
    std::cout << "v * 4:\t" << std::endl
              << (v * 4)._str() << std::endl;
    v *= 4;
    std::cout << "v * 4:\t" << std::endl
              << v._str() << std::endl;
};

void testVectorMult() {
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
    double data3[3] = {
        4, 6, 8};
    double data4[3] = {
        1, -2, 4};
    Vector3 v3 = Vector3(data3);
    Vector3 v4 = Vector3(data4);
    std::cout << "v3 * v4:\t" << std::endl
              << (v3 * v4)._str() << std::endl;
    v3 *= v4;
    std::cout << "v3 * v4:\t" << std::endl
              << v3._str() << std::endl;
    double data5[2] = {
        4, 8};
    double data6[2] = {
        1, -2};
    Vector2 v5 = Vector2(data5);
    Vector2 v6 = Vector2(data6);
    std::cout << "v5 * v6:\t" << std::endl
              << (v5 * v6)._str() << std::endl;
    v5 *= v6;
    std::cout << "v5 * v6:\t" << std::endl
              << v5._str() << std::endl;
};

void testMatrixMult() {
    std::cout << std::endl
              << "Testen zur Matrixenmultiplikation" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
    double data2[16] = {
        1, -2, 5, 0,
        8, 9, -4, 0,
        4, -2, 2, 1,
        9, 3, -3, 7};
    Vector4 v = Vector4(data);
    Matrix44 m = Matrix44(data2);
    std::cout << "v * m:\t" << std::endl
              << (v * m)._str() << std::endl;
    v *= m;
    std::cout << "v * m:\t" << std::endl
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