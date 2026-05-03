#pragma once
#include <memory>
#include "../infrastructure/ArendaRepository.h"

class Person;
class Copy;
class Arenda;

class ArendaService
{
public:
    explicit ArendaService(std::shared_ptr<ArendaRepository> repository);

    std::shared_ptr<Arenda> createArenda(std::shared_ptr<Person> person,
                                         std::shared_ptr<Copy> copy);
    void closeArenda(std::shared_ptr<Arenda> arenda);
    bool hasOverdueArendas(int personId);

private:
    std::shared_ptr<ArendaRepository> repository_;
};