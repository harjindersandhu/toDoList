#include "activity.h"
#include "list.h"
#include <iostream>
#include <QDate>
#include <QString>
#include <QDebug>

Activity::Activity(){
}

Activity::Activity(QString name, QString author, QDate date, bool imp) {
    if(!setDate(date)){
        qDebug() << "Data Errata";
    }
    this->name = name;
    this->author = author;
    this->imp = imp;
    this->done = false;
}

bool Activity::setDate(QDate d){
    QDate currDat = QDate::currentDate(); // prendo la data corrente
    if(d<currDat){   // se la data di immissione è precedente alla data corrente, ritorna false! In grafica fare alert errore
        return false;
    } else {
        dateActivity = d; // altrimenti ritorna dataActivity = data di immissione
        return true;
    }
}

void Activity::setName(QString name){
    this->name = name;
}

void Activity::setAuthor(QString author){
    this->author = author;
}

void Activity::setImp(bool imp){
    this->imp = imp;
}

void Activity::setDone(bool done){
    this->done = done;
}

QString Activity::getName(){
    return name;
}

QString Activity::getAuthor(){
    return author;
}

QDate Activity::getDate(){
    return dateActivity;
}

int Activity::getImp(){
    return imp;
}

bool Activity::isDone(){
    return done;
}

bool Activity::important(){ // ritorna imp, in grafica renderlo con una stella/punto esclamativo sull'attività
    return imp;
}

void Activity::setSubactivities(std::vector<Subactivity> s){
  sottoattivita = s;
}

bool Activity::removeSubactivity(int i){
    if( !isEmpty() ){
        if(i >= sottoattivita.size() && i<0){
            return false;
        }
        sottoattivita.erase(sottoattivita.begin() + i);
        qDebug() << "La sottoattività è stata eliminata";
        return true;
    } else {
        return false;
    }
}

QString Activity::printSubactivities(){
    for(int i=0;i<sottoattivita.size();i++){
    return sottoattivita[i].getName();
    }
}

bool Activity::isEmpty(){
    return !(sottoattivita.size());
}

QString Activity::descriptor(){
    QString isImportant = (imp)?"❗️":"    ";
    QString description = name + " \t Due by:  " + dateActivity.toString("dd.MM.yyyy");
    return  description + "\t" + isImportant;
}



