#include <QDir>
#include <QString>
#include <QtQml>
#include <QUrl>
#include <QJSEngine>
#pragma once

class QMLUrlParser: public QObject {
  Q_OBJECT;
  QML_ELEMENT;
  static QString UrlToString(const QString url);
};
