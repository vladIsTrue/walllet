#pragma once

#include <QDialog>

namespace Ui {
class ChangePass;
}

class ChangePass : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePass(QWidget *parent = nullptr);
    ~ChangePass();

    QString password() const;

private:
    void initializeUI();

private:
    Ui::ChangePass *ui;
};
