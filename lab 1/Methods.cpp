#include "Methods.hpp"
#include <cmath>

// ����������� �������� ������
IntegralCalculator::IntegralCalculator(int numPoints, double tolerance)
    : numPoints(numPoints), tolerance(tolerance) {
    if (numPoints <= 1) {
        throw std::invalid_argument("����� ������ ���� ������ 1");
    }
    if (tolerance <= 0) {
        throw std::invalid_argument("�������� ������ ���� �������������");
    }
}

// ����� ��� ��������� ���� ����������
void IntegralCalculator::setStep(double lowerBound, double upperBound) {
    step = (upperBound - lowerBound) / (numPoints - 1); // (����� ���������)/(���-�� ���������� ����� �������)
}

// ����������� ������ ��� ������ ��������
TrapezoidalIntegralCalculator::TrapezoidalIntegralCalculator(int numPoints, double tolerance)
    : IntegralCalculator(numPoints, tolerance) {}

// ���������� ������ ������� ��������� ������� ��������
double TrapezoidalIntegralCalculator::Calc(std::function<double(double)> func, double lowerBound, double upperBound) {
   
    setStep(lowerBound, upperBound); // ��������� ���� ��������������

    double integral = 0.0;

    // ���������� ����� �������� ������� � ������ ��������������
    for (int i = 0; i < numPoints; ++i) {
        // ������� �������� ��������� �������
        double x = lowerBound + i * step;

        // �������� ������� � ������� ����� � ���������� ��� � ���������� ��������������
        if (i == 0 || i == numPoints - 1) {
            // ���� ����� �������, ��������� �������� �������, ����������� �� 2 (�������� ������ ��������)
            integral += func(x) / 2.0;
        }
        else {
            // ����� ��������� �������� ������� � ������ ������ ��������
            integral += func(x);
        }
    }

    integral *= step;
    return integral;
}


// ����������� ������ ��� ������ ��������
SimpsonIntegralCalculator::SimpsonIntegralCalculator(int numPoints, double tolerance)
    : IntegralCalculator(numPoints, tolerance) {
    if (numPoints % 2 == 0) {
        throw std::invalid_argument("�� ������� �������� ���������� ������ ���� ��������");
    }
}

// ���������� ������ ������� ��������� ������� ��������
double SimpsonIntegralCalculator::Calc(std::function<double(double)> func, double lowerBound, double upperBound) {

    /*
    I = (h/3) * [f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) + ... + 2*f(xn-2) + 4*f(xn-1) + f(xn)]
    */


    // ��������� ���� ��������������
    setStep(lowerBound, upperBound);

    double integral = func(lowerBound) + func(upperBound); // ����� �������� ������� �� ��������

    // ����� �������� ������� � ������ �������������� (������)
    for (int i = 1; i < numPoints - 1; i += 2) {
        double x = lowerBound + i * step; // ���������� ������� �����
        integral += 4 * func(x); // ���������� � ����� �������� �������, ����������� �� 4
    }

    // ��������
    for (int i = 2; i < numPoints - 1; i += 2) {
        double x = lowerBound + i * step; // ������� �����
        integral += 2 * func(x); 
    }

    integral *= step / 3.0;
    return integral;
}