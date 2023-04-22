
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QString>



class Algorithms
{
public:
    Algorithms();
    QString alphavit = "abcdefghijklmnopqrstuvwxyza";

    QString rot(QString msg, QString key);
    QString atbash(QString msg);
    QString vizhener(QString msg, QString key);
    QString gronsfeld(QString msg, QString key);
    int findIt(QChar letter);



};

#endif // ALGORITHMS_H
