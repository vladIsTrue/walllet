#include "manager.h"
#include "logic/wallet.h"
#include "gui/mainwindow.h"

using Wallet = logic::Wallet;

Manager::Manager()
    : m_wallet(std::make_unique<Wallet>())
    , m_paySystem(std::make_unique<PaymentSystem>())
    , m_window(std::make_unique<MainWindow>(m_wallet.get()))
{
    void setSignalsSlots();
}

void Manager::run()
{
    m_window->show();
}

void Manager::setSignalsSlots()
{
    connect(m_window.get(), &MainWindow::pay, [=](const QString &data)
    {
        m_paySystem->pay(data);
    });
}
