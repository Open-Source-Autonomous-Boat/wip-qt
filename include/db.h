#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

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
