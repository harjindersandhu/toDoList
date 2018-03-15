#include "newlistwindow.h"
#include "ui_newlistwindow.h"


newListWindow::newListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newListWindow){
    ui->setupUi(this);
    this->setWindowTitle("Add a new list");
}

newListWindow::~newListWindow(){
    delete ui;
}

QString newListWindow::getName(){
    return name;
}

QString newListWindow::getType(){
    return type;
}

void newListWindow::on_buttonBox_accepted(){
    name = ui->lineEdit->text();
    type = ui->lineEdit2->text();
}
