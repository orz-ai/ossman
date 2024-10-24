
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>

#include <fend/uicommon/emptydialog.h>

namespace Ui {
    class LoginDialog;
}


class LoginDialog : public EmptyDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void updateLoginInfo();

protected:
    bool eventFilter(QObject *watched, QEvent *event);


private:
    Ui::LoginDialog *ui;


private slots:
    void onBtnLoginClicked();
    void onLoginSucceed();
    void onLoginError(int api, const QString &msg, const QJsonValue &req);

};

#endif // LOGINDIALOG_H
