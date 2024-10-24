#ifndef EMPTYDIALOG_H
#define EMPTYDIALOG_H

#include <QWidget>
#include "basedialog.h"


namespace Ui {
class EmptyDialog;
}

class EmptyDialog : public BaseDialog
{
    Q_OBJECT

public:
    explicit EmptyDialog(QWidget *parent = nullptr);
    ~EmptyDialog();

private:
    Ui::EmptyDialog *ui;
};

#endif // EMPTYDIALOG_H
