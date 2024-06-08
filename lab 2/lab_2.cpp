#include <iostream>
#include "Angle.hpp"

void printMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Ввести угол\n";
    std::cout << "2. Сложить углы\n";
    std::cout << "3. Вычесть углы\n";
    std::cout << "4. Умножить угол на число\n";
    std::cout << "5. Разделить угол на число\n";
    std::cout << "6. Перевести угол в радианы\n";
    std::cout << "7. Перевести радианы в угол\n";
    std::cout << "8. Упростить угол\n";
    std::cout << "9. Сравнить углы\n";
    std::cout << "0. Выйти\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    Angle angle1, angle2;
    double scalar;
    int choice;

    while (true) {
        printMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите угол: ";
            std::cin >> angle1;
            break;
        case 2:
            std::cout << "Введите второй угол: ";
            std::cin >> angle2;
            std::cout << "Результат сложения: " << (angle1 + angle2) << std::endl;
            break;
        case 3:
            std::cout << "Введите второй угол: ";
            std::cin >> angle2;
            std::cout << "Результат вычитания: " << (angle1 - angle2) << std::endl;
            break;
        case 4:
            std::cout << "Введите число: ";
            std::cin >> scalar;
            std::cout << "Результат умножения: " << (angle1 * scalar) << std::endl;
            break;
        case 5:
            std::cout << "Введите число: ";
            std::cin >> scalar;
            try {
                std::cout << "Результат деления: " << (angle1 / scalar) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            break;
        case 6:
            std::cout << "Угол в радианах: " << angle1.toRadians() << std::endl;
            break;
        case 7:
            std::cout << "Введите радианы: ";
            std::cin >> scalar;
            angle1 = Angle::fromRadians(scalar);
            std::cout << "Угол: " << angle1 << std::endl;
            break;
        case 8:
            angle1.simplify();
            std::cout << "Упрощенный угол: " << angle1 << std::endl;
            break;
        case 9:
            std::cout << "Введите второй угол: ";
            std::cin >> angle2;
            if (angle1 == angle2) {
                std::cout << "Углы равны\n";
            }
            else if (angle1 < angle2) {
                std::cout << "Первый угол меньше второго\n";
            }
            else {
                std::cout << "Первый угол больше второго\n";
            }
            break;
        case 0:
            std::cout << "Выход из программы\n";
            return 0;
        default:
            std::cout << "Некорректный выбор, попробуйте снова.\n";
        }
    }
    return 0;
}
