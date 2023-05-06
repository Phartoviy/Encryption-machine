
#include "algorithms.h"
#include "mainwindow.h"
#include <QDebug>
#include <QtMath>
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

QString Algorithms::decryptionRot(QString msg, QString key)
{
    int shift = key.toInt();
    QString encryptedMessage;
    for (int i = 0;i<msg.length();i++)
    {
        if (msg[i] == ' '){
            encryptedMessage += ' ';
            continue;
        }
        if ((findIt(msg[i])-shift)>=0)
            encryptedMessage += alphavit[(findIt(msg[i])-shift)];
        else
            encryptedMessage += alphavit[((findIt(msg[i])-shift)+26)];

    }
    return encryptedMessage;

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

int Algorithms::getDigit(QChar ch)
{
    QString digits = "12345";
    for (int i =0;i<10;i++)
    {
        if (ch == digits[i])
            return i;
    }
    return 0;
}

QString Algorithms::decryptionPollibiy(QString msg)
{
        QString encryptedMessage = "";
        QString kvadrat[5] ={ "abcde","fghik","lmnop","qrstu","vwxyz"};
        for (int i = 0; i < msg.length()-1; i += 2) {
            if (msg[i] == ' ')
            {
                i--;
                encryptedMessage +=' ';
                continue;
            }
            int row = getDigit(msg[i]);
            int col = getDigit(msg[i+1]);
            encryptedMessage += kvadrat[row][col];
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
            encryptedMessage += "24";
            continue;
        }
        for (int i = 0;i<5;i++)
        {
         for (int j = 0;j<5;j++)
         {
             if (msg[h] == kvadrat[i][j])
             {
                 encryptedMessage += QString::number(i+1)+QString::number(j+1);
             }
         }
        }

    }
    return encryptedMessage;
}

QString Algorithms::decryptionGronsfeld(QString msg, QString key)
{
    QString plaintext = "";
    int keyIndex = 0;
    for (int i = 0; i < msg.length(); i++) {
        int shift = getDigit(key[keyIndex])+1;
        if (msg[i] == ' ')
        {
          plaintext += ' ';
          continue;
        }
        plaintext += alphavit[(findIt(msg[i])-shift) % 26];
        keyIndex = (keyIndex + 1) % key.length();
    }
    return plaintext;

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

QString Algorithms::decryptionVizhener(QString msg, QString key)
{

    QString plaintext = "";
    int keyIndex = 0;
    for (int i = 0; i < msg.length(); i++) {
        int shift = findIt(key[keyIndex]);
        if (msg[i] == ' ')
        {
         plaintext += ' ';
         continue;
        }
        plaintext += alphavit[(findIt(msg[i])-shift) % 26];
        keyIndex = (keyIndex + 1) % key.length();
    }
    return plaintext;


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

QString Algorithms::decryptionAtbash(QString msg)
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
