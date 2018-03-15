#include "mainwindow.h"
#include <QApplication>
#include "activity.h"
#include "list.h"
#include <QString>
#include <QDebug>
#include <QDate>
#include "listmanager.h"
#include <QProxyStyle>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    qApp->setStyle(new QProxyStyle());
    w.show();
    return a.exec();
}


