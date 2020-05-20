#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include <QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar*rejuBar = menuBar();
    setMenuBar(menuBar());

    QMenu *rejuMenu = rejuBar->addMenu("焕肤");
    QAction *act1 = new QAction(QIcon("://Image/设置.png"),"白色靓丽");
    QAction *act2 = new QAction(QIcon("://Image/设置.png"),"黑色炫酷");
    rejuMenu->addAction(act1);

    rejuMenu->addSeparator();
    rejuMenu->addAction(act2);

    //怎么连接一个信号呢
    connect(act1,&QAction::triggered,act1,[=](){
        com::setStyle("://Proj/black.qss");
    });

    connect(act2,&QAction::triggered,act2,[=](){
        com::whiteStyle();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    com::setStyle("://Proj/black.qss");

}

void MainWindow::on_pushButton_2_clicked()
{
//     com::setStyle("://Proj/white.qss");
}
