#include <QApplication>
#include <QDebug>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QString>
#include <QtQml>
#include <fstream>
#include <string>
#pragma once

class LineNumberHandler : public QObject {
  Q_OBJECT;
  Q_PROPERTY(int lines_count READ lines_count WRITE setlines_count NOTIFY
                 lines_countChanged);
  QML_ELEMENT;

 public:
  LineNumberHandler();
  Q_INVOKABLE int CalculateLineWidth(int a_max_line);
  Q_INVOKABLE int CalculateFileLines(const QString a_path);
  static QObject* SingletonGet(QQmlEngine* a_engine,
                               QJSEngine* a_script_engine);
  /* Properties */
  int lines_count();
  void setlines_count(const int a_lines);

 private:
  void ResetBar();
  int prop_lines_count;
 signals:
  void lines_countChanged();
};
