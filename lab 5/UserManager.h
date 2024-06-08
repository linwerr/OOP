#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include <iostream> 

class UserManager : public IUserManager {
private:
    User* currentUser; // ��������� �� �������� ������������
    IUserRepository* userRepository; // ��������� �� ����������� �������������

public:
    // ����������� ������, ����������� ��������� �� ����������� �������������
    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr) {}

    // ����� ��� ����� ������������ � �������
    void signIn(User& user) override {
        currentUser = &user; // ������������� �������� ������������
    }

    // ����� ��� ������ ������������ �� �������
    void signOut(User& user) override {
        currentUser = nullptr; // ���������� ��������� �� �������� ������������
        std::cout << "������������ ����� �� �������" << std::endl;
    }

    // ����� ��� �������� ����������� ������������
    bool isAuthorized() override {
        return currentUser != nullptr; // ���������� true, ���� ������� ������������ �� �������� nullptr
    }
};
