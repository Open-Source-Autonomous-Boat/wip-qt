#include "widgets/initial.h"

#include <qboxlayout.h>
#include <qbrush.h>
#include <qframe.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <unistd.h>

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <vector>

#include "base_widgets.h"

QPushButton* general_widgets::ExitButton(InitialWidget* parent) {
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
  bottom_bar->addWidget(general_widgets::ExitButton(parent));
  bottom_bar->addWidget(tab_1_widgets::SettingsButton(parent));
  main_dash->addStretch();
  button_bar->addStretch();
  for (auto& data : list_data) {
    main_dash->addLayout(general_widgets::NameLabel(parent, data));
  }
  grid->addLayout(main_dash, 1, 0);
  grid->addLayout(button_bar, 0, 0);
  grid->addLayout(bottom_bar, 2, 0);
  return grid;
}

QBoxLayout* general_widgets::NameLabel(InitialWidget* parent, QString key) {
  auto* box = new QBoxLayout(QBoxLayout::LeftToRight);
  auto* label = new QLabel(key);
  auto* value = new QLabel("Unknown");
  value->setTextInteractionFlags(Qt::TextSelectableByMouse |
                                 Qt::TextSelectableByKeyboard);
  box->setSizeConstraint(QLayout::SetMinimumSize);
  box->addWidget(label);
  box->addWidget(value);
  return box;
}

QBoxLayout* general_widgets::EditLabel(InitialWidget* parent, QString key) {
  auto* box = new QBoxLayout(QBoxLayout::LeftToRight);
  auto* label = new QLabel(key);
  auto* value = new QLineEdit(parent);
  value->setPlaceholderText("Unknown");
  box->setSizeConstraint(QLayout::SetMinimumSize);
  box->addWidget(label);
  box->addWidget(value);
  return box;
}

QGridLayout* tab_2_widgets::Grid(InitialWidget* parent) {
  auto* grid = new QGridLayout();
  grid->addLayout(general_widgets::EditLabel(parent, "Device Information"), 0,
                  0);
  grid->addWidget(tab_2_widgets::Apply(parent), 1, 0);
  return grid;
}

QPushButton* tab_2_widgets::Apply(InitialWidget* parent) {
  auto* button = new QPushButton("Apply", parent);
  return button;
}

/*
 * Structure of tabs:
 * - Widget
 * - Layouts
 * - Widgets
 * - Widgets  append to Layouts
 * - Layouts set to Widget
 * - Widget connections
 * - Widget settings
 * - Layout settings
 */
void InitialWidget::_SetupWidgets() {
  /* Tab 1 */
  QWidget* tab_1 = new QWidget(this);
  tab_1->setLayout(tab_1_widgets::Grid(this));
  /* Tab 2 */
  QWidget* tab_2 = new QWidget(this);
  tab_2->setLayout(tab_2_widgets::Grid(this));
  /* Final Adjustments */
  this->addTab(tab_1, "Dashboard");
  this->addTab(tab_2, "Device Information");
}

void InitialWidget::_SetupWin() {
  this->setWindowTitle("OSAB WIP");
  this->setMinimumSize(600, 400);
  this->show();
}

void InitialWidget::quit() { this->close(); }
