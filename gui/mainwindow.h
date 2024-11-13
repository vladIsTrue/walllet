#pragma once

#include "../logic/iwallet.h"

#include <QDir>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    using IWallet = logic::IWallet;

public:
    explicit MainWindow(IWallet *wllt);
    ~MainWindow();

signals:
    void pay(QString);

private:
    void initializeUI();
    void readSettings();

    void createMenuBar();
    void createFile();
    void createWallet();

    void updateStatusBar(const QString &currentBalance = "0 mBTC");

    void walletInfo();
    void changePassword();

    void openWallet();
    void newWallet();

    void setSignalsSlots();

private:
    Ui::MainWindow *ui;

    IWallet *wallet;

    QString walletsPath = QDir::homePath();
};
