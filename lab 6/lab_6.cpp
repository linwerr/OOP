#include <iostream>
#include "HttpRequestBuilder.h"

int main() {
    // Создаем объект HttpRequestBuilder с базовым URL
    HttpRequestBuilder builder("http://mysite.com");

    // Добавляем параметры и строим конечный URL
    std::string url = builder.addParameter("param1", "value1")
        .addParameter("param2", "value2")
        .build();

    // Выводим сгенерированный URL
    std::cout << "Generated URL: " << url << std::endl;

    return 0;
}
