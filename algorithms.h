
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
    int findIt(QChar letter);



};

#endif // ALGORITHMS_H
