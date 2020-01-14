#include <QCoreApplication>
#include "myudp.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyUDP server;
    MyUDP client;


    client.SayHello();
   // struct Token t;
   // qDebug("%s", qUtf8Printable(t.str));


    return a.exec();
}
