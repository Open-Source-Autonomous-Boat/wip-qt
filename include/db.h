#include <QString>
#include <QtSql>
#pragma once

class DBManager {
 public:
  DBManager();
  ~DBManager();
  // Get shit here!
  QString GetValue(QString key);
  QString SetValue(QString key, QString value);
 private:
  void GenPath();
  QSqlQuery query;
  QSqlDatabase db;
};
