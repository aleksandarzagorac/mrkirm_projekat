#include <QCoreApplication>

#include "server.h"
#include "client.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   // qDebug("%s", qUtf8Printable(t.str));*/

    Server s;
    Client client;

    QTextStream qtin(stdin);
    QString line = qtin.readLine();
    qDebug("%s",qUtf8Printable(line));


    client.send_token();
    s.client_recv_token();



    return a.exec();
}
