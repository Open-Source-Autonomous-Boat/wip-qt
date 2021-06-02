#include "initial.h"

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <memory>

#include "utils/apps.h"
#include "widgets/base_widgets.h"

InitialWindow::InitialWindow(int argc, char** argv)
    : app(app_utils::CreateApp(argc, argv)) {
  this->SetupRenderer();
}
InitialWindow::~InitialWindow() {
  delete this->engine;
}

void InitialWindow::SetupRenderer() {
  this->engine = new QQmlApplicationEngine(this);
  this->engine->load(QUrl(QStringLiteral("qrc:/qml/initial.qml")));
  if (this->engine->rootObjects().isEmpty()) {
    QGuiApplication::exit(-1);
  }
}

int InitialWindow::exec() {
  return this->app->exec();
}
