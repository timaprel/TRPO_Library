#include "Arenda.h"
#include "Person.h"
#include "Copy.h"

Arenda::Arenda(std::shared_ptr<Person> person,
std::shared_ptr<Copy> copy):
person_(person),copy_(copy) {}

bool Arenda::isActive() {
    return active_;
}