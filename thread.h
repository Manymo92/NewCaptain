#ifndef THREAD_H
#define THREAD_H
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QThread>


class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(qintptr ID, QObject *parent = 0);
    void run();
private:
    QByteArray Data;
    QTcpSocket *socket;
    qintptr socketDescriptor;
signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void Lecture();
    void Ecriture();
};

#endif // THREAD_H
