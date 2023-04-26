
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithms.h"
#include <QDebug>
#include <QFile>
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

bool MainWindow::isCheckedKey()
{
    if ((ui->lineEdit->text() != "" && ui->lineEdit->isVisible()) || (!ui->lineEdit->isVisible()))
        return true;
    else
        return false;
}

void MainWindow::writeInFile(QString str)
{
    QFile fileResult;
    QTextStream stream;
    fileResult.setFileName("encryptionMessage.txt");
    stream.setDevice(&fileResult);
    if (fileResult.open(QIODevice::WriteOnly))
    {
        stream << str;
        fileResult.close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();
    QString key = ui->lineEdit->text();
    message = message.toLower();
    //qDebug() << message;//debugging output
    QString cipher;
    try
    {
        if (!isCheckedKey())
            throw 999;
    }
    catch(int i)
    {
        qDebug() << "Error #"+QString::number(i)+" | key is empty";
        return void();
    }
    switch(ui->comboBox->currentIndex())
    {

    case 0:
    {
        cipher = Alg.vizhener(message,key);
        qDebug()<< Alg.vizhener(message,key);
        break;
    }

    case 1:
    {
        cipher = Alg.pollibiy(message);
        qDebug() << Alg.pollibiy(message);
        break;
    }
    case 2:
    {
        cipher = Alg.gronsfeld(message,key);
        qDebug()<< Alg.gronsfeld(message,key);
        break;
    }

    case 3:{
        cipher = Alg.atbash(message);
        qDebug() << Alg.atbash(message);
        break;
    }
    case 4:{
        cipher = Alg.rot(message,key);
        qDebug() << Alg.rot(message,key);
        break;
    }
    default:
        break;
    }

    writeInFile(cipher);

}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 4 || index == 0 || index == 2)
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

