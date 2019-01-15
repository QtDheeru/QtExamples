#include "MyWidget.h"
#include "ui_MyWidget.h"
#include <QThread>
#include "DataGeneratorWorker.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->m_dataWorker = new DataGeneratorWorker;
    QThread *thr = new QThread;
    this->m_dataWorker->moveToThread(thr);
    connect(thr,SIGNAL(started()),m_dataWorker,SLOT(generateData()));
    thr->start();
    this->m_customModel = new SitaViewModel;
    this->m_customModel->setObjectName("Single");
    this->ui->listView->setModel(m_customModel);
    connect(m_dataWorker,&DataGeneratorWorker::sendData,m_customModel,&SitaViewModel::addData);
}

MyWidget::~MyWidget()
{
    delete ui;
}
