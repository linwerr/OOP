#pragma once
#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <iostream>

class Angle {
public:
    // Конструкторы
    Angle(double degrees = 0.0);

    // Методы для перевода из градусов в радианы и наоборот
    double toRadians() const;
    static Angle fromRadians(double radians);

    // Методы для упрощения угла
    void simplify();

    // Операции сложения, вычитания, умножения и деления на число
    Angle operator+(const Angle& other) const;
    Angle operator-(const Angle& other) const;
    Angle operator*(double scalar) const;
    Angle operator/(double scalar) const;

    // Операции сравнения
    bool operator==(const Angle& other) const;
    bool operator!=(const Angle& other) const;
    bool operator<(const Angle& other) const;
    bool operator<=(const Angle& other) const;
    bool operator>(const Angle& other) const;
    bool operator>=(const Angle& other) const;

    // Методы для ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Angle& angle);
    friend std::istream& operator>>(std::istream& is, Angle& angle);

private:
    double degrees; // Угол в градусах
};

#endif // ANGLE_HPP
