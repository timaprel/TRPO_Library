#pragma once
#include <vector>
#include <memory>
#include "../Domain/Copy.h"
#include "../Domain/Person.h"
#include "../Domain/Arenda.h"

class ArendaPolicy
{
public:
    virtual bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const = 0;
    virtual ~ArendaPolicy() = default;
};

class DefaultArendaPolicy : public ArendaPolicy
{
public:
    bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const override;
};