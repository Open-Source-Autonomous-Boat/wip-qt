#include "initial.h"

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>
#include <QQmlTypeInfo>
#include <memory>
#if defined(__unix__)
#include <unistd.h>
#elif defined(__WIN32)
#include <windows.h>
#endif

#include "utils/apps.h"
#include "widgets/base_widgets.h"
#include "widgets/dashboard.h"

InitialWindow::InitialWindow(int argc, char** argv)
    : app(app_utils::CreateApp(argc, argv)) {
  qmlRegisterType<DashBoard>("osab.xyz.DashBoard",1,0, "Dash");
  this->SetupRenderer();
  this->SetupSignals();
}
InitialWindow::~InitialWindow() {
  delete this->engine;
}

void InitialWindow::SetupRenderer() {
  this->engine = new QQmlApplicationEngine(this);
  this->engine->addImportPath("qrc:/qml");
  this->engine->load(QUrl(QStringLiteral("qrc:/qml/initial.qml")));
  if (this->engine->rootObjects().isEmpty()) {
    QGuiApplication::exit(-1);
  }
}

void InitialWindow::SetupSignals() {
        /* Useless */
}

int InitialWindow::exec() {
  return this->app->exec();
}


