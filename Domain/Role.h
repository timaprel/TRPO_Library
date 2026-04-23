#pragma once

#include <string>

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
};
