#pragma once
#include <memory>

class Person;
class Copy;
class Arenda
{

public:
    Arenda(std::shared_ptr<Person> person,
           std::shared_ptr<Copy> copy);
    bool isActive();

private:
    std::shared_ptr<Person> person_;
    std::shared_ptr<Copy> copy_;
    bool active_ = true;
};
