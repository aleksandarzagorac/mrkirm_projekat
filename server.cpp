#include "server.h"
#include "myudp.h"

Server::Server(QObject *parent) : QObject(parent)
{

    socket = new QUdpSocket(this);
    if(!socket->bind(QHostAddress("10.81.35.48"),1233)){
        qDebug("Greska nije server bind uspeo");
    } else {
        qDebug("Server bind done.");
    }
    socket->open(QAbstractSocket::ReadWrite);
    connect(socket, SIGNAL(readyRead()), this, SLOT(prihvatanje_poruke()));
    //connect(this ,SIGNAL(sPrihvatanje_poruke()), this , SLOT(prihvatanje_poruke()));
    //emit sPrihvatanje_poruke();

}




void Server::readyRead()
{


}

void Server::prihvatanje_poruke()
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
