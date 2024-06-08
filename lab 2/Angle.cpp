#include "Angle.hpp"
#include <cmath>

const double PI = 3.14159265358979323846;

// �����������
Angle::Angle(double degrees) : degrees(degrees) {}

// ������� �� �������� � �������
double Angle::toRadians() const {
    return degrees * PI / 180.0;
}

// �������� ���� �� ������
Angle Angle::fromRadians(double radians) {
    return Angle(radians * 180.0 / PI);
}

// ��������� ���� (���������� � ��������� [0, 360) ��������)
void Angle::simplify() {
    degrees = fmod(degrees, 360.0);
    if (degrees < 0) {
        degrees += 360.0;
    }
}

// ��������
Angle Angle::operator+(const Angle& other) const {
    return Angle(degrees + other.degrees);
}

// ���������
Angle Angle::operator-(const Angle& other) const {
    return Angle(degrees - other.degrees);
}

// ��������� �� �����
Angle Angle::operator*(double scalar) const {
    return Angle(degrees * scalar);
}

// ������� �� �����
Angle Angle::operator/(double scalar) const {
    if (scalar == 0) throw std::invalid_argument("������� �� ����");
    return Angle(degrees / scalar);
}

// ��������� �� ���������
bool Angle::operator==(const Angle& other) const {
    return degrees == other.degrees;
}

// ��������� �� �����������
bool Angle::operator!=(const Angle& other) const {
    return degrees != other.degrees;
}

// ��������� (������)
bool Angle::operator<(const Angle& other) const {
    return degrees < other.degrees;
}

// ��������� (������ ��� �����)
bool Angle::operator<=(const Angle& other) const {
    return degrees <= other.degrees;
}

// ��������� (������)
bool Angle::operator>(const Angle& other) const {
    return degrees > other.degrees;
}

// ��������� (������ ��� �����)
bool Angle::operator>=(const Angle& other) const {
    return degrees >= other.degrees;
}

// ���������� ��������� ������ "<<"
std::ostream& operator<<(std::ostream& os, const Angle& angle) {
    os << angle.degrees << " ��������";
    return os;
}

// ���������� ��������� ����� ">>"
std::istream& operator>>(std::istream& is, Angle& angle) {
    is >> angle.degrees;
    return is;
}
