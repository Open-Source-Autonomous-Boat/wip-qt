#include "widgets/base_widgets.h"
#include <QQuickItem>
#pragma once


class InitialWindow: public WindowClass {
public:
    InitialWindow(QObject* parent = nullptr);
    void _SetupWin();
    void _SetupWidgets();
signals:
    void quit();
};
