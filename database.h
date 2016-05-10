#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>

class database
{
public:
    database();
    void verification();
    ~database();
private:
    QSqlDatabase *db;
};
#endif // DATABASE_H
