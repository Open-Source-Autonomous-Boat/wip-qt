#include "base_widgets.h"
#include <QTabWidget>


class InitialWidget: public TabWindowClass {
public:
        InitialWidget(): TabWindowClass() {
                this->_setupWidgets();
                this->_setupWin();
        }
public slots:
        void quit();
private:
        void _setupWidgets() override;
        void _setupWin() override;
};
