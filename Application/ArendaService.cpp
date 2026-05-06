#include "ArendaService.h"
#include "../Domain/Arenda.h"
#include "../Domain/Person.h"
#include "../Domain/Copy.h"
#include <stdexcept>

ArendaService::ArendaService(std::shared_ptr<ArendaRepository> repository,
                             std::shared_ptr<ArendaPolicy> policy)
    : repository_(repository), policy_(policy) {}

std::shared_ptr<Arenda> ArendaService::createArenda(std::shared_ptr<Person> person,
                                                    std::shared_ptr<Copy> copy)
{
    if (!person)
        throw std::invalid_argument("Person is null!");
    if (!copy)
        throw std::invalid_argument("Copy is null!");

    if (hasOverdueArendas(person->getId()))
        throw std::logic_error("User has overdue book/books!");

    auto active = repository_->findActiveByPerson(person->getId());

    if (!policy_)
        throw std::logic_error("ArendaPolicy is not set");
    if (!policy_->canCreateArenda(*person, *copy, active))
        throw std::logic_error("Cannot issue book!");

    auto arenda = std::make_shared<Arenda>(person, copy);
    copy->markAsArenda();
    repository_->save(arenda);
    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda)
        throw std::invalid_argument("Arenda is null!");
    arenda->close();
    arenda->getCopy()->markAsVozvrat();
}

bool ArendaService::hasOverdueArendas(int personId)
{
    auto arendas = repository_->findActiveByPerson(personId);
    for (const auto &a : arendas)
        if (a->isOverdue())
            return true;
    return false;
}