#include "FileUserRepository.h"
#include "UserManager.h" 
#include <windows.h> // для работы с консолью
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filePath = "users.txt"; // Путь к файлу с пользователями

    // Создаем объект userRepository, используя умный указатель std::unique_ptr,
    // и передаем ему экземпляр класса FileUserRepository
    std::unique_ptr<IUserRepository> userRepository(new FileUserRepository(filePath));

    // Создаем объект userManager и передаем ему экземпляр класса UserManager, передавая ему userRepository в качестве параметра
    std::unique_ptr<UserManager> userManager(new UserManager(userRepository.get()));

    // Создаем объект пользователя с определенными данными
    User user(000, "linwer", "123", "Alina");

    // Вход пользователя в систему
    userManager->signIn(user);

    // Выводим логин пользователя
    std::cout << user.getLogin() << '\n';

    // Проверяем, авторизован ли пользователь
    bool isAuthorized = userManager->isAuthorized();
    if (isAuthorized) {
        std::cout << "Пользователь авторизован" << std::endl;
    }
    else {
        std::cout << "Пользователь не авторизован" << std::endl;
    }

    // Выход пользователя из системы
    userManager->signOut(user);

    return 0;
}
