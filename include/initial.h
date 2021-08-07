#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlTypeInfo>
#include <QQuickItem>
#include <QQuickView>
#include <memory>

#include "widgets/base_widgets.h"
#if defined(__unix__)
#include <unistd.h>
#elif defined(_WINDOWS)
#include <windows.h>
#endif

#include "geo/map.h"
#include "parser/qt_vis_parser.h"
#include "parser/line_numbers.h"
#include "utils/apps.h"
#include "widgets/base_widgets.h"
#include "widgets/dashboard.h"
#pragma once

class InitialWindow : public WindowClass {
  Q_OBJECT
 public:
  InitialWindow(int argc, char** argv);
  ~InitialWindow();
  void SetupRenderer();
  void SetupSignals();
  void SetupContext();
  int exec();

 private:
  QQmlApplicationEngine* engine;
  QGuiApplication* app;
};
