#include "listmanager.h"
#include "list.h"
#include "activity.h"
#include <QDate>
#include <vector>
#include <QString>
#include <iostream>

ListManager::ListManager(){
}

//ListManager::~ListManager(){
//    delete u;
//}

void ListManager::printLists(){ // metodo provvisorio per la verifica
    for (int i=0; i<u.size();i++){
            qDebug() << u[i].getName() << " " << u[i].getType();
    }
}

bool ListManager::isEmpty(){ // per verificare se il vettore ListManager è vuoto o meno
    return !(u.size()>0);
}

List ListManager::getActivitiesFromIndex(int i){
    return u[i];
}

std::vector<QString> ListManager::getListNameFromIndex(int i){
    tm = u[i].getNameList();
    return tm;
}

void ListManager::createList(QString name, QString type ){
    List nuovaLista(name, type);
    u.push_back(nuovaLista);
}

bool ListManager::removeList(QString n){ // rimuove la lista all'indice i col nome uguale a quello passato col parametro n
   if( !isEmpty() ){
       int j = -1;
       for(int i = 0; i<u.size(); i++){
           if(u[i].getName() == n){
               j = i;
                u.erase(u.begin() + i);
                qDebug() << "La lista è stata eliminata";
            }else
                return false;
       }
    }
}

bool ListManager::removeList(int i){ // REMOVE PRINCIPALE
    if( !isEmpty() ){
        if(i >= u.size() && i<0){
            return false;
        }
        u.erase(u.begin() + i);
        qDebug() << "La lista è stata eliminata";
        return true;
    } else {
        return false;
    }
}

int ListManager::returnSize(){
    return u.size();
}

QString ListManager::getNameAct(int i){
    QString a = u[i].getName();
    return a;
}
