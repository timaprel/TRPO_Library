#include "Person.h"
#include <stdexcept>
#include <utility>

Person::Person(int id, std::string fullName, std::string email)
    : id_(id),
      fullName_(std::move(fullName)),
      email_(std::move(email))
{
    if (fullName_.empty())
        throw std::invalid_argument("Full name is empty");
}

int Person::getId() const
{
    return id_;
}

const std::string &Person::getFullName() const
{
    return fullName_;
}

const std::string &Person::getEmail() const
{
    return email_;
}

void Person::changeEmail(const std::string &newEmail)
{
    if (newEmail.empty())
        throw std::invalid_argument("Email cannot be empty");
    email_ = newEmail;
}

void Person::addRole(std::shared_ptr<Role> role)
{
    roles_.push_back(role);
}

bool Person::hasRole(const std::string &roleName) const
{
    for (const auto &role : roles_)
    {
        if (role->getName() == roleName)
            return true;
    }
    return false;
}

// Проверяет, есть ли хотя бы одна роль, разрешающая брать книги
bool Person::canTakeBooks() const
{
    for (const auto &role : roles_)
    {
        if (role->canTakeBooks())
            return true;
    }
    return false;
}