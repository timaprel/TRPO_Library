#pragma once
#include <vector>
#include <memory>
#include "Role.h"
#include <string>

class Person
{
public:
    explicit Person(int id, std::string fullName, std::string email);
    void addRole(std::shared_ptr<Role> role);
    bool hasRole(const std::string &roleName) const;
    int getId() const;
    const std::string &getFullName() const;
    const std::string &getEmail() const;
    void changeEmail(const std::string &newEmail);

private:
    int id_;
    std::vector<std::shared_ptr<Role>> roles_;
    std::string fullName_;
    std::string email_;
};