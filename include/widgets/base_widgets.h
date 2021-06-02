#include <QObject>
#pragma once

class WindowClass: public QObject {
    Q_OBJECT;
public:
    explicit WindowClass() {};
    ~WindowClass() = default;
    virtual void _SetupWin() {};
    virtual void _SetupWidgets() {};
signals:
    void quit();
};

namespace win_utils {
void ExecClass(WindowClass* cls);

}
