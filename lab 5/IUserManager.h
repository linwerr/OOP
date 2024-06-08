#pragma once
#include "User.h"

__interface IUserManager {
public:
    // Метод для входа пользователя в систему
    void signIn(User& user);

    // Метод для выхода
    void signOut(User& user);

    // Метод для проверки авторизации
    bool isAuthorized();
};
