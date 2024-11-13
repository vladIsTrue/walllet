#pragma once

class QString;

namespace logic
{

struct IWallet
{
    virtual bool init(const QString &data) = 0; // json
    virtual bool changePassword(const QString &pass) = 0; // json
    virtual QString info() const = 0; // json
};

}
