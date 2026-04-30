#include "Copy.h"
#include <stdexcept>
Copy::Copy(int inventoryNumber)
    : inventoryNumber_(inventoryNumber) {}
bool Copy::isAvailable() const
{
    return available_;
}
void Copy::markAsArenda()
{
    if (!available_)
    { throw std::logic_error("Copy is not
available!");}
 available_ = false;
    }
    void Copy::markAsVozvrat()
    {
        if (available_)
        {
            throw std::logic_error("Copy is already returned!");
        }
        available_ = true;
    }