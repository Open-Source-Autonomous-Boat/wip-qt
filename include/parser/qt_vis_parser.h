#include <VISParser.h>
#include <qobject.h>
#include <qtmetamacros.h>

#include <QDebug>
#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QtQml>

#pragma once

class QtVISParseClass : public QObject {
  Q_OBJECT;
  Q_PROPERTY(QString chosenfile READ chosenfile WRITE setchosenfile NOTIFY
                 chosenfileChanged)
  QML_ELEMENT;

 public:
  explicit QtVISParseClass(QObject* parent = nullptr);
  QString chosenfile();
  void setchosenfile(const QString file);

 private:
  QString prop_chosen_file;

 signals:
  void chosenfileChanged();
};
