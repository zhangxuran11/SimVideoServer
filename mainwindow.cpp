#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ztpprotocol.h"
void MainWindow::sendChannel()
{
    ZTPprotocol ztp;
    ztp.addPara("T","T_ChId");
    ztp.addPara("ChId",ui->lineEdit->text());
    qDebug()<<"send...";
    ztpm->SendOneZtp(ztp,QHostAddress("224.102.228.40"),7789);
}
void MainWindow::fun()
{
    ZTPprotocol ztp;
    ztpm->getOneZtp(ztp);
    qDebug()<<"recv...";
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerSend = new QTimer();
    timerSend->setSingleShot(false);
    timerSend->setInterval(1000);
    connect(timerSend,SIGNAL(timeout()),this,SLOT(sendChannel()));
    timerSend->start();
    ztpm = new ZTPManager(7789,QHostAddress("224.102.228.40"));
    connect(ztpm,SIGNAL(readyRead()),this,SLOT(fun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
