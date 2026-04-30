#include "Email.h"
#include <stdexcept>
#include <cctype>

Email::Email(std::string value) : value_(std::move(value))
{
    if (value_.empty())
        throw std::invalid_argument("Email cannot be empty");

    bool valid = true;
    int state = 0;          // 0 – начало, 1 – найден '@', 2 – есть символ после '@', 3 – найдена точка после '@', 4 – допустимое окончание
    std::string suitable_symbols = "-_.@";

    for (size_t i = 0; i < value_.size(); ++i)
    {
        char ch = value_[i];

        // Недопустимый символ
        if (!std::isalpha(static_cast<unsigned char>(ch)) &&
            !std::isdigit(static_cast<unsigned char>(ch)) &&
            suitable_symbols.find(ch) == std::string::npos)
        {
            valid = false;
            break;
        }

        // Две точки подряд
        if (i > 0 && ch == '.' && value_[i - 1] == '.')
        {
            valid = false;
            break;
        }

        // Обработка '@'
        if (ch == '@')
        {
            if (state == 0)
                state = 1;        // первый '@'
            else
            {
                valid = false;    // второй '@'
                break;
            }
        }
        // После '@' – буква или цифра
        else if ((std::isalpha(static_cast<unsigned char>(ch)) ||
                  std::isdigit(static_cast<unsigned char>(ch))) && state == 1)
        {
            state = 2;
        }
        // После символов – точка (но не в конце)
        else if (ch == '.' && state == 2)
        {
            state = 3;
        }
        // После точки – буква в конце строки
        else if (std::isalpha(static_cast<unsigned char>(ch)) && state == 3 && i == value_.size() - 1)
        {
            state = 4;
        }
    }

    if (!valid || state != 4)
        throw std::invalid_argument("Invalid email format");
}

const std::string& Email::value() const
{
    return value_;
}