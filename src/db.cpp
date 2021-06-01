#include "db.h"

#include <qfileinfo.h>

#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QtSql>
#include <cstdlib>

DBManager::DBManager() {
  const QString home_dir = std::getenv("HOME");
#if defined(__WIN32) || defined(__MINGW64__) || defined(__MINGW32__)
  const QString cache_dir(QString("%1/AppData/Roaming/osab").arg(home_dir));
#elif defined(__LINUX)
  const QString cache_dir(QString("%1/.cache/osab").arg(home_dir));
#endif
  const QString path(QString("%1/db.sql").arg(cache_dir));
  QDir db_dir(cache_dir);
  if (!db_dir.exists()) {
    db_dir.mkpath(cache_dir);
  }
  QFile db_file(path);
  if (!db_file.exists()) {
    /*
     * If file doesn't exist, create empty file
     */
    db_file.open(QIODevice::WriteOnly);
    db_file.write(0, 0);
    db_file.close();
  }
  this->db = QSqlDatabase::addDatabase("QSQLITE");
  this->db.setDatabaseName(path);
  if (!this->db.open()) {
    qDebug() << this->db.lastError();
    return;
  }
  this->query.exec("SELECT count(*) FROM info");
  if (this->query.value(0).toInt() <= 0) {
    this->query.exec("CREATE TABLE info(id INTEGER PRIMARY KEY, key TEXT, value INTEGER)");
  }
}

DBManager::~DBManager() = default;

QString DBManager::GetValue(QString key) {
  this->query.prepare("SELECT (key) FROM info VALUES (:key)");
  this->query.bindValue(":key", key);
  if (!this->query.exec()) {
    return QString();
  }
  return this->query.value(0).toString();
}


QString DBManager::SetValue(QString key, QString value) {
  this->query.prepare("");
  if (!this->query.exec()) {
    return QString();
  }
  return this->query.value(0).toString();
}

void DBManager::GenPath() {
  return;
}
