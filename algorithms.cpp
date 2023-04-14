
#include "algorithms.h"
#include "mainwindow.h"
#include <QDebug>
Algorithms::Algorithms()
{


}

int Algorithms::findIt(QChar letter)
{
    for (int i = 0;i<26;i++)
    {
        if (letter == alphavit[i])
            return i;
    }
    return 0;
}

QString Algorithms::rot(QString msg, const QString key)
{

    int shift = key.toInt();
    QString encryptedMessage;
    for (int i = 0;i<msg.length();i++)
    {
        //qDebug()<< findIt(msg[i]);
        encryptedMessage += alphavit[(findIt(msg[i])+shift)%26];
    }

    return encryptedMessage;
}
