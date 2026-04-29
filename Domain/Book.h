#pragma once
#include <string>
#include <vector>
#include "isbn.h"

class Book
{
public:
    Book(std::string title,
         ISBN isbn,
         std::vector<std::string> authors,
         int publicationYear);
    const std::string &getTitle() const;
    const std::string &getIsbn() const;
    const std::vector<std::string> &getAuthors() const;
    int getPublicationYear() const;
    bool Book::Kem_napisana_kniga(const std::string &author) const;

private:
    std::string title_;
    ISBN isbn_;
    std::vector<std::string> authors_;
    int publicationYear_;
};
