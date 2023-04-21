
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithms.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Алгоритм Виженера");
    ui->comboBox->addItem("Квадрат Поллибия");
    ui->comboBox->addItem("Алгоритм Гронсфельда");
    ui->comboBox->addItem("Алгоритм Атбаш");
    ui->comboBox->addItem("ROT");
    //ui->label->hide();
    //ui->lineEdit->hide();
    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(print()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    qDebug()<<"hello";
}

void MainWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();
    QString key = ui->lineEdit->text();
    qDebug() << message;//debugging output
    switch(ui->comboBox->currentIndex())
    {

    case 0:
    {
        qDebug()<< Alg.vizhener(message,key);
        break;
    }


    case 3:{
        qDebug() << Alg.atbash(message);
        break;}
    case 4:{
        qDebug() << Alg.rot(message,key);
        break;}


    default:
        break;
    }



}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 4 || index == 0)
    {
        ui->label->show();
        ui->lineEdit->show();
    }
    else
    {
        ui->label->hide();
        ui->lineEdit->hide();
    }
}

