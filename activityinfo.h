#ifndef ACTIVITYINFO_H
#define ACTIVITYINFO_H

#include <QDialog>
#include "newactivitywindow.h"
#include <QDate>
#include "activity.h"
#include "subactivity.h"
#include "list.h"


namespace Ui {
class activityinfo;
}

class activityinfo : public QDialog
{
    Q_OBJECT

public:
    explicit activityinfo(QWidget *parent = 0);
    ~activityinfo();  
    void setName(QString n);
    void setAutore(QString a);
    QDate setDate(QDate d);
    void setSubactivities(std::vector<Subactivity> subs);
    void isImp();
    QString getName();
    QString getAuthor();
    QDate getDate();
    bool getImp();
    std::vector<Subactivity> getSub();
    bool Done();
    void updateSubactivitiesView(); //aggiorna ogni volta la vista di listwidget
    void setDone(bool d);

private slots:
    void on_add_clicked();
    void on_remove_clicked();
    void on_save_clicked();

private:
    std::vector<List> *activityList;
    Ui::activityinfo *ui;
    QString name;
    std::vector<Subactivity> subactivities;
    Activity* a;
};

#endif // ACTIVITYINFO_H
