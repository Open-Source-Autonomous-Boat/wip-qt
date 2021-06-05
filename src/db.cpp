#include "db.h"

#include <qfileinfo.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QtSql>
#include <cstdlib>
#include <memory>

DBManager::DBManager() {
#if defined(__WIN32) || defined(__MINGW64__) || defined(__MINGW32__)
  const QString home_dir = std::getenv("USERPROFILE");
  const QString cache_dir(QString("%1/AppData/Roaming/osab").arg(home_dir));
#elif defined(__unix__)
  const QString home_dir = std::getenv("HOME");
  const QString cache_dir(QString("%1/.cache/osab").arg(home_dir));
#else
  const QString cache_dir(QString("./"));
  qDebug() << "Unknown/Unhandled OS";
#endif
  const QString path(QString("%1/db.sql").arg(cache_dir));
  QDir db_dir(cache_dir);
  if (!db_dir.exists()) {
    db_dir.mkpath(cache_dir);
  }
  qDebug() << path;
  if (!QSqlDatabase::contains("main_db")) {
    this->db = QSqlDatabase::addDatabase("QSQLITE", "main_db");
    this->db.setDatabaseName(path);
  } else {
    this->db = QSqlDatabase::database("main_db");
  }
  this->db.open();
  this->query = new QSqlQuery(this->db);
  this->query->exec(
      "CREATE TABLE IF NOT EXISTS info(key TEXT PRIMARY KEY, value TEXT)");
  this->SetValue("dev_name", "The Sears Tower"); // DEBUG
}

DBManager::~DBManager() {
  delete this->query;
};

QString DBManager::GetValue(QString key) {
  this->query->prepare("SELECT value FROM info WHERE key=:key");
  this->query->bindValue(":key", key);
  if (!this->query->exec()) {
    qDebug() << this->query->lastError().text();
    return "";
  }
  if (this->query->next()) {
    return this->query->value(0).toString();
  } else {
    return "";
  }
}

void DBManager::SetValue(QString key, QString value) {
  this->query->prepare(
      "INSERT INTO info(key, value) VALUES(:key, :value)"
      "ON CONFLICT(key) DO UPDATE SET value=excluded.value");
  this->query->bindValue(":key", key);
  this->query->bindValue(":value", value);
  if (!this->query->exec()) {
    qDebug() << this->query->lastError().text();
  }
}

void DBManager::RemValue(QString key) {
  this->query->prepare("DELETE FROM info WHERE key=:key");
  this->query->bindValue(":key", key);
  if (!this->query->exec()) {
    qDebug() << this->query->lastError().text();
  }
}
