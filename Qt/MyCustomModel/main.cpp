#include "MyWidget.h"
#include <QApplication>
#include <QStringListModel>
#include <QListView>
#include <QTableView>
#include <QSortFilterProxyModel>
#include "SitaViewModel.h"
#include "MyProxyModel.h"
/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This program shows the custom model can be written
 *
 *
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SitaViewModel *model = new SitaViewModel();
    QTableView tview;
    model->setObjectName("Single");
    model->startInsert();
    tview.setModel(model);
    tview.show();

    SitaViewModel *model2 = new SitaViewModel();
    QTableView tview1;
    model2->startInsert();
    tview1.setModel(model2);
    tview1.show();

    /*
    MyProxyModel proxyModel;
    proxyModel.setSourceModel(model);
    proxyModel.setStartRow(0);
    proxyModel.filterAcceptsRow(0,QModelIndex());

    MyProxyModel proxyModel1;
    proxyModel1.setSourceModel(model);
    proxyModel1.setStartRow(1);

    */
    //    QListView lView;
    //    lView.setModel(model);
    //    lView.show();

    //    QSortFilterProxyModel filterModel;
    //    filterModel.setSourceModel(model);
    //    if (filterModel.removeRows(1,2)) {
    //        qDebug() << " Rows removed successfully"<<endl;
    //    }else {
    //        qDebug() << " Rows NOT removed successfully"<<endl;
    //    }
    //    QTableView tview;
    //    tview.setModel(&filterModel);
    //    tview.show();




    return a.exec();
}
int main_unused(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QStringList list;
    list << "Raj" << "Praveen" << "Imran"<<"Guru"<<"Hari";


    QStringList list1;
    list << "S1" << "S2" << "S3";

    QStringListModel *model = new QStringListModel();
    model->setStringList(list);

    QListView lView;
    lView.setModel(model);
    lView.show();

    QTableView tview;
    tview.setModel(model);
    tview.show();


    return a.exec();
}

