#include "newwallet.h"
#include "ui_newwallet.h"

NewWallet::NewWallet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewWallet)
{
    initializeUI();
}

NewWallet::~NewWallet()
{
    delete ui;
}

QString NewWallet::name() const
{
    return ui->name->text();
}

QString NewWallet::password() const
{
    return ui->pass->text();
}

void NewWallet::initializeUI()
{
    ui->setupUi(this);

    setLayout(ui->mainLayout);
}
