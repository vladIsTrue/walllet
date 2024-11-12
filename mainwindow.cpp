#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sendtab.h"

#include <QDebug>

#include <QToolBar>
#include <QSettings>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    qDebug() << "walletInfo";
}

void MainWindow::changePassword()
{
    qDebug() << "passwordChanged";
}

void MainWindow::openWallet()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open wallet"), walletsPath,
                                                    tr("Wallets (*)"));

    // TODO: // reopen wallet
}

void MainWindow::newWallet()
{
    // TODO QDialog
}

void MainWindow::quit()
{

}

void MainWindow::initializeUI()
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->mainLayout);

    createMenuBar();
    updateStatusBar();
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

    QAction *quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, &QAction::triggered, this, &MainWindow::quit);

    fileMenu->addAction(openAction);
    fileMenu->addAction(newAction);
    fileMenu->addAction(quitAction);
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
