#pragma once

#include <string>

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
    virtual bool canTakeBooks() const;
    virtual int getDefaultArendaDays() const = 0;
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
    int getDefaultArendaDays() const override
    {
        return 100;
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
    int getDefaultArendaDays() const override
    {
        return 0;
    }
};

// Роль "Администратор" – по умолчанию НЕ может брать книги
class AdministratorRole : public Role
{
public:
    std::string getName() const override
    {
        return "Administrator";
    }
    int getDefaultArendaDays() const override
    {
        return 0;
    }
};

// Роль "Гость" – не может брать книги
class GuestRole : public Role
{
public:
    std::string getName() const override
    {
        return "Guest";
    }
    int getDefaultArendaDays() const override { return 0; }
};