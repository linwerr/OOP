#include "Methods.hpp"
#include <cmath>

// Конструктор базового класса
IntegralCalculator::IntegralCalculator(double tolerance)
    : tolerance(tolerance) {
    if (tolerance <= 0) {
        throw std::invalid_argument("Точность должна быть положительной");
    }
}

// Метод для установки шага вычисления
void IntegralCalculator::setStep(double lowerBound, double upperBound, int numPoints) {
    step = (upperBound - lowerBound) / (numPoints - 1); // (длина интервала)/(кол-во интервалов между точками)
}

// Конструктор класса для метода трапеций
TrapezoidalIntegralCalculator::TrapezoidalIntegralCalculator(double tolerance)
    : IntegralCalculator(tolerance) {}

// Реализация метода расчета интеграла методом трапеций
double TrapezoidalIntegralCalculator::Calc(std::function<double(double)> func, double lowerBound, double upperBound, int numPoints) {
    if (numPoints <= 1) {
        throw std::invalid_argument("Число точек должно быть больше 1");
    }

    setStep(lowerBound, upperBound, numPoints); // Установка шага интегрирования

    double integral = 0.0;

    // Вычисление суммы значений функции в точках интегрирования
    for (int i = 0; i < numPoints; ++i) {
        // Текущее значения аргумента функции
        double x = lowerBound + i * step;

        // Значение функции в текущей точке и добавление его к результату интегрирования
        if (i == 0 || i == numPoints - 1) {
            // Если точка крайняя, добавляем значение функции, разделенное на 2 (половина высоты трапеции)
            integral += func(x) / 2.0;
        }
        else {
            // Иначе добавляем значение функции в полной высоте трапеции
            integral += func(x);
        }
    }

    integral *= step;
    return integral;
}

// Конструктор класса для метода Симпсона
SimpsonIntegralCalculator::SimpsonIntegralCalculator(double tolerance)
    : IntegralCalculator(tolerance) {}

// Реализация метода расчета интеграла методом Симпсона
double SimpsonIntegralCalculator::Calc(std::function<double(double)> func, double lowerBound, double upperBound, int numPoints) {
    if (numPoints <= 1) {
        throw std::invalid_argument("Число точек должно быть больше 1");
    }
    if (numPoints % 2 == 0) {
        throw std::invalid_argument("По правилу Симпсона количество точек должно быть нечетным");
    }

    // Установка шага интегрирования
    setStep(lowerBound, upperBound, numPoints);

    double integral = func(lowerBound) + func(upperBound); // Сумма значений функции на границах

    // Сумма значений функции в точках интегрирования (четные)
    for (int i = 1; i < numPoints - 1; i += 2) {
        double x = lowerBound + i * step; // Вычисление текущей точки
        integral += 4 * func(x); // Добавление к сумме значения функции, умноженного на 4
    }

    // нечетные
    for (int i = 2; i < numPoints - 1; i += 2) {
        double x = lowerBound + i * step; // Текущая точки
        integral += 2 * func(x);
    }

    integral *= step / 3.0;
    return integral;
}
