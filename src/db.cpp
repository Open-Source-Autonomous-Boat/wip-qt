#include "db.h"

#include <qfileinfo.h>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QtSql>
#include <cstdlib>
#include <memory>

DBManager::DBManager() {
  const QString home_dir = std::getenv("HOME");
#if defined(__WIN32__) || defined(__MINGW64__) || defined(__MINGW32__)
  const QString cache_dir(QString("%1/AppData/Roaming/osab").arg(home_dir));
#elif defined(__unix__)
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
  if (!QSqlDatabase::contains("main_db")) {
    this->db = QSqlDatabase::addDatabase("QSQLITE", "main_db");
  } else {
    this->db = QSqlDatabase::database("main_db");
  }
  this->query = std::make_unique<QSqlQuery>(QSqlQuery(this->db));
  this->db.open();
  if (!this->query->exec("SELECT count(*) from info")) {
    qDebug() << this->query->exec(
        "CREATE TABLE info(id INTEGER PRIMARY KEY, key TEXT, value TEXT)");
	qDebug() << this->query->lastError();
    return;
  }
}

DBManager::~DBManager() = default;

QString DBManager::GetValue(QString key) {
  this->query->prepare("SELECT value FROM info WHERE key=(key) VALUES (:key)");
  this->query->bindValue(":key", key);
  if (!this->query->exec()) {
    return QString("Unknown");
  }
  return this->query->value(0).toString();
}

QString DBManager::SetValue(QString key, QString value) {
  this->query->prepare(
      "UPDATE info SET value=(value) WHERE key=(key) VALUES (:key) (:value)");
  this->query->bindValue(":key", key);
  this->query->bindValue(":value", value);
  if (!this->query->exec()) {
    return QString("");
  }
  return this->query->value(0).toString();
}

void DBManager::GenPath() { return; }
