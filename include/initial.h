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
 public:
  InitialWindow(int argc, char** argv);
  ~InitialWindow();
  void SetupRenderer();
  int exec();
 private:
  QQmlApplicationEngine* engine;
  QGuiApplication* app;
};
