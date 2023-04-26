
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QString>
#include <QVector>
#include <string>


class Algorithms
{
public:
    Algorithms();
    QString alphavit = "abcdefghijklmnopqrstuvwxyza";
    //..QVector <QVector <char> > kvadrat;

    QString rot(QString msg, QString key);
    QString atbash(QString msg);
    QString vizhener(QString msg, QString key);
    QString gronsfeld(QString msg, QString key);
    QString pollibiy(QString msg);
    int findIt(QChar letter);





};

#endif // ALGORITHMS_H
