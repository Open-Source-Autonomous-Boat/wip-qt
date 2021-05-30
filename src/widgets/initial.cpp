#include "widgets/initial.h"

#include <qboxlayout.h>
#include <qbrush.h>
#include <qframe.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <unistd.h>

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <vector>

#include "base_widgets.h"

QPushButton* tab_1_widgets::ExitButton(InitialWidget* parent) {
  auto* new_widget = new QPushButton("Exit", parent);
  QObject::connect(new_widget, &QPushButton::clicked, parent,
                   &InitialWidget::quit);
  return new_widget;
}

QPushButton* tab_1_widgets::SettingsButton(InitialWidget* parent) {
  auto* new_widget = new QPushButton("Settings", parent);
  QObject::connect(new_widget, &QPushButton::clicked, parent,
                   &InitialWidget::quit);
  return new_widget;
}

QGridLayout* tab_1_widgets::Grid(InitialWidget* parent) {
  std::vector<QString> list_data = {"Device Name", "Identification Number",
                                    "Uptime", "Current Coordinates", "Status"};
  auto* grid = new QGridLayout(parent);
  auto* main_dash = new QBoxLayout(QBoxLayout::TopToBottom);
  auto* button_bar = new QBoxLayout(QBoxLayout::TopToBottom);
  auto* bottom_bar = new QBoxLayout(QBoxLayout::LeftToRight);
  bottom_bar->addWidget(tab_1_widgets::ExitButton(parent));
  bottom_bar->addWidget(tab_1_widgets::SettingsButton(parent));
  main_dash->addStretch();
  button_bar->addStretch();
  for (auto& data : list_data) {
    main_dash->addLayout(tab_1_widgets::dash_board::NameLabel(parent, data));
  }
  grid->addLayout(main_dash, 1, 0);
  grid->addLayout(button_bar, 0, 0);
  grid->addLayout(bottom_bar, 2, 0);
  return grid;
}

QBoxLayout* tab_1_widgets::dash_board::NameLabel(InitialWidget* parent,
                                                 QString key) {
  auto box = new QBoxLayout(QBoxLayout::LeftToRight);
  auto label = new QLabel(key);
  auto value = new QLabel("Unknown");
  value->setTextInteractionFlags(Qt::TextSelectableByMouse |
                                 Qt::TextSelectableByKeyboard);
  box->setSizeConstraint(QLayout::SetMinimumSize);
  box->addWidget(label);
  box->addWidget(value);
  return box;
}

/*
 * Structure of tabs:
 * - Widget
 * - Layouts
 * - Widgets
 * - Widgets append to Layouts
 * - Layouts set to Widget
 * - Widget connections
 * - Widget settings
 * - Layout settings
 */
void InitialWidget::_SetupWidgets() {
  /* Tab 1 */
  QWidget *Tab1 = new QWidget(this);
  Tab1->setLayout(tab_1_widgets::Grid(this));
  /* Tab 2 */
  /* Final Adjustments */
  this->addTab(Tab1, "Dashboard");
}

void InitialWidget::_SetupWin() {
  this->setWindowTitle("OSAB WIP");
  this->setMinimumSize(600, 400);
  this->show();
}

void InitialWidget::quit() { this->close(); }
