
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
        if (msg[i] == ' '){
            encryptedMessage += ' ';
            continue;
        }
        encryptedMessage += alphavit[(findIt(msg[i])+shift)%26];
    }

    return encryptedMessage;
}

QString Algorithms::pollibiy(QString msg)
{
    QString encryptedMessage;
    QString kvadrat[5] ={ "abcde","fghik","lmnop","qrstu","vwxyz"};
    for (int h = 0;h<msg.length();h++)
    {
        if (msg[h] == ' '){
            encryptedMessage += ' ';
            continue;
        }
        if (msg[h] == 'j')
        {
            encryptedMessage += "24 ";
            continue;
        }
        for (int i = 0;i<5;i++)
        {
         for (int j = 0;j<5;j++)
         {
             if (msg[h] == kvadrat[i][j])
             {
                 encryptedMessage += QString::number(i+1)+QString::number(j+1)+' ';
             }
         }
        }

    }
    return encryptedMessage;
}

QString Algorithms::gronsfeld(QString msg, QString key)
{
    QString keyWord = key;
    QString encryptedMessage;
    int count = 0;
    while(keyWord.length() < msg.length())
    {
        keyWord += key;
    }
    //qDebug()<< keyWord[1].digitValue();
    for (int i = 0;i<msg.length();i++)
    {
        if (msg[i] == ' '){
         encryptedMessage += ' ';
         continue;
        }
        encryptedMessage += alphavit[(keyWord[count++].digitValue() + findIt(msg[i])) % 26];
    }



    return encryptedMessage;
}

QString Algorithms::vizhener(QString msg, QString key)
{
    QString keyWord = key;
    QString encryptedMessage;
    int count = 0;
    while(keyWord.length() < msg.length())
    {
        keyWord += key;
    }
    //qDebug() << keyWord;
    for (int i = 0;i<msg.length();i++)
    {
        if (msg[i] == ' '){
         encryptedMessage += ' ';
         continue;
        }
        encryptedMessage += alphavit[(findIt(keyWord[count++])+findIt(msg[i])) % 26];
    }
    return encryptedMessage;
}

QString Algorithms::atbash(QString msg)
{
    QString encryptedMessage;
    for (int i = 0;i<msg.length();i++)
    {
        if (msg[i] == ' '){
         encryptedMessage += ' ';
         continue;
        }
        encryptedMessage += alphavit[(26 - findIt(msg[i])-1)];
    }
    return encryptedMessage;
}
