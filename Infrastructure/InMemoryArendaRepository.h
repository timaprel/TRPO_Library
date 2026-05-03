#pragma once
#include "ArendaRepository.h"
#include <vector>
#include <memory>

class Arenda;

class InMemoryArendaRepository : public ArendaRepository
{
public:
    void save(std::shared_ptr<Arenda> arenda) override;
    std::vector<std::shared_ptr<Arenda>> findActiveByPerson(int personId) override;
    std::vector<std::shared_ptr<Arenda>> findOverdue() const override;
    std::vector<std::shared_ptr<Arenda>> findOverdueByPerson(int personId) const override;

private:
    std::vector<std::shared_ptr<Arenda>> arendas_;
};