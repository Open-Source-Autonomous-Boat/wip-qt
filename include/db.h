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
  QString SetValue(QString key, QString value);
 private:
  void GenPath();
  std::unique_ptr<QSqlQuery>query;
  QSqlDatabase db;
};
