#include "ArendaPolicy.h"

bool DefaultArendaPolicy::canCreateArenda(
    const Person &person,
    const Copy &copy,
    const std::vector<std::shared_ptr<Arenda>> &active,
    const std::vector<std::shared_ptr<Arenda>> &overdue) const
{
    bool res = true;
    if (!copy.isAvailable())
        res = false;
    if (active.size() >= static_cast<size_t>(person.getMaxActiveArendas()))
        res = false;
    if (!overdue.empty())
        res = false;
    return res;
}