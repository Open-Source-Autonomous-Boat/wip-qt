#include "db.h"

#include <qfileinfo.h>

#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <cstdlib>

DBManager::DBManager(QString path) {
  QFile db_file(path);
  if (!db_file.exists()) {
    /*
     * If file doesn't exist, create empty file
     */
    db_file.open(QIODevice::WriteOnly);
    db_file.write(0, 0);
    db_file.close();
  }
  this->db = QSqlDatabase::addDatabase("SQLITE");
  this->db.setDatabaseName(path);
  if (!this->db.open()) {
    qDebug() << "Failed to open Database";
  }
  this->query.exec("SELECT count(*) FROM table");
  if (this->query.value(0).toInt() <= 0) {
    this->query.exec("CREATE TABLE info(key value)");
  }
}

DBManager::~DBManager() { std::exit(0); }

QString DBManager::GetValue(QString key, QString catagory) {
  this->query.prepare("SELECT (key) FROM (catagory) VALUES (:key) (:catagory)");
  this->query.bindValue(":key", key);
  this->query.bindValue(":catagory", catagory);
  if (!this->query.exec()) {
    return QString();
  }
  return this->query.value(0).toString();
}
