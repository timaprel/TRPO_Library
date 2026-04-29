#pragma once
#include <string>
class ISBN
{
public:
    explicit ISBN(std::string value);
    const std::string &value() const;

private:
    std::string value_;
};