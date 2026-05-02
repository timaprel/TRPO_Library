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
    void issueArenda(int personId, int copyId);

    std::shared_ptr<Arenda> createArenda(std::shared_ptr<Person> person,
                                         std::shared_ptr<Copy> copy);
    void closeArenda(std::shared_ptr<Arenda> arenda);
private:
    std::shared_ptr<ArendaRepository> repository_;
};