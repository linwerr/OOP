#ifndef HTTPREQUESTBUILDER_H
#define HTTPREQUESTBUILDER_H

#include <string>
#include <map>

// Класс для построения HTTP-запросов методом GET
class HttpRequestBuilder {
private:
    std::string baseUrl; // Основной URL без параметров
    std::map<std::string, std::string> parameters; // Параметры запроса

public:
    // Конструктор, принимающий основной URL
    HttpRequestBuilder(const std::string& url);

    // Метод для добавления параметров к запросу
    HttpRequestBuilder& addParameter(const std::string& key, const std::string& value);

    // Метод для построения финального URL
    std::string build() const;

    // Деструктор
    ~HttpRequestBuilder() = default;
};

#endif // HTTPREQUESTBUILDER_H
