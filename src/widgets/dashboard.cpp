#include <QObject>
#include <QString>
#include <QQmlEngine>
#include <QJSEngine>

#include <qobject.h>
#if defined(__unix__)
#include <unistd.h>
#elif defined(__WIN32)
#include <windows.h>
#endif

#include "widgets/dashboard.h"
#include "db.h"

DashBoard::DashBoard(QObject* parent) : QObject(parent) {
  db = new DBManager();
}
DashBoard::~DashBoard() {
  delete db;
}

QString DashBoard::ppid() {
  this->prop_pid = QString("Unknown");
#if defined(__unix__)
  this->prop_pid = QString::number(getpid());
#elif defined(__WIN32)
  this->prop_pid = QString::number(GetCurrentProcessId());
#endif
  return this->prop_pid;
}

QString DashBoard::devname() {
  this->prop_dev_name = this->db->GetValue("dev_name");
  return (this->prop_dev_name != "") ?
        this->prop_dev_name : "Unknown";
}

void DashBoard::setdevname(const QString user_name) {
  this->prop_dev_name = user_name;
  this->db->SetValue("dev_name", this->prop_dev_name);
  emit this->devnameChanged();
}

QObject * DashBoard::SingletonGet(QQmlEngine* engine, QJSEngine* script_engine) {
  Q_UNUSED(engine);
  Q_UNUSED(script_engine);
  return new DashBoard();
}
