#ifndef HTTPREQUESTBUILDER_H
#define HTTPREQUESTBUILDER_H

#include <string>
#include <map>

// ����� ��� ���������� HTTP-�������� ������� GET
class HttpRequestBuilder {
private:
    std::string baseUrl; // �������� URL ��� ����������
    std::map<std::string, std::string> parameters; // ��������� �������

public:
    // �����������, ����������� �������� URL
    HttpRequestBuilder(const std::string& url);

    // ����� ��� ���������� ���������� � �������
    HttpRequestBuilder& addParameter(const std::string& key, const std::string& value);

    // ����� ��� ���������� ���������� URL
    std::string build() const;

    // ����������
    ~HttpRequestBuilder() = default;
};

#endif // HTTPREQUESTBUILDER_H
