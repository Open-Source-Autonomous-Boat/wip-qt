#include <qobject.h>
#include <qtmetamacros.h>
#include <QObject>
#include <QString>
#include <QtQml>
#include "db.h"
#pragma once


class DashBoard: public QObject {
  Q_OBJECT;
  Q_PROPERTY(QString GetPropPid READ GetPropPid NOTIFY NotifyPropPid);
  Q_PROPERTY(QString GetPropDevName
             READ GetPropDevName WRITE SetPropDevName  NOTIFY NotifyPropDevName)
  QML_ELEMENT;
public:
  explicit DashBoard(QObject* parent = nullptr);
  ~DashBoard();
  /* Read */
  QString GetPropPid();
  QString GetPropDevName();
  /* Write */
  void SetPropDevName(const QString user_name);
signals:
  void NotifyPropPid();
  void NotifyPropDevName();
private:
  QString prop_pid;
  QString prop_dev_name;
  DBManager *db;
};
