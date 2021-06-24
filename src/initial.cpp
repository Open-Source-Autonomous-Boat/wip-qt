#include "initial.h"

#include <qnamespace.h>
#include <qqml.h>
#include <qsgnode.h>
#include <qsgrendererinterface.h>

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlTypeInfo>
#include <QQuickItem>
#include <QQuickView>
#include <memory>
#if defined(__unix__)
#include <unistd.h>
#elif defined(_WINDOWS)
#include <windows.h>
#endif

#include "geo/map.h"
#include "utils/apps.h"
#include "widgets/base_widgets.h"
#include "widgets/dashboard.h"

InitialWindow::InitialWindow(int argc, char** argv)
    : app(app_utils::CreateApp(argc, argv)) {
  this->SetupSignals();
  this->SetupRenderer();
}
InitialWindow::~InitialWindow() { delete this->engine; }

void InitialWindow::SetupRenderer() {
  // Initializes QML engine for program :D
  this->engine = new QQmlApplicationEngine(this);
  // Add path that engine can import from
  this->engine->addImportPath("qrc:/qml");
  // Incase contexts need to be declared
  this->SetupContext();
  // Loads index QML file
  this->engine->load(QUrl(QStringLiteral("qrc:/qml/initial.qml")));
  if (this->engine->rootObjects().isEmpty()) {  // Check if empty
    QGuiApplication::exit(-1);                  // If empty exit UwU
  }
}

void InitialWindow::SetupSignals() {
  // So I can use Dash without importing from QML <3
  QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGLRhi);
  qmlRegisterSingletonType<DashBoard>("osab.xyz.DashBoard", 1, 0, "Dash",
                                      DashBoard::SingletonGet);
  qmlRegisterType<MapDisplay>("osab.xyz.Map", 1, 0, "MapDisplay");
}

void InitialWindow::SetupContext() {
}

// Returns exit code ;-;
int InitialWindow::exec() { return this->app->exec(); }
