#include <QObject>
#pragma once

class WindowClass: public QObject {
    Q_OBJECT;
public:
    WindowClass() = default;
    ~WindowClass() = default;
    void _SetupWin() {};
    void _SetupWidgets() {};
signals:
    void quit();
};
