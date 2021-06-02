#include "widgets/base_widgets.h"
#include <QQuickItem>

void win_utils::ExecClass(WindowClass* cls) {
    cls->_SetupWin();
    cls->_SetupWidgets();
    return;
}
