#pragma once

#include <string>

class User {
public:
    int id; // ������������� ������������
    std::string login;
    std::string password;
    std::string name;

    // ����������� ������, ����������� ���������������� �������� ��� id, login, password � name
    User(const int& id, const std::string& login, const std::string& password, const std::string& name)
        : id(id), login(login), password(password), name(name) {}

    // ��������� �������������� ������������
    int getId() const {
        return id;
    }

    //��������� ������ �������������� ������������
    void setId(int newId) {
        id = newId;
    }

    // ��������� ������ ������������
    const std::string& getLogin() const {
        return login;
    }

    // ��������� ������ ������ ������������
    void setLogin(const std::string& newLogin) {
        login = newLogin;
    }

    // ��������� ������ ������������
    const std::string& getPassword() const {
        return password;
    }

    // ��������� ������ ������ ������������
    void setPassword(const std::string& newPassword) {
        password = newPassword;
    }

    // ��������� ����� ������������
    const std::string& getName() const {
        return name;
    }

    // ��������� ������ ����� ������������
    void setName(const std::string& newName) {
        name = newName;
    }
};
