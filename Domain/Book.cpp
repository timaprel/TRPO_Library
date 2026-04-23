#include "Book.h"
Book::Book(std::string title, std::string isbn)
    : title_(std::move(title)),
      isbn_(std::move(isbn)) {}