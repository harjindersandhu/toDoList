#ifndef SUBACTIVITY_H
#define SUBACTIVITY_H
#include <QString>
#include <vector>



class Subactivity{

public:
    Subactivity();
    Subactivity(QString name);
    void setName(QString name);
    QString getName();

private:
    QString name;
};

#endif // SUBACTIVITY_H
