#include "info.h"
#include "ui_info.h"

#include <QJsonObject>
#include <QJsonDocument>

Info::Info(const QString &info, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Info)
{
    initializeUI();

    setInfo(info);
}

Info::~Info()
{
    delete ui;
}

void Info::setInfo(const QString &info)
{
    auto object = QJsonDocument::fromJson(info.toUtf8()).object();

    ui->name->setText(object.value("name").toString());
    ui->type->setText(object.value("type").toString());
}

void Info::initializeUI()
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);
}
