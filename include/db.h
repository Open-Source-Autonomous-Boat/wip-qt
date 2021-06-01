#include <QString>
#include <QtSql>
#pragma once

class DBManager {
 public:
  DBManager();
  ~DBManager();
  // Get stuff here!
  QString GetValue(QString key);
  QString SetValue(QString key, QString value);
  void CloseDB();
 private:
  void GenPath();
  QSqlQuery query;
  QSqlDatabase db;
};
