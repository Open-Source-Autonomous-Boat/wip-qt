#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "widgets/base_widgets.h"
#pragma once

class InitialWindow : public WindowClass {
 public:
  InitialWindow(int argc, char** argv);
  ~InitialWindow();
  void SetupRenderer();
  int exec();
 signals:
 private:
  QQmlApplicationEngine* engine;
  QGuiApplication* app;
};
