#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listmanager.h"
#include "list.h"
#include "activity.h"
#include "activityinfo.h"
#include <QDate>
#include <QErrorMessage>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    listModel = new QStandardItemModel();
    this->setWindowTitle("ToDo List");
    lastRowSelectedList = 0;
    lastRowSelectedActivities = 0;
}
MainWindow::~MainWindow(){
    delete ui;
}

/*void MainWindow::createItemList(){
    //qDebug() <<"accettato";
}*/

void MainWindow::on_newList_clicked(){ // click sul button "Create new List"
    lastRowSelectedList = arrayListe.size();
    newList = new newListWindow();
    QObject::connect(newList, SIGNAL(accepted()), this, SLOT(createItemList()));
        if(newList->exec() != 0){
        QString s = QString(newList->getName());  // casella Nome
        QString r = QString(newList->getType()); // casella Tipo
        arrayListe.push_back(List(s, r));
        updateListView();
        updateActivityView();
        }
}

void MainWindow::on_newAct_clicked(){ // click sul button "Add new activity"
    lastRowSelectedActivities = arrayListe[lastRowSelectedList].size();
    newActivity = new newActivityWindow();
    newActivity->setDate();
    QObject::connect(newActivity,SIGNAL(accepted()), this, SLOT(createItemList()));
    if (arrayListe.size() == 0){
        QMessageBox::information(
            this,
            tr("Application Name"),
            tr("Inserisci prima una lista") );
    }
    else{
    if(newActivity->exec()!=0){
        int currentRow = ui->liste->currentRow(); // in currentRow abbiamo il numero della lista
        QString n = QString(newActivity->getName()); // mette in n il nome della nuova attività
        QString a = QString(newActivity->getAuthor()); // mette in a l'autore della nuova attività
        QDate d = QDate(newActivity->getDate()); // mette in d la data creata
        bool c = bool(newActivity->isImp()); // mette in c imp
        Activity b(n, a, d, c); // creo una nuova attività che prende s al nome
        if(b.setDate(d)==false){
            QMessageBox::information(
                this,
                tr("Application Name"),
                tr("Data errata") );
            return;
        }
        arrayListe[currentRow].addActivity(b);
        updateActivityView();
        updateListView();
    }
    }
}

void MainWindow::updateActivityView(){ 
    ui->vistaLista->clear();
    int currentRow = ui->liste->currentRow();
    if(currentRow >= 0 && currentRow < arrayListe.size() ){
        for (int i=0;i<arrayListe[currentRow].size();i++){
            if ( arrayListe[currentRow].getActivity(i)->isDone() ){
            ui->vistaLista->addItem(arrayListe[currentRow].getActivity(i)->descriptor() + " " + "Done:☑️");
            updateListView();

            }else{
                   ui->vistaLista->addItem(arrayListe[currentRow].getActivity(i)->descriptor());
                 }
        }
    }
    ui->vistaLista->setCurrentRow( lastRowSelectedActivities );
}

void MainWindow::updateListView(){
    ui->liste->clear();
    for (int i=0;i<arrayListe.size();i++){
        List currentList = arrayListe.at(i);
        ui->liste->addItem( QString( currentList.getName() + "-" + currentList.getType() +" \t " + QVariant(currentList.size()).toString()));
    }
        ui->liste->setCurrentRow(lastRowSelectedList);
}

void MainWindow::on_liste_clicked(const QModelIndex &index){
    lastRowSelectedList = ui->liste->currentRow();
    lastRowSelectedActivities = 0;
    updateActivityView();
}

void MainWindow::on_vistaLista_itemDoubleClicked(QListWidgetItem *item){
    lastRowSelectedActivities = ui->vistaLista->currentRow();
    windowActivity = new activityinfo();
    QObject::connect(windowActivity, SIGNAL(accepted()), this, SLOT(updateListView()));

    int currentActivityRow = ui->vistaLista->currentRow();
    int currentListRow = ui->liste->currentRow();

    windowActivity->setName(arrayListe[currentListRow].getNameAct(currentActivityRow));
    windowActivity->setAutore(arrayListe[currentListRow].getAuthorAct(currentActivityRow));
    windowActivity->setSubactivities(arrayListe[currentListRow].getActivity(currentActivityRow)->getSub());
    QDate d = arrayListe[currentListRow].getDateAct(currentActivityRow);
    windowActivity->setDate(d);
    windowActivity->updateSubactivitiesView();
    windowActivity->setDone( arrayListe[currentListRow].getActivity(currentActivityRow)->isDone() );

    if (arrayListe[currentListRow].getImpAct(currentActivityRow)==true){
        windowActivity->isImp();
    }
    windowActivity->exec();
        arrayListe[currentListRow].getActivity(currentActivityRow)->setName(windowActivity->getName());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setAuthor(windowActivity->getAuthor());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setDate(windowActivity->getDate());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setImp(windowActivity->getImp());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setSubactivities(windowActivity->getSub());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setDone(windowActivity->Done());
        updateActivityView();
}

void MainWindow::on_deleteActivity_clicked(){
    lastRowSelectedActivities = arrayListe[lastRowSelectedList].size()-1;
    int currentActivityRow = ui->vistaLista->currentRow();
    int currentListRow = ui->liste->currentRow();
    if( arrayListe[currentListRow].size() <= 0){
        return;
    }
    arrayListe[currentListRow].removeActivity(currentActivityRow);
    updateActivityView();
    updateListView();
    ui->vistaLista->setCurrentRow( arrayListe[currentListRow].size()-1 );
}
void MainWindow::on_deleteList_clicked(){
    if( arrayListe.size() > 0 ){
        int currentListRow = ui->liste->currentRow();
        arrayListe.erase(arrayListe.begin() + currentListRow);
        updateListView();
        updateActivityView();
        ui->liste->setCurrentRow(arrayListe.size()-1);
    }
}

void MainWindow::on_liste_itemDoubleClicked(QListWidgetItem *item){
    newActivity = new newActivityWindow();
    newActivity->setDate();
    QObject::connect(newActivity,SIGNAL(accepted()), this, SLOT(createItemList()));
    if (arrayListe.size() == 0){
        QMessageBox::information(
            this,
            tr("Application Name"),
            tr("Inserisci prima una lista") );
    }
    else{
    if(newActivity->exec()!=0){
        int currentRow = ui->liste->currentRow(); // in currentRow abbiamo il numero della lista
        QString n = QString(newActivity->getName()); // mette in n il nome della nuova attività
        QString a = QString(newActivity->getAuthor()); // mette in a l'autore della nuova attività
        QDate d = QDate(newActivity->getDate()); // mette in d la data creata
        bool c = bool(newActivity->isImp()); // mette in c imp
        Activity b(n, a, d, c); // creo una nuova attività che prende s al nome
        if(b.setDate(d)==false){
            QMessageBox::information(
                this,
                tr("Application Name"),
                tr("Data errata") );
            return;
        }
        arrayListe[currentRow].addActivity(b);
        updateActivityView();
        updateListView();
    }
    }
}
