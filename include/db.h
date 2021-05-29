#include <QtSql/QSql>
#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#pragma once


class DBManager {
public:
  DBManager(QString path);
  ~DBManager();
  // Get shit here!
  QString GetValue(QString key);
private:
  QSqlQuery query;
  QSqlDatabase db;
};
