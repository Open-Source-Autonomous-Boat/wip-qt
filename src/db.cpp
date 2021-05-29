#include "db.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <cstdlib>
#include <QString>
#include <QDebug>


DBManager::DBManager(QString path) {
  this->db = QSqlDatabase::addDatabase("SQLITE");
  this->db.setDatabaseName(path);
  if (!this->db.open()) {
    qDebug() << "Failed to open Database";
  }
}

DBManager::~DBManager() {
  std::exit(0);
}
