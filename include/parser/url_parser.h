#include <QDir>
#include <QJSEngine>
#include <QString>
#include <QUrl>
#include <QtQml>
#pragma once

class QMLUrlParser : public QObject {
  Q_OBJECT;
  QML_ELEMENT;

 public:
  static QString UrlToString(const QString url);
  static QString UrlToFilename(const QString url);
};
