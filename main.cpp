#include <QCoreApplication>

#include "server.h"
#include "client.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qDebug("Ovaj terminal je za: \n 1. server \n 2. client \n unesi broj ");

    QTextStream qtin(stdin);
    QString line = qtin.readLine();


    if(line == '1')
    {
         Server server;
    }else
    {
         Client client;
    }


   // QTextStream qtin(stdin);
   // QString line = qtin.readLine();
   // qDebug("%s",qUtf8Printable(line));

    return a.exec();
}
