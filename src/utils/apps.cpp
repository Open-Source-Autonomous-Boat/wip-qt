#include "utils/apps.h"

#include <QGuiApplication>
#include <QApplication>
#include <QQuickStyle>
#include <memory>

QGuiApplication* app_utils::CreateApp(int argc, char** argv) {
  QGuiApplication::setOrganizationName("osab");
  QGuiApplication::setOrganizationDomain("osas.xyz");
  QGuiApplication::setApplicationName("WIP-qt");
  QGuiApplication::setApplicationDisplayName(
      "Watercraft Interface Program - QT");
  QGuiApplication::setApplicationVersion("0.0.1");
  auto* app = new QApplication(argc, argv);
  return app;
}
