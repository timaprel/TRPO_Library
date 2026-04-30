#pragma once
#include <memory>
#include <chrono>

class Person;
class Copy;

class Arenda
{
public:
    enum class ArendaStatus {
        Active,
        Closed
    };

    Arenda(std::shared_ptr<Person> person, std::shared_ptr<Copy> copy);

    // Геттеры
    std::shared_ptr<Person> getPerson() const;
    std::shared_ptr<Copy> getCopy() const;
    std::chrono::system_clock::time_point getStartDate() const;
    bool isActive() const;   // возвращает true, если статус Active

private:
    std::shared_ptr<Person> person_;
    std::shared_ptr<Copy> copy_;
    std::chrono::system_clock::time_point startDate_;
    ArendaStatus status_;
};