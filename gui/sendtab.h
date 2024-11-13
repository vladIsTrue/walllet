#pragma once

#include <QString>
#include <QWidget>

namespace Ui
{
class SendTab;
}

class SendTab : public QWidget
{
    Q_OBJECT

public:
    explicit SendTab(QWidget *parent = nullptr);
    ~SendTab();

    void initializeUI();

    void setSignalsSlots();

signals:
    void pay(QString);

private:
    Ui::SendTab *ui;
};
