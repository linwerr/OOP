#ifndef METHODS_HPP
#define METHODS_HPP

#include <functional>
#include <stdexcept>

// ������� ����� ��� ���������� ������� ����������
class IntegralCalculator {
protected:
    int numPoints; // ����� ����� ��� ���������� ���������
    double step; // ��� ���������� ���������
    double tolerance; // �������� ����������

public:
    // ����������� ������ � �������������� ����� ����� � ��������
    IntegralCalculator(int numPoints, double tolerance);

    // ����������� ����� ��� ������� ���������
    virtual double Calc(std::function<double(double)> func, double lowerBound, double upperBound) = 0;

    // ����� ��� ��������� ���� ����������
    void setStep(double lowerBound, double upperBound);

    // ����������� ����������
    virtual ~IntegralCalculator() = default;
};

// ����� ��� ������� ���������� ������� ��������
class TrapezoidalIntegralCalculator : public IntegralCalculator {
public:
    // ����������� ������
    TrapezoidalIntegralCalculator(int numPoints, double tolerance);

    // ���������� ������ ������� ���������
    double Calc(std::function<double(double)> func, double lowerBound, double upperBound) override;
};

// ����� ��� ������� ���������� ������� �������� (�������)
class SimpsonIntegralCalculator : public IntegralCalculator {
public:
    // ����������� ������
    SimpsonIntegralCalculator(int numPoints, double tolerance);

    // ���������� ������ ������� ���������
    double Calc(std::function<double(double)> func, double lowerBound, double upperBound) override;
};

#endif // METHODS_HPP