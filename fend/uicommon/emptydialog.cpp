#include "emptydialog.h"
#include "ui_basedialog.h"
#include "ui_emptydialog.h"

EmptyDialog::EmptyDialog(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::EmptyDialog)
{
    ui->setupUi(this);
    // TODO set logo
    setLogo("");
    setTitle(QString::fromLocal8Bit("ossman"));
    ui_bd->labelLogo->setFixedSize(32,24);
    ui_bd->labelTitle->setProperty("style", "h4");
}

EmptyDialog::~EmptyDialog()
{
    delete ui;
}
