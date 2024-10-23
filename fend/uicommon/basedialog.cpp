#include "basedialog.h"
#include "ui_basedialog.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QKeyEvent>

BaseDialog::BaseDialog(QWidget *parent)
    : QDialog(parent)
    , ui_bd(new Ui::BaseDialog)
{
    ui_bd->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::Window);
    // TODO set logo etc.

    ui_bd->labelLogo->setFixedSize(28, 28);
}

BaseDialog::~BaseDialog()
{
    delete ui_bd;
}

void BaseDialog::setTitle(const QString &title)
{
    ui_bd->labelTitle->setText(title);
}

void BaseDialog::setLogo(const QString &path)
{
    ui_bd->labelLogo->setStyleSheet(QString("border-image: url(\"%1\");").arg(path));
}

void BaseDialog::addMinButton(const QString path, const QString &hoverPath)
{
    QPushButton* btn = addButton(path, hoverPath);
    connect(btn, &QPushButton::clicked, this, &BaseDialog::showMinimized);
}

void BaseDialog::addMaxButton(const QString maxPath, const QString &hoverMaxPath, const QString &normalPath, const QString hoverNormalPath)
{
    QPushButton* btn = addButton(maxPath, hoverMaxPath);
    auto imageFunc = [=]() {
        isMaximized() ? setButtonImage(btn, normalPath, hoverNormalPath): setButtonImage(btn, maxPath, hoverMaxPath);
    };

    auto showFunc = [=]() {
        isMaximized() ? showNormal() : showMaximized();
        imageFunc();
    };
}

QPushButton *BaseDialog::addButton(const QString &path, const QString &hoverPath)
{
    QPushButton* btn = new QPushButton;
    btn->setFixedSize(ui_size, ui_size);
    setButtonImage(btn, path, hoverPath);
    addWidget(btn);
    return btn;
}

void BaseDialog::setButtonImage(QPushButton *btn, const QString &path, const QString &hoverPath)
{
    btn->setStyleSheet(QString("QPushButton{border-image: url(\"%1\")};"
                               "QPushBotton::hover{border-image: url(\"%1\")}").arg(path, hoverPath));
}

void BaseDialog::setAllButtonSize(int w)
{
    QList<QPushButton *> btns = ui_bd->frameTitle->findChildren<QPushButton*>();
    for (auto* btn : btns) {
        btn->setFixedSize(w,w);
    }

    ui_size = w;
}

void BaseDialog::setKeyDisabled()
{
    installEventFilter(this);
}

void BaseDialog::addTitleLine(int w)
{
    QLabel* label = new QLabel;
    label->setFixedSize(w, 15);
    addWidget(label);
}

void BaseDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        ui_start = event->pos();
    }

    QDialog::mousePressEvent(event);
}

void BaseDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPoint targetPos = event->pos() - ui_start + pos();
        this->move(targetPos);
    }

    QDialog::mouseMoveEvent(event);
}

bool BaseDialog::eventFilter(QObject *obj, QEvent *event)
{
    BaseDialog *pDialog = qobject_cast<BaseDialog *>(obj);
    if (pDialog && event->type() == QEvent::KeyPress){
        QKeyEvent *pKeyEvent = static_cast<QKeyEvent *>(event);
        if (
            pKeyEvent->key() == Qt::Key_Return
            || pKeyEvent->key() == Qt::Key_Escape
            || pKeyEvent->key() == Qt::Key_Enter
        ){
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}

QWidget *BaseDialog::body()
{
    return ui_bd->widgetBody;
}

void BaseDialog::addCloseButton(const QString &path, const QString &hoverPath)
{
    setButtonImage(ui_bd->buttonClose, path, hoverPath);
    ui_bd->horizontalLayout->addWidget(ui_bd->buttonClose);
    connect(ui_bd->buttonClose, &QPushButton::clicked, this, &BaseDialog::reject);
}

void BaseDialog::addWidget(QWidget *w)
{
    int i = ui_bd->horizontalLayout->indexOf(ui_bd->buttonClose);
    ui_bd->horizontalLayout->insertWidget(i, w);
}
