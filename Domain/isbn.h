#pragma once
#include <string>

class ISBN
{
public:
    explicit ISBN(std::string value);

    // Геттеры
    const std::string& value() const;           // исходная строка (с дефисами, если были)
    const std::string& cleaned() const;         // очищенная строка (только цифры и X)
    bool isIsbn10() const;
    bool isIsbn13() const;
    char getCheckDigit() const;                 // контрольная цифра (может быть 'X')
    std::string getPrefix() const;              // для ISBN-13: "978" или "979", иначе пустая строка
    std::string getCountryCode() const;         // упрощённый код страны/языка

private:
    std::string original_;
    std::string cleaned_;
    int type_; // 10 или 13

    void validateAndClean();
    bool isValidIsbn10(const std::string& s) const;
    bool isValidIsbn13(const std::string& s) const;
};