#include <QString>
#include <QtSql>
#include <memory>
#pragma once

class DBManager {
 public:
  DBManager();
  ~DBManager();
  // Get stuff here!
  QString GetValue(QString key);
  void SetValue(QString key, QString value);
  void RemValue(QString key);

 private:
  QSqlQuery* query;
  QSqlDatabase db;
};
