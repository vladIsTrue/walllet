#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sendtab.h"
#include "newwallet.h"
#include "info.h"
#include "changepass.h"
#include "../logic/utils.h"

#include <QSettings>
#include <QFileDialog>

MainWindow::MainWindow(IWallet *wllt)
    : ui(new Ui::MainWindow)
    , wallet(wllt)
{
    initializeUI();

    readSettings();
}

void MainWindow::readSettings()
{
    QSettings settings("wallet", "wallet");
    settings.beginGroup("paths");
    walletsPath.append(settings.value("walletsPath").toString());
    settings.endGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::walletInfo()
{
    Info info(wallet->info(), this);
    info.exec();
}

void MainWindow::changePassword()
{
    ChangePass dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        wallet->changePassword(dialog.password());
    }
}

void MainWindow::openWallet()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open wallet"), walletsPath,
                                                    tr("Wallets (*)"));

    if (auto data = logic::dataParser(fileName); data.has_value())
        wallet->init(data.value());
}

void MainWindow::newWallet()
{
    NewWallet dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        dialog.name();
        dialog.password();
    }
}

void MainWindow::initializeUI()
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->mainLayout);

    createMenuBar();
    updateStatusBar();

    setSignalsSlots();
}

void MainWindow::setSignalsSlots()
{
    connect(ui->sendTab, &SendTab::pay, [=](const QString &data)
    {
        emit pay(data);
    });
}

void MainWindow::createMenuBar()
{
    createFile();
    createWallet();
}

void MainWindow::updateStatusBar(const QString &currentBalance)
{
    statusBar()->showMessage(tr("Balance: %1").arg(currentBalance));
}

void MainWindow::createFile()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAction = new QAction(tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openWallet);

    QAction *newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    connect(newAction, &QAction::triggered, this, &MainWindow::newWallet);

    fileMenu->addAction(openAction);
    fileMenu->addAction(newAction);
}

void MainWindow::createWallet()
{
    QMenu *walletMenu = menuBar()->addMenu(tr("&Wallet"));

    QAction *infoAction = new QAction(tr("&Information"), this);
    connect(infoAction, &QAction::triggered, this, &MainWindow::walletInfo);
    QAction *passwordAction = new QAction(tr("&Password"), this);
    connect(passwordAction, &QAction::triggered, this, &MainWindow::changePassword);

    walletMenu->addAction(infoAction);
    walletMenu->addAction(passwordAction);
}
