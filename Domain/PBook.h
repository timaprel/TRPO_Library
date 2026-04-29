#pragma once
#include "Book.h"

class PBook : public Book {
public:
    using Book::Book;
    std::string getOpisanie() const override;
};
