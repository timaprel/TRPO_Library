#include "PBook.h"

std::string PBook::getOpisanie() const
{
    return Book::getOpisanie() + " [P-Book]";
}
