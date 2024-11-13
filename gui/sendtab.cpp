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

    setSignalsSlots();
}

void SendTab::setSignalsSlots()
{
    connect(ui->clear, &QPushButton::clicked, [=]
    {
        ui->payTo->clear();
        ui->description->clear();
        ui->amount->clear();
    });

    connect(ui->pay, &QPushButton::clicked, [=]
    {
        ui->payTo->text(); // hash it
        ui->description->text(); // hash it
        ui->amount->text(); // hash it

        // then create and emit structure for pay

        emit pay(QString{});
    });
}
