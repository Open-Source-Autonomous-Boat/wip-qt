#include <qfileinfo.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QtSql>
#include <iostream>
#if defined(_WINDOWS) || defined(__MINGW64__) || defined(__MINGW32__) || \
    defined(_MSC_VER)
#include <windows.h>
#endif
#include <cstdlib>
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
