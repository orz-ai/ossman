#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class BaseDialog; }
QT_END_NAMESPACE

class BaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDialog(QWidget *parent = nullptr);
    ~BaseDialog();

    void setTitle(const QString &title);
    void setLogo(const QString &path);
    void addMinButton(const QString path, const QString &hoverPath);
    void addMaxButton(const QString maxPath, const QString &hoverMaxPath, const QString &normalPath, const QString hoverNormalPath);
    QPushButton* addButton(const QString &path, const QString &hoverPath);
    void setButtonImage(QPushButton* btn, const QString &path, const QString &hoverPath);
    void setAllButtonSize(int w=20);
    void setKeyDisabled();
    void addTitleLine(int w=2);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    bool eventFilter(QObject *obj, QEvent* event);
    QWidget* body();

    Ui::BaseDialog *ui_bd;

private:
    void addCloseButton(const QString& path, const QString& hoverPath);
    void addWidget(QWidget* w);

    QPoint ui_start;
    int ui_size = 20;

};

#endif // BASEDIALOG_H
