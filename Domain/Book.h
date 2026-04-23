#pragma once
#include <string>
class Book
{
public:
    Book(std::string title, std::string isbn);

private:
    std::string title_;
    std::string isbn_;
};
