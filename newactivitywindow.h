#ifndef NEWACTIVITYWINDOW_H
#define NEWACTIVITYWINDOW_H

#include <QDialog>
#include <QDate>
#include <QCheckBox>
#include "activity.h"
#include <QMessageBox>

namespace Ui {
class newActivityWindow;
}

class newActivityWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newActivityWindow(QWidget *parent = 0);
    ~newActivityWindow();
    QString getName();
    QString getAuthor();
    QDate setDate();
    QDate getDate();
    bool isImp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newActivityWindow *ui;
    QString name;
    QString author;
    QDate data;
    bool important;
    Activity* a;
};

#endif // NEWACTIVITYWINDOW_H
