#pragma once

#include <string>

class User {
public:
    int id; // Идентификатор пользователя
    std::string login;
    std::string password;
    std::string name;

    // Конструктор класса, принимающий инициализирующие значения для id, login, password и name
    User(const int& id, const std::string& login, const std::string& password, const std::string& name)
        : id(id), login(login), password(password), name(name) {}

    // Получение идентификатора пользователя
    int getId() const {
        return id;
    }

    //Установка нового идентификатора пользователя
    void setId(int newId) {
        id = newId;
    }

    // Получение логина пользователя
    const std::string& getLogin() const {
        return login;
    }

    // Установка нового логина пользователя
    void setLogin(const std::string& newLogin) {
        login = newLogin;
    }

    // Получение пароля пользователя
    const std::string& getPassword() const {
        return password;
    }

    // Установка нового пароля пользователя
    void setPassword(const std::string& newPassword) {
        password = newPassword;
    }

    // Получение имени пользователя
    const std::string& getName() const {
        return name;
    }

    // Установка нового имени пользователя
    void setName(const std::string& newName) {
        name = newName;
    }
};
