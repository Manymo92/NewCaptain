#include "serveur.h"

serveur::serveur()
{
    int port=12345;

    if(!this->listen(QHostAddress::Any, port))
        {
            qDebug() << "impossible de lancer le serveur ";
        }
        else
        {
            qDebug() << "serveur sur ecoute" << port << "...";
        }
}

void serveur::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Message recu";
    so=new QTcpSocket();
    so->setSocketDescriptor(socketDescriptor);
    sD=socketDescriptor;
    connect(so, SIGNAL(readyRead()), this, SLOT(ecr()), Qt::DirectConnection);

}

void serveur::ecr()
{
    t = new Thread(sD, this);//creation du thread
    t->start();
}
