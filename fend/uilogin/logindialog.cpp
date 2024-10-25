
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    EmptyDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(body());

    // TODO
    setTitle(QString::fromLocal8Bit("µÇÂ¼"));
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

}

void LoginDialog::onLoginSucceed()
{

}

void LoginDialog::onLoginError(int api, const QString &msg, const QJsonValue &req)
{

}
