#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include <QAction>
#include <QtDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    com::setStyle("://Proj/white.qss");
    //这些都改成为qss样式
    setWindowTitle("Rabbitchenc style demo");
    ui->helpAction->setIcon(QIcon("://Image/sysicon/帮助.png"));
    ui->openAction->setIcon(QIcon("://Image/File/open.jpg"));
    ui->closeAction->setIcon(QIcon("://Image/File/clo.png"));
    ui->saveAction->setIcon(QIcon("://Image/File/save.png"));
    ui->deleteAction->setIcon(QIcon("://Image/sysicon/delete.png"));
    ui->newAction->setIcon(QIcon("://Image/File/new.jpeg"));
    ui->rejuAction->setIcon(QIcon("://Image/File/皮肤.png"));
    QPixmap img = QPixmap(":/Image/庄周.jpeg");
    ui->label->setPixmap(img);
    ui->textEdit->setText("蝴蝶是我，抑或我就是蝴蝶？");


    ui->tableAttri->setColumnCount(2);
    ui->tableAttri->setHorizontalHeaderLabels(QStringList()<<"属性"<<"星数");
    ui->tableAttri->setRowCount(5);
    ui->tableAttri->setItem(0,0);

    ui->tableSkill->setColumnCount(2);
    //文件对话框   打开文件夹  过滤打开文件夹
//    ui->tableAttri->setHorizontalHeaderLabels(QStringList()<<"属性"<<"星数");

    //字体对话框 颜色对话框  用不到


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_styleWhite_triggered()
{
    com::setStyle("://Proj/white.qss");
}

void MainWindow::on_styleBlack_triggered()
{
    com::setStyle("://Proj/black.qss");
}


void MainWindow::on_yesRadioButton_clicked()
{
    ui->checkBoxKun->setEnabled(true);
    ui->checkBoxFish->setEnabled(true);
    ui->checkBoxBird->setEnabled(true);
    ui->checkBoxBoth->setEnabled(true);

}

void MainWindow::on_noRadioButton_clicked()
{
     ui->checkBoxBird->setEnabled(false);
     ui->checkBoxBoth->setEnabled(false);
     ui->checkBoxKun->setEnabled(false);
     ui->checkBoxFish->setEnabled(false);
}


void MainWindow::on_closeAction_triggered()
{
    this->close();
}

void MainWindow::on_openAction_triggered()
{
    QFileDialog::getOpenFileName(this,"打开文件","/home/rabbitchenc/下载","*.txt");

}

void MainWindow::on_fontAction_triggered()
{
    bool flag;
    QFontDialog::getFont(&flag,this);
}

void MainWindow::on_colorAction_triggered()
{
    QColorDialog::getColor();
}

void MainWindow::on_aboutAction_triggered()
{
    QMessageBox::aboutQt(this);
}
