#pragma once
#include <string> 
#include <vector> 

template <typename T>
__interface IRepository {
public:
    // Метод для получения всех элементов репозитория
    std::vector<T> getAll() const;

    // Метод для добавления элемента в репозиторий
    void add(const T& user);

    // Метод для удаления элемента
    void remove(const T& user);

    // Метод для обновления элемента
    void update(const T& user);
};
