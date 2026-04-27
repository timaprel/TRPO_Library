#include "Book.h"
#include <utility>
Book::Book(std::string title,
           std::string isbn,
           std::vector<std::string> authors,
           int publicationYear)
    : title_(std::move(title)),
      isbn_(std::move(isbn)),
      authors_(std::move(authors)),
      publicationYear_(publicationYear) {}
const std::string &Book::getTitle() const
{
  return title_;
}
const std::string &Book::getIsbn() const
{
  return isbn_;
}
const std::vector<std::string> &Book::getAuthors() const
{
  return authors_;
}
int Book::getPublicationYear() const
{
  return publicationYear_;
}
