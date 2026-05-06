#include "ArendaPolicy.h"

bool DefaultArendaPolicy::canCreateArenda(
    const Person &person,
    const Copy &copy,
    const std::vector<std::shared_ptr<Arenda>> &active) const
{
    if (!copy.isAvailable())
        return false;
    if (active.size() >= static_cast<size_t>(person.getMaxActiveArendas()))
        return false;
    return true;
}