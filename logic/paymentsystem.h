#pragma once

#include <QString>

namespace logic
{

// it also must have an interface
class PaymentSystem
{
public:
    // explicit PaymentSystem(IWallet *wallet);
    void pay(const QString &data); // json

private:
    // other payment data;

    // IWallet *wallet;
};

}
