#include "newactivitywindow.h"
#include "ui_newactivitywindow.h"
#include <QCheckBox>
newActivityWindow::newActivityWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newActivityWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a new activity");
}

newActivityWindow::~newActivityWindow(){
    delete ui;
}

QString newActivityWindow::getName(){
    return name;
}

QString newActivityWindow::getAuthor(){
    return author;
}

QDate newActivityWindow::setDate(){
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
}

QDate newActivityWindow::getDate(){
    return data;
}

bool newActivityWindow::isImp(){
    if (ui->checkBox->isChecked()==true){
        return true;
    }else{
        return false;
    }
}

void newActivityWindow::on_buttonBox_accepted(){
    name = ui->lineEdit->text();
    author = ui->lineEdit2->text();
    data = ui->dateEdit->date();
    important = ui->checkBox->isChecked();
}

