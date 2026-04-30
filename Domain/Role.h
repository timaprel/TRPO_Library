#pragma once

#include <string>

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
};

// Роль "Читатель"
class ReaderRole : public Role
{
public:
    std::string getName() const override
    {
        return "Reader";
    }
};

// Роль "Библиотекарь"
class BibliotekarRole : public Role
{
public:
    std::string getName() const override
    {
        return "Bibliotekar";
    }
};

// Роль "Администратор"
class AdministratorRole : public Role
{
public:
    std::string getName() const override
    {
        return "Administrator";
    }
};