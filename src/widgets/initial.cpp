#include "widgets/initial.h"
#include "widgets/base_widgets.h"
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QGuiApplication>

InitialWindow::InitialWindow(QQuickItem* parent) {
        win_utils::ExecClass(this);
}

void InitialWindow::_SetupWin() {
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/initial.qml")));
    if (engine.rootObjects().isEmpty()) {
        QGuiApplication::exit(-1);
    }
    return;
}
void InitialWindow::_SetupWidgets() {}
