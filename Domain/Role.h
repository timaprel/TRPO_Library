#pragma once

#include <string>

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
    virtual bool canTakeBooks() const;
};

// Роль "Читатель" – может брать книги
class ReaderRole : public Role
{
public:
    std::string getName() const override
    {
        return "Reader";
    }
    bool canTakeBooks() const override
    {
        return true;
    }
};

// Роль "Библиотекарь" – по умолчанию НЕ может брать книги
class BibliotekarRole : public Role
{
public:
    std::string getName() const override
    {
        return "Bibliotekar";
    }
    // canTakeBooks() наследуется от Role (возвращает false)
};

// Роль "Администратор" – по умолчанию НЕ может брать книги
class AdministratorRole : public Role
{
public:
    std::string getName() const override
    {
        return "Administrator";
    }
    // canTakeBooks() наследуется от Role (возвращает false)
};

// Роль "Гость" – не может брать книги
class GuestRole : public Role
{
public:
    std::string getName() const override
    {
        return "Guest";
    }
};