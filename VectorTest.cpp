#include <iostream>

#include "matrixmath.h"

void testAdd();
void testSub();
void testSkalarMult();
void testVectorMult();
void testMatrixMult();
void testNormalize();
void testCrossProduct();

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
    testCrossProduct();
    std::cout << "s is scho voabei" << std::endl;
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
    std::cout << "v += v2:\t" << std::endl
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
    std::cout << "v -= v2:\t" << std::endl
              << v._str() << std::endl;
};

void testSkalarMult()
{
    std::cout << std::endl
              << "Testen zur Skalarenmultiplikation" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
    double k = 4;
    Vector4 v = Vector4(data);
    std::cout << "v * 4:\t" << std::endl
              << (v * 4)._str() << std::endl;
    v *= 4;
    std::cout << "v *= 4:\t" << std::endl
              << v._str() << std::endl;
};

void testVectorMult()
{
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
    std::cout << "v *= v2:\t" << std::endl
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
    std::cout << "v3 *= v4:\t" << std::endl
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
    std::cout << "v5 *= v6:\t" << std::endl
              << v5._str() << std::endl;
};

void testMatrixMult()
{
    std::cout << std::endl
              << "Testen zur Matrixenmultiplikation" << std::endl;
    double data[4] = {
        4, 6, 8, -2};
    double data2[16] = {
        1, -2, 5, 0,
        8, 9, -4, 0,
        4, -2, 2, 1,
        9, 3, -3, 7};
    Vector4 v4 = Vector4(data);
    Matrix44 m4 = Matrix44(data2);
    std::cout << "v4 * m4:\t" << std::endl
              << (v4 * m4)._str() << std::endl;
    v4 *= m4;
    std::cout << "v4 *= m4:\t" << std::endl
              << v4._str() << std::endl;

    double data3[3] = {
        4, 6, 8};
    double data4[16] = {
        1, -2, 5,
        8, 9, 0,
        4, 2, 1};
    Vector3 v3 = Vector3(data3);
    Matrix33 m3 = Matrix33(data4);
    std::cout << "v3 * m3:\t" << std::endl
              << (v3 * m3)._str() << std::endl;
    v3 *= m3;
    std::cout << "v3 *= m3:\t" << std::endl
              << v3._str() << std::endl;
    double data5[4] = {
        4, -2};
    double data6[16] = {
        1, 0,
        -3, 7};
    Vector2 v2 = Vector2(data5);
    Matrix22 m2 = Matrix22(data6);
    std::cout << "v2 * m2:\t" << std::endl
              << (v2 * m2)._str() << std::endl;
    v2 *= m2;
    std::cout << "v2 *= m2:\t" << std::endl
              << v2._str() << std::endl;
    Matrix<2, 3> m = Matrix<2, 3>(data4);
    Vector<2> v = Vector<2>(data5);
    std::cout << "v * m:\t" << std::endl
              << (v * m)._str() << std::endl;
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

void testCrossProduct()
{
    std::cout << std::endl
              << "Testen zum Vektorenkreuzprodukt" << std::endl;
    double data[4] = {
        3, -4, 5};
    double data2[4] = {
        5, 4, -3};
    Vector3 v1 = Vector3(data);
    Vector3 v2 = Vector3(data2);
    std::cout << "v1 x v2: " << std::endl
              << v1.cross(v2)._str() << std::endl;
    std::cout << "v2 x v1: " << std::endl
              << v2.cross(v1)._str() << std::endl;
};