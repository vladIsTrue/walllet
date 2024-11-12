#include "sendtab.h"
#include "ui_sendtab.h"

SendTab::SendTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SendTab)
{
    initializeUI();
}

SendTab::~SendTab()
{
    delete ui;
}

void SendTab::initializeUI()
{
    ui->setupUi(this);

    setLayout(ui->mainLayout);
}
