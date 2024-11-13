#pragma once

#include "gui/mainwindow.h"
#include "logic/iwallet.h"
#include "logic/paymentsystem.h"

#include <QObject>

#include <memory>

class Manager : public QObject
{
    Q_OBJECT

    using IWallet = logic::IWallet;
    using PaymentSystem = logic::PaymentSystem;

public:
    explicit Manager();

    void run();

private:
    void setSignalsSlots();

private:
    std::unique_ptr<IWallet> m_wallet;
    std::unique_ptr<PaymentSystem> m_paySystem;
    std::unique_ptr<MainWindow> m_window;
};
