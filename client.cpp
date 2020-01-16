#include "client.h"
#include "myudp.h"
#include "token_str.h"

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    if (!socket->bind(QHostAddress("10.81.35.48"),1234)) {
        qDebug("Client bind failed.");
    } else {
        qDebug("Client bind done.");
    }
    connect(this, SIGNAL(send()), this , SLOT(send_token()));
    emit send();

}
void Client::send_token()
{
    QByteArray Data;

    qDebug("Slanje iz klijenta!");
    struct Token tok;
    Data.append(qUtf8Printable(tok.poruka));

    if (socket->writeDatagram(Data, QHostAddress("10.81.35.48"), 1233) <= 0) {
        qDebug("Did not send data");
    }



}

