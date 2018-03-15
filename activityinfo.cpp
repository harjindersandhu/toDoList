#include "activityinfo.h"
#include "ui_activityinfo.h"
#include "activity.h"



activityinfo::activityinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activityinfo){
    ui->setupUi(this);
    this->setWindowTitle("Activity description");
}

activityinfo::~activityinfo(){
    delete ui;
}

QString activityinfo::getName(){
    return ui->nome->text();
}

QString activityinfo::getAuthor(){
    return ui->autore->text();
}

QDate activityinfo::getDate(){
    return ui->data->date();
}

bool activityinfo::getImp(){
    return ui->importante->checkState();
}

std::vector<Subactivity> activityinfo::getSub(){
    return subactivities;
}

void activityinfo::setName(QString n){
    ui->nome->setText(n);
}

void activityinfo::setAutore(QString a){
    ui->autore->setText(a);
}

QDate activityinfo::setDate(QDate d){
    ui->data->setDate(d);
}

void activityinfo::setSubactivities(std::vector<Subactivity> subs){
    subactivities = subs;
}

void activityinfo::isImp(){
    ui->importante->setChecked(true);
}

//void activityinfo::isNotImp(){
//    ui->importante->setText("NO");
//}

bool activityinfo::Done(){
    if (ui->checkBox->isChecked()==true){

        return true;
    }else{

        return false;
    }
}

void activityinfo::on_add_clicked(){
    Subactivity s (ui->lineEdit->text());
    subactivities.push_back(s);
    updateSubactivitiesView();
    ui->lineEdit->clear();
}

void activityinfo::updateSubactivitiesView(){
    ui->listWidget->clear();
    for(int i = 0; i < subactivities.size(); i++)
        ui->listWidget->addItem(subactivities[i].getName());
        ui->listWidget->setCurrentRow(subactivities.size()-1);

}

void activityinfo::setDone(bool d){
    if(d)
        ui->checkBox->toggle();
}

void activityinfo::on_remove_clicked(){
    if (subactivities.size() == 0){
        return;
    }
    int i = ui->listWidget->currentRow();
    subactivities.erase(subactivities.begin() + i);
    updateSubactivitiesView();
}

void activityinfo::on_save_clicked(){
   this->close();
}
