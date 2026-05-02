#pragma once

#include <string>

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
    virtual bool canTakeBooks() const;
    virtual int getDefaultArendaDays() const = 0;
    virtual int getMaxActiveArendas() const;
};

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
    int getMaxActiveArendas() const override
    {
        return 10;
    }
};

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

class GuestRole : public Role
{
public:
    std::string getName() const override
    {
        return "Guest";
    }
    int getDefaultArendaDays() const override { return 0; }
};