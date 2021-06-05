#include "widgets/dashboard.h"
#include "db.h"

#include <qobject.h>
#if defined(__unix__)
#include <unistd.h>
#elif defined(__WIN32)
#include <windows.h>
#endif

DashBoard::DashBoard(QObject* parent) : QObject(parent) {
  db = new DBManager();
}
DashBoard::~DashBoard() {
  delete db;
}

QString DashBoard::GetPropPid() {
  this->prop_pid = QString("Unknown");
#if defined(__unix__)
  this->prop_pid = QString::number(getpid());
#elif defined(__WIN32)
  this->prop_pid = QString::number(GetCurrentProcessId());
#endif
  return this->prop_pid;
}

QString DashBoard::GetPropDevName() {
  this->prop_dev_name = this->db->GetValue("dev_name");
  if (this->prop_dev_name == "") {
    this->prop_dev_name = "Unknown";
  }
  return this->prop_dev_name;
}

void DashBoard::SetPropDevName(const QString user_name) {
  this->prop_dev_name = user_name;
  this->db->SetValue("dev_name", this->prop_dev_name);
  emit this->NotifyPropDevName();
}
