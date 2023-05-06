
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithms.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QProgressDialog>
#include <QMessageBox>

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

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(fileChooser()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(decryption()));

    //qDebug() << char(48);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutInfo()
{
    //QMesssageBox* messageBox = new QMessageBox(QMessageBox::Information,"MesaageBox","Encryption Machine",QMessageBox::Cancel);
}

void MainWindow::fileChooser()
{
    fileName = QFileDialog::getOpenFileName();
    ui->label_3->setText(fileName);

}

void MainWindow::decryption()
{
    QString message = readFromFile(fileName);
    QString key = ui->lineEdit_2->text();
    //some code
    switch(ui->comboBox->currentIndex())
    {

    case 0:
    {
        qDebug() << Alg.decryptionVizhener(message,key);
        break;
    }

    case 1:
    {
        qDebug() << Alg.decryptionPollibiy(message);
        break;
    }
    case 2:
    {
        qDebug() << Alg.decryptionGronsfeld(message,key);
        break;
    }

    case 3:{
        qDebug() << Alg.decryptionAtbash(message);
        break;
    }
    case 4:{
        qDebug() << Alg.decryptionRot(message,key);
        break;
    }
    default:
        break;
    }


}

QString MainWindow::readFromFile(QString fileName)
{
    QFile file(fileName);
    QString str;
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        str = stream.readAll();
        //qDebug() << str;//test debug out
        file.close();
    }
    return str;
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
        ui->label_2->show();
        ui->lineEdit_2->show();
    }
    else
    {
        ui->label->hide();
        ui->lineEdit->hide();
        ui->label_2->hide();
        ui->lineEdit_2->hide();
    }
}


void MainWindow::on_actionInformation_triggered()
{
    QMessageBox::information(this,"Information","Encryption Machine");
}

