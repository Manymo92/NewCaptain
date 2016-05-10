#include "thread.h"

Thread::Thread(qintptr ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}

void Thread::run()
{
    this->socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
       emit error(socket->error());
       return;
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(lecture()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    exec();
}

void Thread::Lecture()
{
    Data = socket->readAll();
}

void Thread::Ecriture()
{
    socket->write("ok");
    socket->waitForBytesWritten(30);
}
