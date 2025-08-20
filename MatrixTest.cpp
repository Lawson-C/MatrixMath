#include <iostream>

#include "matrixmath.h"

void testAdd();
void testSub();
void testMult();
void testTranspose();
void testInverse();

int main()
{
    std::cout << "JAAAAAA WOIIIII!!!!! MIA GHEAN MA WEIDA" << std::endl;
    double data[4] = {
        1, -2,
        3, 2};
    Matrix22 m = Matrix22(data);
    std::cout << "m:\t" << std::endl
              << m._str() << std::endl;
    testAdd();
    testSub();
    testMult();
    testTranspose();
    testInverse();
    return 0;
};

void testAdd()
{
    std::cout << std::endl
              << "Testen zur Matrixenaddition" << std::endl;
    double data[4] = {
        1, -2,
        3, 2};
    Matrix22 m = Matrix22(data);
    Matrix22 m2 = Matrix22(data);
    std::cout << "m + m:" << std::endl
              << (m + m2)._str() << std::endl;
};

void testSub()
{
    std::cout << std::endl
              << "Testen zur Matrixensubraktion" << std::endl;
    double data[4] = {
        1, -2,
        3, 2};
    double data2[4] = {
        -1, -4,
        1, 0};
    Matrix22 m = Matrix22(data);
    Matrix22 m2 = Matrix22(data2);
    std::cout << "m - m2:\t" << std::endl
              << (m - m2)._str() << std::endl;
    m -= m2;
    std::cout << "m - m2:\t" << std::endl
              << m._str() << std::endl;
};

void testMult()
{
    std::cout << std::endl
              << "Testen zur Matrixenmultiplikation" << std::endl;
    double data[4] = {
        1, -2,
        3, 2};
    Matrix22 m = Matrix22(data);
    std::cout << "m * 3 * 3:\t" << std::endl
              << (m * 3)._str() << std::endl;
    m *= 3;
    std::cout << "m * 3:\t" << std::endl
              << m._str() << std::endl;
    double data2[6] = {
        1, -2, 6,
        8, 2, 3};
    double data3[9] = {
        5, -3, 7,
        3, 2, -5,
        2, -2, 6};
    Matrix<2, 3> m2 = Matrix<2, 3>(data2);
    Matrix33 m3 = Matrix33(data3);
    std::cout << "m2 * m3:\t" << std::endl
              << (m2 * m3)._str() << std::endl;
    m2 *= m3;
    std::cout << "m2 * m3:\t" << std::endl
              << m2._str() << std::endl;
};

void testTranspose()
{
    std::cout << std::endl
              << "Testen zur Matrixentransponierung" << std::endl;
    double data[8] = {
        5, -3.6, 19, 7,
        4, 1, 2, 3};
    double data2[8] = {
        5, 4,
        -3.6, 1,
        19, 2,
        7, 3};
    double data3[4] = {
        1, -2,
        5, 4};
    Matrix<2, 4> m = Matrix<2, 4>(data);
    std::cout << "m^T:\t" << std::endl
              << m.transpose()._str() << std::endl;
    Matrix<4, 2> m2 = Matrix<4, 2>(data2);
    std::cout << "m2^T:\t" << std::endl
              << m2.transpose()._str() << std::endl;
    Matrix22 m3 = Matrix22(data3);
    std::cout << "m3^T:\t" << std::endl
              << m3.transpose()._str() << std::endl;
    std::cout << std::endl;
    double data4[9] = {
        5, -3.6, 3,
        19, 7, 4,
        1, 2, 3};
    Matrix33 m4 = Matrix33(data4);
    std::cout << "m4^T:\t" << std::endl
              << m4.transpose()._str() << std::endl;
    double data5[16] = {
        5, 4, 8, 4,
        -3.6, 1, 19, 1,
        2, 7, 3, -3,
        -9, 6, 53, 5};
    Matrix44 m5 = Matrix44(data5);
    std::cout << "m5^T:\t" << std::endl
              << m5.transpose()._str() << std::endl;
};

void testInverse()
{
    std::cout << std::endl
              << "Testen zur Inverse von Matrixen" << std::endl;
    double data[4] = {
        1, -2,
        4, 2};
    Matrix22 m = Matrix22(data);
    std::cout << "m^-1:\t" << std::endl
              << m.inverse()._str() << std::endl;
};