#pragma once
#include <memory>
#include <vector>

class Arenda;

class ArendaRepository
{
public:
    virtual ~ArendaRepository() = default;
    virtual void save(std::shared_ptr<Arenda> arenda) = 0;
    virtual std::vector<std::shared_ptr<Arenda>> findActiveByPerson(int personId) = 0;
};