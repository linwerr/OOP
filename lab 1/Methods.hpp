#ifndef METHODS_HPP
#define METHODS_HPP

#include <functional>
#include <stdexcept>

// Базовый класс для численного расчета интегралов
class IntegralCalculator {
protected:
    double step; // Шаг вычисления интеграла
    double tolerance; // Точность вычислений

public:
    // Конструктор класса с инициализацией точности
    IntegralCalculator(double tolerance);

    // Виртуальный метод для расчета интеграла
    virtual double Calc(std::function<double(double)> func, double lowerBound, double upperBound, int numPoints) = 0;

    // Метод для установки шага вычисления
    void setStep(double lowerBound, double upperBound, int numPoints);

    // Виртуальный деструктор
    virtual ~IntegralCalculator() = default;
};

// Класс для расчета интегралов методом трапеций
class TrapezoidalIntegralCalculator : public IntegralCalculator {
public:
    // Конструктор класса
    TrapezoidalIntegralCalculator(double tolerance);

    // Реализация метода расчета интеграла
    double Calc(std::function<double(double)> func, double lowerBound, double upperBound, int numPoints) override;
};

// Класс для расчета интегралов методом Симпсона (парабол)
class SimpsonIntegralCalculator : public IntegralCalculator {
public:
    // Конструктор класса
    SimpsonIntegralCalculator(double tolerance);

    // Реализация метода расчета интеграла
    double Calc(std::function<double(double)> func, double lowerBound, double upperBound, int numPoints) override;
};

#endif // METHODS_HPP
