#include <qqml.h>
#include <qtmetamacros.h>

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "widgets/base_widgets.h"
#pragma once

class InitialWindow : public WindowClass {
  Q_OBJECT
  Q_PROPERTY(QString PropGetPID READ PropGetPID NOTIFY PropChangePID)
  QML_ELEMENT
 public:
  InitialWindow(int argc, char** argv);
  ~InitialWindow();
  void SetupRenderer();
  int exec();
  /* Properties */
  QString PropGetPID();
 signals:
  void PropChangePID();
 private:
  QQmlApplicationEngine* engine;
  QGuiApplication* app;
  QString prop_pid;
};
