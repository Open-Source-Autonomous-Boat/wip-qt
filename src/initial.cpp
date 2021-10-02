#include "initial.h"

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
  qmlRegisterSingletonType<DashBoard>("osab.xyz.DashBoard", 1, 0, "Dash",
                                      DashBoard::SingletonGet);
  // Same but for the VIS parser
  qmlRegisterSingletonType<QtVISParseClass>("osab.xyz.QtVIS", 1, 0, "QtVIS",
                                            QtVISParseClass::SingletonGet);
  // Same also, but for line number handling
  qmlRegisterSingletonType<LineNumberHandler>(
      "osab.xyz.QtVIS", 1, 0, "LineNumHandle", LineNumberHandler::SingletonGet);
  qmlRegisterType<MapDisplay>("osab.xyz.Map", 1, 0, "MapDisplay");
  qmlRegisterType<GridDisplay>("osab.xyz.Map", 1, 0, "GridDisplay");
}

void InitialWindow::SetupContext() {}

// Returns exit code ;-;
int InitialWindow::exec() { return this->app->exec(); }
