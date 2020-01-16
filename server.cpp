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
    qDebug("Dosli smo do waitForReadyRead()");

    connect(socket, SIGNAL(readyRead()), this, SLOT(prihvatanje_poruke()));
    this->uspostava_veze_clienti();

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

    if(Buffer == "inicijalna"){
        qDebug("\nporuka JESTE inicijalna\n");
    }

}
void Server::uspostava_veze_clienti()
{
    int n;
    //do{
        qDebug("Unesite koliko zelite klijenata\n"
               "Radi jednostavnosti 3-6");
        QTextStream qtin(stdin);
        QString line = qtin.readLine();
        n = line.toInt();
   // }while (!(n >= 3 && n <= 7));

    client_br = n;

    for(int i = 0; i < n ; i++)
    {
        socket->waitForReadyRead();
        qDebug("Prosli smo waitForReadyRead()");
    }

}














