#ifndef LIST_H
#define LIST_H
#include <QDate>
#include "activity.h"
#include <vector>
#include <QDebug>

class List{

public:
    List(); 
    List (QString name, QString type);
    //~List();
    void setName(QString name);
    void setType(QString type);
    QString getName();
    QString getType();
    bool isEmpty();
    void addActivity(Activity a);
    bool removeActivity(Activity a);
    bool removeActivity(int i);
    bool removeActivity(QString n);
    void printListActivities();
    int findIndex(QString n);
    QString getNameAct(int i);
    QString getAuthorAct(int i);
    QDate getDateAct(int i);
    bool getImpAct(int i);
    bool isDone(int i);
    std::vector<QString> getNameList();
    int size();
    Activity* getActivity(int i);

private:
    std::vector<Activity> v; // vettore delle attività
    QString type; // es: "Svago", "Scuola"
    QString name; // es: "Film da guardare" , "Matematica"
    std::vector<QString> nameList;
};

#endif // LIST_H
