#include "myudp.h"
#include "token_str.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1232);
    connect(socket,SIGNAL(readyRead()), this , SLOT(readyRead()));
}



void MyUDP::SayHello()
{
    QByteArray Data;


    struct Token tok;
    Data.append(qUtf8Printable(tok.str));

    socket->writeDatagram(Data, QHostAddress::LocalHost, 1232);
    //socket->writeDatagram(t.str, QHostAddress::LocalHost, 1232);
}



 void MyUDP::readyRead()
 {

    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

    qDebug()<<"Message from: "<< sender.toString();
    qDebug()<<"Message port: "<< senderPort;
    qDebug()<<"Message: "<< Buffer;

 }
