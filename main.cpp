
#include "fend/uilogin/logindialog.h"
#include "middle/globalmanager.h"

#include <QApplication>
#include <QNetworkInterface>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GM->init(argc, argv);

    LoginDialog ld;
    ld.show();
    return a.exec();
}



