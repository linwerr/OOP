#include "Angle.hpp"
#include <cmath>

const double PI = 3.14159265358979323846;

// Конструктор
Angle::Angle(double degrees) : degrees(degrees) {}

// Перевод из градусов в радианы
double Angle::toRadians() const {
    return degrees * PI / 180.0;
}

// Создание угла из радиан
Angle Angle::fromRadians(double radians) {
    return Angle(radians * 180.0 / PI);
}

// Упрощениу угла (приведение к диапазону [0, 360) градусов)
void Angle::simplify() {
    degrees = fmod(degrees, 360.0);
    if (degrees < 0) {
        degrees += 360.0;
    }
}

// Сложение
Angle Angle::operator+(const Angle& other) const {
    return Angle(degrees + other.degrees);
}

// Вычитание
Angle Angle::operator-(const Angle& other) const {
    return Angle(degrees - other.degrees);
}

// Умножение на число
Angle Angle::operator*(double scalar) const {
    return Angle(degrees * scalar);
}

// Деление на число
Angle Angle::operator/(double scalar) const {
    if (scalar == 0) throw std::invalid_argument("Деление на ноль");
    return Angle(degrees / scalar);
}

// Сравнение на равенство
bool Angle::operator==(const Angle& other) const {
    return degrees == other.degrees;
}

// Сравнение на неравенство
bool Angle::operator!=(const Angle& other) const {
    return degrees != other.degrees;
}

// Сравнение (меньше)
bool Angle::operator<(const Angle& other) const {
    return degrees < other.degrees;
}

// Сравнение (меньше или равно)
bool Angle::operator<=(const Angle& other) const {
    return degrees <= other.degrees;
}

// Сравнение (больше)
bool Angle::operator>(const Angle& other) const {
    return degrees > other.degrees;
}

// Сравнение (больше или равно)
bool Angle::operator>=(const Angle& other) const {
    return degrees >= other.degrees;
}

// Перегрузка оператора вывода "<<"
std::ostream& operator<<(std::ostream& os, const Angle& angle) {
    os << angle.degrees << " градусов";
    return os;
}

// Перегрузка оператора ввода ">>"
std::istream& operator>>(std::istream& is, Angle& angle) {
    is >> angle.degrees;
    return is;
}
