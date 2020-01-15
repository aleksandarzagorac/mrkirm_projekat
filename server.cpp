#include "server.h"
#include "myudp.h"

Server::Server(QObject *parent) : QObject(parent)
{

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1232);
    connect(socket,SIGNAL(readyRead()), this , SLOT(readyRead()));

}




void Server::readyRead()
{
/*
   QByteArray Buffer;
   Buffer.resize(socket->pendingDatagramSize());

   QHostAddress sender;
   quint16 senderPort;
   socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

   qDebug()<<"Message from: "<< sender.toString();
   qDebug()<<"Message port: "<< senderPort;
   qDebug()<<"Message: "<< Buffer;*/

}

void Server::client_recv_token()
{
    qDebug("Citanje iz Servera!\n");
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

    qDebug()<<"Message from: "<< sender.toString();
    qDebug()<<"Message port: "<< senderPort;
    qDebug()<<"Message: "<< Buffer;

}
