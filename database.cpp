#include "database.h"
#include <iostream>
#define q2c(string) string.toStdString()


database::database()
{
    db = new QSqlDatabase();

    db->addDatabase("QMYSQL");
    db->setHostName("localhost");
    db->setUserName("Demi");
    db->setPassword("");
    db->setDatabaseName("securite");
    db->open();

}

database::~database()
{
    db->close();
}

void database::verification()
{
    if(db->open())
    {
        std::cout << "Vous êtes maintenant connecté à " << q2c(db->hostName()) << std::endl;
        //QMessageBox::information(this,"You win !", "Connexion réussi");
        db->close();
    }
    else
    {
        std::cout << "La connexion a échouée, désolé :(" << std::endl << q2c(db->lastError().text()) << std::endl;
        //QMessageBox::critical(this,"Défaite", "Connexion Echoué");
        ::exit(1);
    }
}
