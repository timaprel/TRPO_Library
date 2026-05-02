#include "ArendaService.h"
#include "../Domain/Arenda.h"
#include "../Domain/Person.h"
#include "../Domain/Copy.h"
#include "../Domain/Role.h"
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

    if (person->hasOverdueArendas())
        throw std::logic_error("User has overdue book/books!");

    auto arenda = std::make_shared<Arenda>(person, copy);

    person->addArenda(arenda);

    repository_->save(arenda);

    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda)
        throw std::invalid_argument("Arenda is null");
    arenda->close();
}

void ArendaService::issueArenda(int personId, int copyId)
{
    auto person = std::make_shared<Person>(personId, "Test User", Email("test@example.com"));
    person->addRole(std::make_shared<ReaderRole>());

    auto copy = std::make_shared<Copy>(copyId);

    createArenda(person, copy);
}