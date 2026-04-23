#include "Person.h"

Person::Person(int id)
    : id_(id) {}
void Person::addRole(std::shared_ptr<Role> role)
{
    roles_.push_back(role);
}
bool Person::hasRole(const std::string &roleName) const
{
    for (const auto &role : roles_)
    {
        if (role->getName() == roleName)
        {
            return true;
        }
    }
    return false;
}
