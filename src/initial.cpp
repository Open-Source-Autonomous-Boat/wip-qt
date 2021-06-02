#include "initial.h"
#include "widgets/base_widgets.h"
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QDebug>

InitialWindow::InitialWindow(QObject* parent) {
        this->_SetupWin();
}

void InitialWindow::_SetupWin() {
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");
    engine.load(QUrl(QStringLiteral("qrc:/qml/initial.qml")));
    if (engine.rootObjects().isEmpty()) {
        QGuiApplication::exit(-1);
    }
    return;
}
void InitialWindow::_SetupWidgets() {}
