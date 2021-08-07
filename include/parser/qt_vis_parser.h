#include <VISParser.h>
#include <qobject.h>
#include <qtmetamacros.h>

#include <QApplication>
#include <QDebug>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QString>
#include <QtQml>

#pragma once

class QtVISParseClass : public QObject {
  Q_OBJECT;
  Q_PROPERTY(QString chosen_file READ chosen_file WRITE setchosen_file NOTIFY
                 chosen_fileChanged)
  QML_ELEMENT;

 public:
  explicit QtVISParseClass(QObject* parent = nullptr);
  QString chosen_file();
  void setchosen_file(const QString file);

  /* Invokable */
  Q_INVOKABLE QString UrlToFilenameWrapper(const QString text);

  static QObject* SingletonGet(QQmlEngine* engine, QJSEngine* script_engine);

 private:
  QString prop_chosen_file;

 signals:
  void chosen_fileChanged();
};
