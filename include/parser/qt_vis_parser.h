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
  // The file chosen by user
  Q_PROPERTY(QString chosen_file READ chosen_file WRITE setchosen_file NOTIFY
                 chosen_fileChanged);
  // The file contents
  Q_PROPERTY(QString file_contents READ file_contents WRITE setfile_contents
                 NOTIFY file_contentsChanged);
  QML_ELEMENT;

 public:
  // Constructor
  /* For QML! */
  explicit QtVISParseClass(QObject* parent = nullptr);
  QString chosen_file();
  QString file_contents();
  void setchosen_file(const QString file);
  void setfile_contents(const QString text);

  /* Invokable QML function*/
  Q_INVOKABLE QString UrlToFilenameWrapper(const QString text);

  /*
   * QML Singleton
   * param[in] engine: the QML engine
   * param[in] script_engine: the JavaScript engine
   */
  static QObject* SingletonGet(QQmlEngine* engine, QJSEngine* script_engine);

 private:
  /*
   * Get text of file and set that to prop_file_contents
   */
  void FileGetText();
  QString prop_chosen_file;
  QString prop_file_contents;

 signals:
  void chosen_fileChanged();
  void file_contentsChanged();
};
