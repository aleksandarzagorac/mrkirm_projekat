#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    int client_br = 0;

    explicit Server(QObject *parent = 0);
    void client_recv_token();
    void client_send_token();
    void uspostava_veze_clienti();



signals:
    void sCekanje_poruke();
    void sPrihvatanje_poruke();
    void sSlanje_poruke();


public slots:
    //void cekanje_poruke();
    void prihvatanje_poruke();
   // void slanje_poruke();
    void readyRead();


private:
    QUdpSocket *socket;
};

#endif // SERVER_H
