#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>

#include <QTabWidget>

#include "base_widgets.h"

#pragma once

class InitialWidget : public TabWindowClass {
 public:
  InitialWidget() {
    this->_SetupWidgets();
    this->_SetupWin();
  }
 public slots:
  void quit();

 protected:
  void _SetupWidgets() override;
  void _SetupWin() override;
};

namespace tab_1_widgets {
// Widgets
QPushButton* ExitButton(InitialWidget* parent);
namespace dash_board {
  QBoxLayout* NameLabel(InitialWidget* parent, QString key);
}
// Layouts
QGridLayout* Grid(InitialWidget* parent);
}  // namespace tab_1_widgets
