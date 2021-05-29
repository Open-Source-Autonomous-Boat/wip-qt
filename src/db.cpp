#include "db.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
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
