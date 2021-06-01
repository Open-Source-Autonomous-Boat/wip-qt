#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>

#include <QTabWidget>

#include "base_widgets.h"
#include "db.h"

#pragma once

class InitialWidget : public WindowClass {
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
QBoxLayout* NameLabel(InitialWidget* parent, QString key,
                      DBManager* db = nullptr);
QBoxLayout* EditLabel(InitialWidget* parent, QString key,
                      DBManager* db = nullptr);
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
