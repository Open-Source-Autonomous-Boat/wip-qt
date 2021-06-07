#include <qobject.h>
#include <qtmetamacros.h>
#include <QObject>
#include <QString>
#include <QtQml>
#include <QQmlEngine>
#include <QJSEngine>
#include "db.h"
#pragma once


class DashBoard: public QObject {
  Q_OBJECT;
  Q_PROPERTY(QString ppid READ ppid NOTIFY ppidChanged);
  Q_PROPERTY(QString devname READ devname WRITE setdevname NOTIFY devnameChanged)
  QML_ELEMENT;
public:
  explicit DashBoard(QObject* parent = nullptr);
  ~DashBoard();
  /* Read */
  QString ppid();
  QString devname();
  /* Write */
  void setdevname(const QString user_name);
  static QObject* SingletonGet(QQmlEngine* engine, QJSEngine* script_engine);
signals:
  void ppidChanged();
  void devnameChanged();
private:
  QString prop_pid;
  QString prop_dev_name;
  DBManager *db;
};
