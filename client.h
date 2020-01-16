#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

signals:
    void send();
    void cekanje();
    void primanje();


public slots:
    void send_token();

private:
    QUdpSocket *socket;

};

#endif // CLIENT_H
