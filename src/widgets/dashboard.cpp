#include <qobject.h>

#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QString>
#if defined(__unix__)
#include <unistd.h>
#endif
#if defined(_WINDOWS) || defined(__MINGW64__) || defined(__MINGW32__) || defined(_MSC_VER)
#include <windows.h>
#endif


#include "db.h"
#include "widgets/dashboard.h"
#include "utils/psuedo_uuid_gen.h"

DashBoard::DashBoard(QObject* parent) : QObject(parent) {
  db = new DBManager();
}
// Delete dangling pointers in class decontrusted 
DashBoard::~DashBoard() { delete db; }

QString DashBoard::ppid() {
  // Declare "Unknown" as fallback string
  this->prop_pid = QString("Unknown");
#if defined(__unix__)
  // Use POSIX function of *NIX
  this->prop_pid = QString::number(getpid());
#elif defined(_WINDOWS)
  // Use WIN32 if Windows :face_vomiting:
  this->prop_pid = QString::number(GetCurrentProcessId());
#endif
  // Return pid
  return this->prop_pid;
}

QString DashBoard::devname() {
  // Declare QString and get value from SQLite DB
  this->prop_dev_name = this->db->GetValue("dev_name");
  // Check if empty or non-existant
  if (this->prop_dev_name == "") {
	// Generate random string of numbers and set it as name
	this->db->SetValue("dev_name", psuedo_uuid::gen());
  }
  // Return device name
  return this->prop_dev_name;
}

void DashBoard::setdevname(const QString user_name) {
  // Checks if user_name is empty, and if so, do not change device name
  if (user_name == "") {
	// And return from function too <3
	return;
  }
  // Set new value of device name 
  this->prop_dev_name = user_name;
  // Set name in DB
  this->db->SetValue("dev_name", this->prop_dev_name);
  // Tell QML to update name too
  emit this->devnameChanged();
}

QObject* DashBoard::SingletonGet(QQmlEngine* engine, QJSEngine* script_engine) {
  // If used as singleton
  Q_UNUSED(engine);
  Q_UNUSED(script_engine);
  // Whatever
  return new DashBoard();
}
