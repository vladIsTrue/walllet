#pragma once

#include <QDialog>

namespace Ui
{
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    Info(const QString &info, QWidget *parent = nullptr);
    ~Info();

private:
    void setInfo(const QString &info);

    void initializeUI();

private:
    Ui::Info *ui;
};
