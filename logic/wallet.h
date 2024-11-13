#pragma once

#include "iwallet.h"

#include <QString>

namespace logic
{

class Wallet : public IWallet
{
public:
    bool init(const QString &data) override;
    bool changePassword(const QString &pass) override;
    QString info() const override;

private:
    // an easy way to fill out the fields for test
    QString name = "wallet";
    QString type = "type";

    // other wallet data
};

}
