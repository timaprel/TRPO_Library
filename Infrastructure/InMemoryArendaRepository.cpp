#include "InMemoryArendaRepository.h"
#include "../Domain/Arenda.h"
#include "../Domain/Person.h"
#include <vector>

void InMemoryArendaRepository::save(std::shared_ptr<Arenda> arenda)
{
    arendas_.push_back(arenda);
}

std::vector<std::shared_ptr<Arenda>> InMemoryArendaRepository::findActiveByPerson(int personId)
{
    std::vector<std::shared_ptr<Arenda>> res;
    for (const auto &arenda : arendas_)
    {
        if (arenda->getPerson()->getId() == personId && arenda->isActive())
        {
            res.push_back(arenda);
        }
    }
    return res;
}