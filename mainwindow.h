#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include "newlistwindow.h"
#include "newactivitywindow.h"
#include "activityinfo.h"
#include <QListWidgetItem>
#include <QListWidget>
#include "list.h"
#include "listmanager.h"
#include "activity.h"
#include <QDate>
#include <QErrorMessage>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:   
    void on_newList_clicked();
    // void createItemList();
    //void on_liste_itemClicked(QListWidgetItem *item);
    void on_newAct_clicked();
    void on_liste_clicked(const QModelIndex &index);
    void on_vistaLista_itemDoubleClicked(QListWidgetItem *item);
    void updateActivityView();
    void updateListView();
    void on_deleteActivity_clicked();
    void on_deleteList_clicked();
    void on_liste_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *listModel;
    newListWindow* newList;
    newActivityWindow* newActivity;
    activityinfo* windowActivity;
    std::vector<List> arrayListe;
    int lastRowSelectedList;
    int lastRowSelectedActivities;
};

#endif // MAINWINDOW_H
