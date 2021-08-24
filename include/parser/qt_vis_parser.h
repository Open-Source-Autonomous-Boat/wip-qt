#include <VISParser.h>
#include <qobject.h>
#include <qtmetamacros.h>

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QString>
#include <QTextDocument>
#include <QTextStream>
#include <QtQml>

#pragma once

class QtVISParseClass : public QObject {
  Q_OBJECT;
  Q_PROPERTY(QString chosen_file READ chosen_file WRITE setchosen_file NOTIFY
                 chosen_fileChanged);
  Q_PROPERTY(QString file_contents READ file_contents WRITE setfile_contents
                 NOTIFY file_contentsChanged);
  QML_ELEMENT;

 public:
  explicit QtVISParseClass(QObject* parent = nullptr);
  QString chosen_file();
  QString file_contents();
  void setchosen_file(const QString file);
  void setfile_contents(const QString text);

  /* Invokable */
  Q_INVOKABLE QString UrlToFilenameWrapper(const QString text);

  static QObject* SingletonGet(QQmlEngine* engine, QJSEngine* script_engine);

 private:
  void FileGetText();
  QString prop_chosen_file = "CMakeCache.txt";
  QString prop_file_contents;

 signals:
  void chosen_fileChanged();
  void file_contentsChanged();
};
