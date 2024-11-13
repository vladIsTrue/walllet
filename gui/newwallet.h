#pragma once

#include <QDialog>

namespace Ui
{
class NewWallet;
}

class NewWallet : public QDialog
{
    Q_OBJECT

public:
    explicit NewWallet(QWidget *parent = nullptr);
    ~NewWallet();

    QString name() const;
    QString password() const;

private:
    void initializeUI();

private:
    Ui::NewWallet *ui;
};
