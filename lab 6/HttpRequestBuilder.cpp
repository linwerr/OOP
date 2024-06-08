#include "HttpRequestBuilder.h"
#include <sstream>

// Конструктор, инициализирующий основной URL
HttpRequestBuilder::HttpRequestBuilder(const std::string& url) : baseUrl(url) {}

// Метод для добавления параметров к запросу
HttpRequestBuilder& HttpRequestBuilder::addParameter(const std::string& key, const std::string& value) {
    parameters[key] = value; // Добавляем параметр в карту
    return *this; // Возвращаем ссылку на текущий объект для цепочечного вызова
}

// Метод для построения финального URL с параметрами
std::string HttpRequestBuilder::build() const {
    std::ostringstream url; // Используем stringstream для построения строки
    url << baseUrl; // Начинаем с основного URL

    if (!parameters.empty()) {
        url << "?"; // Если есть параметры, добавляем ?
        for (auto it = parameters.begin(); it != parameters.end(); ++it) {
            if (it != parameters.begin()) {
                url << "&"; // Добавляем & между параметрами
            }
            url << it->first << "=" << it->second; // Добавляем ключ=значение
        }
    }

    return url.str(); // Возвращаем построенную строку URL
}
