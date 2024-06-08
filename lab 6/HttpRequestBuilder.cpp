#include "HttpRequestBuilder.h"
#include <sstream>

// �����������, ���������������� �������� URL
HttpRequestBuilder::HttpRequestBuilder(const std::string& url) : baseUrl(url) {}

// ����� ��� ���������� ���������� � �������
HttpRequestBuilder& HttpRequestBuilder::addParameter(const std::string& key, const std::string& value) {
    parameters[key] = value; // ��������� �������� � �����
    return *this; // ���������� ������ �� ������� ������ ��� ����������� ������
}

// ����� ��� ���������� ���������� URL � �����������
std::string HttpRequestBuilder::build() const {
    std::ostringstream url; // ���������� stringstream ��� ���������� ������
    url << baseUrl; // �������� � ��������� URL

    if (!parameters.empty()) {
        url << "?"; // ���� ���� ���������, ��������� ?
        for (auto it = parameters.begin(); it != parameters.end(); ++it) {
            if (it != parameters.begin()) {
                url << "&"; // ��������� & ����� �����������
            }
            url << it->first << "=" << it->second; // ��������� ����=��������
        }
    }

    return url.str(); // ���������� ����������� ������ URL
}
