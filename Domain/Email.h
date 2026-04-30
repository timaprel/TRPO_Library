#pragma once
#include <string>

class Email
{
public:
    explicit Email(std::string value);
    const std::string& value() const;

private:
    std::string value_;
};