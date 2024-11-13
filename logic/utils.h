#pragma once

#include <QString>

#include <optional>

namespace logic
{
std::optional<QString> dataParser(const QString &walletFileName);
}
