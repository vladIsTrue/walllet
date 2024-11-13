#include "paymentsystem.h"

using namespace logic;

void PaymentSystem::pay(const QString &data)
{
    Q_UNUSED(data);

    // data is json like
    //
    // {
    // payment_field: hashed_data;
    // ...
    // }
}
