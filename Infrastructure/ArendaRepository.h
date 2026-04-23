#pragma once
#include <memory>
class Arenda;

class ArendaRepository
{
public:
    virtual ~ArendaRepository() = default;
    virtual void save(std::shared_ptr<Arenda> arenda) = 0;
};
