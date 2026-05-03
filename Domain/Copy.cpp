#include "Copy.h"
#include "Book.h"
#include <stdexcept>
/*
Copy::Copy(int inventoryNumber)
    : inventoryNumber_(inventoryNumber) {}
*/

Copy::Copy(int inventoryNumber, std::shared_ptr<Book> book)
    : inventoryNumber_(inventoryNumber),
      book_(std::move(book))
{
    if (!book_)
        throw std::invalid_argument("Book cannot be null!");
}

bool Copy::isAvailable() const
{
    return available_;
}
void Copy::markAsArenda()
{
    if (!available_)
        throw std::logic_error("Copy is not available!");
    available_ = false;
}

void Copy::markAsVozvrat()
{
    if (available_)
        throw std::logic_error("Copy is already returned!");
    available_ = true;
}

std::shared_ptr<Book> Copy::getBook() const
{
    return book_;
}