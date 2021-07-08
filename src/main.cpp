#include "main.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlDebuggingEnabler>

#include "initial.h"
#include "utils/apps.h"

int main(int argc, char *argv[]) {
  // Enable qml debugging
#if DEBUG
  QQmlDebuggingEnabler enabler;
#endif
  // Create application (duhh)
  InitialWindow win(argc, argv);
  // Return exit value
  return win.exec();
}
