#include "Array3d.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание экземпляра класса Array3d с размерами (3, 3, 3)
    Array3d<int> arr(3, 3, 3);

    // Установка значений для определенных элементов массива
    arr(0, 0, 0) = 1;
    arr(1, 1, 1) = 2;
    arr(2, 2, 2) = 3;

    // Вывод среза массива по первой координате на экран
    std::cout << "Срез массива по первой координате: ";
    std::vector<int> slice0 = arr.GetValues0(2);
    for (int i = 0; i < slice0.size(); i++) {
        std::cout << slice0[i] << " ";
    }
    std::cout << '\n';

    // Создание массивов с одинаковыми элементами
    Array3d<double> ones_arr = ones<double>(2, 2, 2);
    Array3d<float> zeros_arr = zeros<float>(2, 2, 2);
    Array3d<int> fill_arr = fill<int>(2, 2, 2, 3);

    std::cout << "Срез массива с одинаковыми элементами (все единицы): ";
    std::vector<double> mas1 = ones_arr.GetValues01(0, 0);
    for (int i = 0; i < mas1.size(); i++) {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Срез массива с одинаковыми элементами (все нули): ";
    std::vector<float> mas2 = zeros_arr.GetValues02(0, 0);
    for (int i = 0; i < mas2.size(); i++) {
        std::cout << mas2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Срез массива с одинаковыми элементами (все тройки): ";
    std::vector<int> mas3 = fill_arr.GetValues1(0);
    for (int i = 0; i < mas3.size(); i++) {
        std::cout << mas3[i] << " ";
    }

    return 0;
}
