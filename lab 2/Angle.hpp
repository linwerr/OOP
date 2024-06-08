#pragma once
#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <iostream>

class Angle {
public:
    // ������������
    Angle(double degrees = 0.0);

    // ������ ��� �������� �� �������� � ������� � ��������
    double toRadians() const;
    static Angle fromRadians(double radians);

    // ������ ��� ��������� ����
    void simplify();

    // �������� ��������, ���������, ��������� � ������� �� �����
    Angle operator+(const Angle& other) const;
    Angle operator-(const Angle& other) const;
    Angle operator*(double scalar) const;
    Angle operator/(double scalar) const;

    // �������� ���������
    bool operator==(const Angle& other) const;
    bool operator!=(const Angle& other) const;
    bool operator<(const Angle& other) const;
    bool operator<=(const Angle& other) const;
    bool operator>(const Angle& other) const;
    bool operator>=(const Angle& other) const;

    // ������ ��� ����� � ������
    friend std::ostream& operator<<(std::ostream& os, const Angle& angle);
    friend std::istream& operator>>(std::istream& is, Angle& angle);

private:
    double degrees; // ���� � ��������
};

#endif // ANGLE_HPP
