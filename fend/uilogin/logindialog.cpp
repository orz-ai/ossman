
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    this->resize(400, 450);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
