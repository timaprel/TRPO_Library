#pragma once
class Copy
{
public:
    explicit Copy(int inventoryNumber);
    bool isAvailable() const;
    void markAsArenda();
    void markAsVozvrat();

private:
    int inventoryNumber_;
    bool available_ = true;
};
