
#include <QJsonObject>
#include "logindialog.h"
#include "ui_logindialog.h"
#include "config/common.h"
#include "middle/globalmanager.h"
#include "config/api.h"
#include <bend/gateway.h>

LoginDialog::LoginDialog(QWidget *parent) :
    EmptyDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(body());

    setTitle(STR("µÇÂ¼"));
    ui->buttonLogin->setDefault(true);

    ui->labelLoginName->setProperty("style_font", "h5");
    ui->labelSecretId->setProperty("style_font", "h5");
    ui->labelSecretKey->setProperty("style_font", "h5");
    ui->labelRemark->setProperty("style_font", "h5");

    ui->buttonLogin->setProperty("style_font", "h5");
    ui->buttonLogin->setProperty("style_button", "main");

    connect(ui->buttonLogin, &QPushButton::clicked, this, &LoginDialog::onBtnLoginClicked);

    this->resize(400, 450);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::updateLoginInfo()
{
}

bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    return false;
}

void LoginDialog::onBtnLoginClicked()
{
    QJsonObject params;
    params["secretId"] = ui->lineEditSecretId->text().trimmed();
    params["secretKey"] = ui->lineEditSecretKey->text().trimmed();
    GM->gateway->send(API::LOGIN::NORMAL, params);
}

void LoginDialog::onLoginSucceed()
{
}

void LoginDialog::onLoginError(int api, const QString &msg, const QJsonValue &req)
{
}
