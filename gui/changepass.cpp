#include "changepass.h"
#include "ui_changepass.h"

ChangePass::ChangePass(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePass)
{
    initializeUI();
}

ChangePass::~ChangePass()
{
    delete ui;
}

QString ChangePass::password() const
{
    // create json obj like this

    // {
    // current_pass: current_pass_hash
    // new_pass: new_pass_hash
    // new_pass_confirm: new_pass_confirm_hash
    // }

    // and return it;

    return QString{};
}

void ChangePass::initializeUI()
{
    ui->setupUi(this);
}
