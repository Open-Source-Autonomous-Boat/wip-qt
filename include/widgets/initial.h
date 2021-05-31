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

namespace general_widgets {
QBoxLayout* NameLabel(InitialWidget* parent, QString key);
QBoxLayout* EditLabel(InitialWidget* parent, QString key);
QPushButton* ExitButton(InitialWidget* parent);
}  // namespace general_widgets

namespace tab_1_widgets {  // Dashboard
// Widgets
QPushButton* SettingsButton(InitialWidget* parent);
// Layouts
QGridLayout* Grid(InitialWidget* parent);
}  // namespace tab_1_widgets

namespace tab_2_widgets {  // Device Info
                           // Widgets
QPushButton* Apply(InitialWidget* parent);
// Layouts
QGridLayout* Grid(InitialWidget* parent);
}  // namespace tab_2_widgets
