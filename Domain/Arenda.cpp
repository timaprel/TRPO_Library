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

    int days = person_->getMaxArendaDays();
    if (days <= 0)
        throw std::logic_error("Person cannot take books (no valid rental period)");

    if (!copy_->isAvailable())
        throw std::logic_error("Copy is not available");

    copy_->markAsArenda(); // помечаем экземпляр как занятый
    dueDate_ = startDate_ + std::chrono::hours(24 * days);
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

bool Arenda::isOverdue() const
{
    if (status_ == ArendaStatus::Closed)
        return false;

    return std::chrono::system_clock::now() > dueDate_;
}