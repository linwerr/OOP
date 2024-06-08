#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include <iostream> 

class UserManager : public IUserManager {
private:
    User* currentUser; // ”казатель на текущего пользовател€
    IUserRepository* userRepository; // ”казатель на репозиторий пользователей

public:
    //  онструктор класса, принимающий указатель на репозиторий пользователей
    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr) {}

    // ћетод дл€ входа пользовател€ в систему
    void signIn(User& user) override {
        currentUser = &user; // ”станавливаем текущего пользовател€
    }

    // ћетод дл€ выхода пользовател€ из системы
    void signOut(User& user) override {
        currentUser = nullptr; // —брасываем указатель на текущего пользовател€
        std::cout << "ѕользователь вышел из системы" << std::endl;
    }

    // ћетод дл€ проверки авторизации пользовател€
    bool isAuthorized() override {
        return currentUser != nullptr; // ¬озвращаем true, если текущий пользователь не €вл€етс€ nullptr
    }
};
