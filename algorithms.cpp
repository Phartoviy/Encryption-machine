
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

QString Algorithms::vizhener(QString msg, QString key)
{
    QString keyWord = key;
    QString encryptedMessage;
    while(keyWord.length() < msg.length())
    {
        keyWord += key;
    }
    //qDebug() << keyWord;
    for (int i = 0;i<msg.length();i++)
    {
        encryptedMessage += alphavit[(findIt(keyWord[i])+findIt(msg[i])) % 26];
    }
    return encryptedMessage;
}

QString Algorithms::atbash(QString msg)
{
    QString encryptedMessage;
    for (int i = 0;i<msg.length();i++)
    {
        encryptedMessage += alphavit[(26 - findIt(msg[i])-1)];
    }
    return encryptedMessage;
}
