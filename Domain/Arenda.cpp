#include "Arenda.h"
#include "Person.h"
#include "Copy.h"
#include <stdexcept>

Arenda::Arenda(std::shared_ptr<Person> person,
               std::shared_ptr<Copy> copy)
    : person_(person),
      copy_(copy),
      startDate_(std::chrono::system_clock::now())
{
    if (!person_)
    {
        throw std::invalid_argument("Person cannot be null!");
    }
    if (!copy_)
    {
        throw std::invalid_argument("Copy cannot be null!");
    }
}
std::shared_ptr<Person> Arenda::getPerson() const
{
    return person_;
}
std::shared_ptr<Copy> Arenda::getCopy() const
{
    return copy_;
}