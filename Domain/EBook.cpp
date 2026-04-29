#include "EBook.h"

std::string EBook::getOpisanie() const
{
    return Book::getOpisanie() + " [E-Book]";
}
