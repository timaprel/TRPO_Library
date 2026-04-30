#pragma once
#include <memory>
#include <chrono>

class Person;
class Copy;

class Arenda
{
public:
    Arenda(std::shared_ptr<Person> person,
           std::shared_ptr<Copy> copy);
    std::shared_ptr<Person> getPerson() const;
    std::shared_ptr<Copy> getCopy() const;

private:
    std::shared_ptr<Person> person_;
    std::shared_ptr<Copy> copy_;
    std::chrono::system_clock::time_point
        startDate_;
};