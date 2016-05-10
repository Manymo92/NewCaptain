#ifndef SERVEUR_H
#define SERVEUR_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include "thread.h"



class serveur : public QTcpServer
{
    Q_OBJECT
public:
    serveur();
    void ecr();
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
     QTcpSocket *so;
     QByteArray Data;
     qintptr sD;
     Thread *t;
};

#endif // SERVEUR_H
