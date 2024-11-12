#pragma once

#include <QDir>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void quit();

private:
    Ui::MainWindow *ui;

    QString walletsPath = QDir::homePath();
};
