#include "client.h"
#include "myudp.h"

Client::Client(QObject *parent) : QObject(parent)
{

}
void Client::send_token()
{
    MyUDP client;
    //qDebug("Da li zelite da posaljete poruku?");
    client.SayHello();
}
