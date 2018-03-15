#ifndef NEWLISTWINDOW_H
#define NEWLISTWINDOW_H

#include <QDialog>

namespace Ui {
class newListWindow;
}

class newListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newListWindow(QWidget *parent = 0);
    ~newListWindow();
    QString getName();
    QString getType();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newListWindow *ui;
    QString name;
    QString type;
};

#endif // NEWLISTWINDOW_H
