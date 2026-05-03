#include "ArendaService.h"
#include "../Domain/Arenda.h"
#include "../Domain/Person.h"
#include "../Domain/Copy.h"
#include <stdexcept>

ArendaService::ArendaService(std::shared_ptr<ArendaRepository> repository)
    : repository_(repository) {}

std::shared_ptr<Arenda> ArendaService::createArenda(std::shared_ptr<Person> person,
                                                    std::shared_ptr<Copy> copy)
{
    if (!person)
        throw std::invalid_argument("Person is null");
    if (!copy)
        throw std::invalid_argument("Copy is null");

    if (hasOverdueArendas(person->getId()))
        throw std::logic_error("User has overdue book/books!");

    auto active = repository_->findActiveByPerson(person->getId());
    if (active.size() >= static_cast<size_t>(person->getMaxActiveArendas()))
        throw std::logic_error("Arenda's Limit exceeded!");

    auto arenda = std::make_shared<Arenda>(person, copy);
    repository_->save(arenda);
    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda)
        throw std::invalid_argument("Arenda is null");
    arenda->close();
}

bool ArendaService::hasOverdueArendas(int personId)
{
    auto arendas = repository_->findActiveByPerson(personId);
    for (const auto &arenda : arendas)
        if (arenda->isOverdue())
            return true;
    return false;
}