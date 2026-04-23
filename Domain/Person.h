#pragma once
#include <vector>
#include <memory>
#include "Role.h"

class Person
{
public:
    explicit Person(int id);
    void addRole(std::shared_ptr<Role> role);
    bool hasRole(const std::string &roleName) const;

private:
    int id_;
    std::vector<std::shared_ptr<Role>> roles_;
};