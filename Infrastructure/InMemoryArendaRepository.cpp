#include "InMemoryArendaRepository.h"

void InMemoryArendaRepository::save(std::shared_ptr<Arenda> Arenda)
{
    storage_.push_back(Arenda);
}