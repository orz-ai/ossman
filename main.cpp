
#include "fend/uilogin/logindialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    ld.show();
    return a.exec();
}
