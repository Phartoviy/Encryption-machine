
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "algorithms.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int count = 0;//temp value

private slots:
    void on_pushButton_clicked();
    void fileChooser();
    bool isCheckedKey();
    void on_comboBox_currentIndexChanged(int index);
    void writeInFile(QString str);
    QString readFromFile(QString fileName);
    void decryption();
    void aboutInfo();
    void on_actionInformation_triggered();

private:
    Ui::MainWindow *ui;
    Algorithms Alg;
    QString fileName;
    QString encrypt;
};

#endif // MAINWINDOW_H
