#include "widgets/base_widgets.h"
#include <QQuickItem>
#pragma once


class InitialWindow: public WindowClass {
public:
    InitialWindow(QQuickItem* parent = nullptr);
    void _SetupWin() override;
    void _SetupWidgets() override;
signals:
    void quit();
};
