#include "Arenda.h"
#include "Person.h"
#include "Copy.h"
#include <stdexcept>

Arenda::Arenda(std::shared_ptr<Person> person, std::shared_ptr<Copy> copy)
    : person_(person),
      copy_(copy),
      startDate_(std::chrono::system_clock::now()),
      status_(ArendaStatus::Active)
{
    if (!person_)
        throw std::invalid_argument("Person cannot be null!");
    if (!copy_)
        throw std::invalid_argument("Copy cannot be null!");
    if (!person_->canTakeBooks())
        throw std::logic_error("Person cannot take books");
    if (!copy_->isAvailable())
        throw std::logic_error("Copy is not available");

    copy_->markAsArenda(); // помечаем экземпляр как занятый
}

std::shared_ptr<Person> Arenda::getPerson() const
{
    return person_;
}

std::shared_ptr<Copy> Arenda::getCopy() const
{
    return copy_;
}

std::chrono::system_clock::time_point Arenda::getStartDate() const
{
    return startDate_;
}

bool Arenda::isActive() const
{
    return status_ == ArendaStatus::Active;
}

void Arenda::close()
{
    if (status_ == ArendaStatus::Closed)
        throw std::logic_error("Arenda already closed!");

    status_ = ArendaStatus::Closed;
    endDate_ = std::chrono::system_clock::now();
    copy_->markAsVozvrat(); // возвращаем экземпляр в доступные
}

std::chrono::system_clock::time_point Arenda::getEndDate() const
{
    return endDate_;
}