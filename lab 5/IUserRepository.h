#pragma once

#include "IRepository.h"
#include "User.h"

class IUserRepository : public IRepository<User> { // IUserRepository, наследующий IRepository<User>
public:
    // Виртуальная функция для получения пользователя по его идентификатору
    virtual User* getById(int id) = 0;

    // Виртуальная функция для получения пользователя по его логину
    virtual User* getByLogin(const std::string& login) = 0;
};
