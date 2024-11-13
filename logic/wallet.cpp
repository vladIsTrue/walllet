#include "wallet.h"

#include <QJsonObject>
#include <QJsonDocument>

using namespace logic;

bool Wallet::init(const QString &data)
{
    Q_UNUSED(data);

    // init all class fields
    // data has a structure like
    // {
    // field_name: data_hash
    // ...
    // }

    // if data parsing success - true
    // else false

    return true;
}

bool Wallet::changePassword(const QString &pass)
{
    Q_UNUSED(pass);

    return true;
}

QString Wallet::info() const
{
    return QJsonDocument(QJsonObject{{"name", name},{"type", type}}).toJson();
}
