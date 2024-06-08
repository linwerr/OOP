#include <iostream>
#include "Methods.hpp"

// Пример подынтегральной функции
double exampleFunction(double x) {
    return x * x; // Интеграл от x^2
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Определяем границы интегрирования
    double lowerBound = 0.0;
    double upperBound = 1.0;

    // Число точек и допустимая погрешность
    int numPoints = 11;
    double tolerance = 1e-6;

    // Создаем объекты для расчета интегралов методами трапеций и парабол (Симпсона)
    TrapezoidalIntegralCalculator trapezoidalCalculator(numPoints, tolerance);
    SimpsonIntegralCalculator simpsonCalculator(numPoints, tolerance);

    // Расчет интеграла методом трапеций
    double resultTrapezoidal = trapezoidalCalculator.Calc(exampleFunction, lowerBound, upperBound);
    std::cout << "Метод трапеций: " << resultTrapezoidal << std::endl;

    // Расчет интеграла методом Симпсона
    double resultSimpson = simpsonCalculator.Calc(exampleFunction, lowerBound, upperBound);
    std::cout << "Метод Симпсона(парабол): " << resultSimpson << std::endl;

    // Проверка
    //double analyticalResult = (upperBound * upperBound * upperBound) / 3.0;
    //std::cout << "Аналитический результат: " << analyticalResult << std::endl;

    return 0;
}
