#include "main.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "initial.h"
#include "utils/apps.h"

int main(int argc, char *argv[]) {
  // Create application (duhh)
  InitialWindow win(argc, argv);
  // Return exit value
  return win.exec();
}
