#pragma once
#include "ArendaRepository.h"
#include <vector>

class InMemoryArendaRepository : public ArendaRepository
{
public:
    void save(std::shared_ptr<Arenda> arenda);

private:
    std::vector<std::shared_ptr<Arenda>> storage_;
};
