#pragma once

#include "IUserRepository.h"
#include <vector>
#include <fstream> 
#include "User.h" 

class FileUserRepository : public IUserRepository {
public:
    // Конструктор класса, принимающий путь к файлу
    FileUserRepository(const std::string& filePath) : filePath(filePath) {
        loadUsersFromFile(); // Загружаем пользователей из файла
    }

    // Деструктор класса
    ~FileUserRepository() {
        saveUsersToFile(); // Сохраняем пользователей в файл перед уничтожением объекта
    }

    // Метод для получения всех пользователей
    std::vector<User> getAll() const override {
        return users;
    }

    // Метод для добавления пользователя
    void add(const User& user) override {
        users.push_back(user);
        saveUsersToFile(); // Сохраняем пользователей в файл после добавления нового пользователя
    }

    // Метод для удаления пользователя
    void remove(const User& user) override {
        users.erase(std::remove_if(users.begin(), users.end(), [&user](const User& u) {return u.getId() == user.getId(); }), users.end());
        saveUsersToFile(); // Сохраняем пользователей в файл после удаления пользователя
    }

    // Метод для обновления данных пользователя
    void update(const User& user) override {
        // Находим пользователя для обновления
        int userId = user.getId();
        User* userToUpdate = getById(userId);
        // Проверяем, существует ли пользователь
        if (!userToUpdate) {
            return;
        }
        // Обновляем данные пользователя
        userToUpdate->setLogin(user.getLogin());
        userToUpdate->setPassword(user.getPassword());
        userToUpdate->setName(user.getName());
        // Сохраняем обновленных пользователей в файл
        saveUsersToFile();
    }

    // Метод для получения пользователя по его идентификатору
    User* getById(int id) override {
        for (User& user : users) {
            if (user.getId() == id) {
                return &user;
            }
        }
        return nullptr;
    }

    // Метод для получения пользователя по его логину
    User* getByLogin(const std::string& login) override {
        for (User& user : users) {
            if (user.getLogin() == login) {
                return &user;
            }
        }
        return nullptr;
    }

private:
    // Метод для загрузки пользователей из файла
    void loadUsersFromFile() {
        users.clear(); // Очищаем текущий список пользователей

        std::ifstream file(filePath); // Открываем файл для чтения
        if (!file.is_open()) { // Проверяем, удалось ли открыть файл
            return; // Если не удалось, просто выходим из метода
        }

        std::string line;
        while (getline(file, line)) { // Читаем файл построчно
            std::vector<std::string> parts = split(line, ','); // Разделяем строку по запятой
            int id = std::stoi(parts[0]); // Преобразуем первую часть строки в целое число (id пользователя)
            std::string login = parts[1]; // Получаем логин пользователя
            std::string password = parts[2]; // Получаем пароль
            std::string name = parts[3]; // Получаем имя

            User user(id, login, password, name); // Создаем объект пользователя
            users.push_back(user); // Добавляем пользователя в список
        }

        file.close(); // Закрываем файл
    }

    // Метод для сохранения пользователей в файл
    void saveUsersToFile() const {
        std::ofstream file(filePath, std::ios::out | std::ios::trunc); // Открываем файл для записи (при этом существующий файл очищается)
        if (!file.is_open()) { // Проверяем, удалось ли открыть файл
            return; // Если не удалось, просто выходим из метода
        }

        for (const User& user : users) { // Проходим по всем пользователям в списке
            file << user.getId() << "," << user.getLogin() << "," << user.getPassword() << "," << user.getName() << std::endl; // Записываем данные пользователя в файл
        }

        file.close();
    }

    // Метод для разделения строки на подстроки по заданному разделителю
    std::vector<std::string> split(const std::string& str, char delimiter) const {
        std::vector<std::string> parts; // Вектор для хранения подстрок
        std::string part; // Строка для хранения текущей подстроки

        for (char c : str) { // Проходим по каждому символу в строке
            if (c == delimiter) { // Если символ равен разделителю
                if (!part.empty()) { // Проверяем, что текущая подстрока не пуста
                    parts.push_back(part); // Добавляем текущую подстроку в вектор
                    part.clear(); // Очищаем строку для следующей подстроки
                }
            }
            else { 
                part += c; // Добавляем символ к текущей подстроке
            }
        }
        if (!part.empty()) { // Проверяем, что последняя подстрока не пуста
            parts.push_back(part); // Добавляем последнюю подстроку в вектор
        }
        return parts; // Возвращаем вектор с подстроками
    }


private:
    std::vector<User> users; // Вектор для хранения пользователей
    std::string filePath; // Путь к файлу, в котором хранятся пользователи
};
