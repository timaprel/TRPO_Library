#pragma once
#include <vector>
#include <memory>
#include "../Domain/Copy.h"
#include "../Domain/Person.h"
#include "../Domain/Arenda.h"

// Базовый интерфейс политики
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

// Правило: доступность экземпляра
class AvailabilityPolicy : public ArendaPolicy
{
public:
    bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const override;
    {
        return copy.isAvailable();
    }
};

// Правило: лимит активных аренд
class MaxActiveArendasPolicy : public ArendaPolicy
{
public:
    bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const override
    {
        return active.size() < static_cast<size_t>(person.getMaxActiveArendas());
    }
};

// Правило: отсутствие просрочек
class OverduePolicy : public ArendaPolicy
{
public:
    bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const override
    {
        return overdue.empty();
    }
};

// Составное правило (композит)
class CompositeArendaPolicy : public ArendaPolicy
{
public:
    void addPolicy(std::shared_ptr<ArendaPolicy> policy)
    {
        policies_.push_back(policy);
    }

    bool canCreateArenda(
        const Person &person,
        const Copy &copy,
        const std::vector<std::shared_ptr<Arenda>> &active,
        const std::vector<std::shared_ptr<Arenda>> &overdue) const override
    {
        bool res = true;
        for (const auto &policy : policies_)
        {
            if (!policy->canCreateArenda(person, copy, active, overdue))
            {
                res = false;
            }
        }
        return res;
    }

private:
    std::vector<std::shared_ptr<ArendaPolicy>> policies_;
};