#include "Person.h"
#include "Arenda.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

Person::Person(int id, std::string fullName, Email email)
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

const Email &Person::getEmail() const
{
    return email_;
}

void Person::changeEmail(Email &newEmail)
{
    email_ = std::move(newEmail);
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

bool Person::canTakeBooks() const
{
    for (const auto &role : roles_)
    {
        if (role->canTakeBooks())
            return true;
    }
    return false;
}

int Person::getMaxArendaDays() const
{
    int maxDays = 0;
    for (const auto &role : roles_)
    {
        if (role->canTakeBooks())
        {
            maxDays = std::max(maxDays, role->getDefaultArendaDays());
        }
    }
    return maxDays;
}

int Person::getMaxActiveArendas() const
{
    int maxActive = 0;
    for (const auto &role : roles_)
    {
        if (role->canTakeBooks())
        {
            maxActive = std::max(maxActive, role->getMaxActiveArendas());
        }
    }
    return maxActive;
}

void Person::addArenda(std::shared_ptr<Arenda> arenda)
{
    arendas_.push_back(arenda);
}

bool Person::hasOverdueArendas() const
{
    for (const auto& arenda : arendas_)
        if (arenda->isOverdue())
            return true;
    return false;
}