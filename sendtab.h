#pragma once

#include <QWidget>

namespace Ui {
class SendTab;
}

class SendTab : public QWidget
{
    Q_OBJECT

public:
    explicit SendTab(QWidget *parent = nullptr);
    ~SendTab();

    void initializeUI();

private:
    Ui::SendTab *ui;
};
