#include "isbn.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>

ISBN::ISBN(std::string value)
    : original_(std::move(value))
{
    validateAndClean();
}

const std::string &ISBN::value() const
{
    return original_;
}

const std::string &ISBN::cleaned() const
{
    return cleaned_;
}

bool ISBN::isIsbn10() const
{
    return type_ == 10;
}

bool ISBN::isIsbn13() const
{
    return type_ == 13;
}

char ISBN::getCheckDigit() const
{
    if (cleaned_.empty())
        return '\0';
    return cleaned_.back();
}

std::string ISBN::getPrefix() const
{
    if (type_ == 13 && cleaned_.size() >= 3)
        return cleaned_.substr(0, 3);
    return "";
}

std::string ISBN::getCountryCode() const
{
    if (cleaned_.empty())
        return "";
    if (type_ == 10)
    {
        // Для ISBN-10 первая цифра — код страны/языка (0,1 – англ, 2 – франц, 3 – нем, 4 – япон, 5 – русский, 7 – китай)
        char first = cleaned_[0];
        switch (first)
        {
        case '0':
            return "English (0)";
        case '1':
            return "English (1)";
        case '2':
            return "French";
        case '3':
            return "German";
        case '4':
            return "Japan";
        case '5':
            return "Russian";
        case '7':
            return "China";
        default:
            return "Other";
        }
    }
    else
    { // ISBN-13
        // Префикс 978 или 979, затем код группы переменной длины
        if (cleaned_.size() < 4)
            return "";
        std::string group = cleaned_.substr(3);
        // Пример простого определения по первым цифрам группы
        if (group.empty())
            return "";
        char firstG = group[0];
        if (firstG == '0' || firstG == '1')
            return "English";
        if (firstG == '2')
            return "French";
        if (firstG == '3')
            return "German";
        if (firstG == '4')
            return "Japan";
        if (firstG == '5')
            return "Russian";
        if (firstG == '7')
            return "China";
        return "Unknown";
    }
}

void ISBN::validateAndClean()
{
    // Удаляем дефисы и пробелы
    cleaned_.clear();
    for (char ch : original_)
    {
        if (ch == '-' || ch == ' ')
            continue;
        cleaned_.push_back(ch);
    }

    // Определяем тип
    if (cleaned_.size() == 10)
    {
        type_ = 10;
        if (!isValidIsbn10(cleaned_))
            throw std::invalid_argument("Invalid ISBN-10 checksum");
    }
    else if (cleaned_.size() == 13)
    {
        type_ = 13;
        if (!isValidIsbn13(cleaned_))
            throw std::invalid_argument("Invalid ISBN-13 checksum");
    }
    else
    {
        throw std::invalid_argument("ISBN must be 10 or 13 digits long");
    }
}

bool ISBN::isValidIsbn10(const std::string &s) const
{
    int sum = 0;
    for (size_t i = 0; i < 9; ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
        sum += (s[i] - '0') * (int)(i + 1);
    }
    char last = s[9];
    int lastVal;
    if (last == 'X' || last == 'x')
        lastVal = 10;
    else if (std::isdigit(static_cast<unsigned char>(last)))
        lastVal = last - '0';
    else
        return false;

    sum += lastVal * 10;
    return (sum % 11 == 0);
}

bool ISBN::isValidIsbn13(const std::string &s) const
{
    if (s.size() != 13)
        return false;
    int sum = 0;
    for (size_t i = 0; i < 13; ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
        int digit = s[i] - '0';
        sum += (i % 2 == 0) ? digit : digit * 3;
    }
    return (sum % 10 == 0);
}