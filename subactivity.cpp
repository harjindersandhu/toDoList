#include "subactivity.h"

Subactivity::Subactivity(){
}

Subactivity::Subactivity(QString name){
    this->name = name;
}

void Subactivity::setName(QString n){
    name = n;
}

QString Subactivity::getName(){
    return name;
}

