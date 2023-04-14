
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

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();
    QString key = ui->lineEdit->text();
    qDebug() << message;//debugging output
    switch(ui->comboBox->currentIndex())
    {

    case 4:
        qDebug() << Alg.rot(message,key);
        break;




    default:
        break;
    }



}


