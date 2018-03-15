#include "list.h"
#include "activity.h"
#include "listmanager.h"
#include <QDate>
#include <QString>
#include <QDebug>
#include <vector>

List::List(){
}

List::List(QString name, QString type){
    this->name = name;
    this->type = type;
}

//List::~List(){
//   delete v;
//}

void List::setName(QString name){
   this->name = name;
}

void List::setType(QString type){
    this->type = type;
}

QString List::getName(){
    return name;
}

QString List::getType(){ // ritorna il tipo di un'attività, es: "Svago", "Scuola"
    return type;
}

bool List::isEmpty(){
   return !(v.size()); // per verificare se il vettore lista è vuoto o meno
}

void List::addActivity(Activity a){ // aggiunge un'attività al vector di List
    v.push_back(a);
}

bool List::removeActivity(Activity a){
    // dall'attività passata in ingresso mi richiama la removeActivity(QString n), dove n = a.getName()
    // (che a sua volta richiama la REMOVE PRINCIPALE con l'indice trovato)
    return removeActivity(a.getName());
}

bool List::removeActivity(int i){ // REMOVE PRINCIPALE
    //  ha in ingresso l'indice dell'attività da eliminare, verifica che non sia vuota
    // e successivamente elimina l'attività all'indice i
    if( !isEmpty() ){
        if(i >= v.size() && i<0){
            return false;
        }
        v.erase(v.begin() + i);
        qDebug() << "L'attività è stata eliminata";
        return true;
    } else {
        return false;
    }
}

bool List::removeActivity(QString n){ // booleano che ritorna il metodo REMOVE PRINCIPALE sopra con in ingresso l'indice ricavato da findIndex(n)
    return removeActivity(findIndex(n));
}

int List::findIndex(QString n){ // ritorna l'indice di un'attività, si scorre il vector fino a trovare il nome cercato
    int j = -1;
    for(int i = 0; i<v.size(); i++){
        if(v[i].getName() == n){
            j = i;
            break;
        }
    }
    return j;
}

QString List::getNameAct(int i){
    QString a = v[i].getName();
    return a;
}

QString List::getAuthorAct(int i){
    QString a = v[i].getAuthor();
    return a;
}

QDate List::getDateAct(int i){
    QDate d = v[i].getDate();
    return d;
}

bool List::getImpAct(int i){
    int s = v[i].getImp();
    if (s==1){
        return true;
    }else{
        return false;
    }
}

bool List::isDone(int i){
    if (v[i].isDone()==true){
        return true;
    }else{
        return false;
    }
}

std::vector<QString> List::getNameList(){
    for (int i=0; i<v.size();i++){
     nameList.push_back(v[i].getName());
    }
}

int List::size(){
    return v.size();
}

void List::printListActivities(){ // metodo provvisorio per vedere il funzionamento del codice
    //qDebug() << "sono dentro la lista";
    for (int i=0; i<v.size();i++){
            //qDebug() << v[i].getName() << " " << v[i].getAuthor() << " "<< v[i].getDate() << " " << v[i].getImp() ;
    }
}

Activity* List::getActivity(int i){
    return &v.at(i);
}


