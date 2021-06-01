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
#include <qtabwidget.h>
#include <qwidget.h>
#include <unistd.h>

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <algorithm>
#include <memory>
#include <vector>

#include "base_widgets.h"
#include "db.h"

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
  std::unique_ptr<DBManager>db(new DBManager());
  main_dash->addStretch();
  button_bar->addStretch();
  for (auto& data : list_data) {
    main_dash->addLayout(general_widgets::NameLabel(parent, data, db.get()));
  }
  grid->addLayout(main_dash, 1, 0);
  grid->addLayout(button_bar, 0, 0);
  return grid;
}

QBoxLayout* general_widgets::NameLabel(InitialWidget* parent, QString key,
                                       DBManager* db) {
  if (!db) {
    std::unique_ptr<DBManager>db(new DBManager());
  }
  auto* box = new QBoxLayout(QBoxLayout::LeftToRight);
  auto* label = new QLabel(key);
  // auto* value = new QLabel(db->GetValue(key));
  auto* value = new QLabel("Unknown");
  value->setTextInteractionFlags(Qt::TextSelectableByMouse |
                                 Qt::TextSelectableByKeyboard);
  box->setSizeConstraint(QLayout::SetMinimumSize);
  box->addWidget(label);
  box->addWidget(value);
  return box;
}

QBoxLayout* general_widgets::EditLabel(InitialWidget* parent, QString key,
                                       DBManager* db) {
  if (!db) {
        std::unique_ptr<DBManager>db(new DBManager());
  }
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
  std::vector<QString> value_list = {"Device Information", "Nickname"};
  auto* info_bar = new QBoxLayout(QBoxLayout::TopToBottom);
  auto* grid = new QGridLayout();
  std::unique_ptr<DBManager>db(new DBManager());
  for (auto& i : value_list) {
    info_bar->addLayout(general_widgets::EditLabel(parent, i, db.get()));
  }
  grid->addLayout(info_bar, 0, 0);
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
  auto* bar = new QBoxLayout(QBoxLayout::LeftToRight);
  auto* tabs = new QTabWidget(this);
  auto* main_layout = new QBoxLayout(QBoxLayout::TopToBottom);
  bar->addWidget(general_widgets::ExitButton(this));
  bar->addWidget(tab_1_widgets::SettingsButton(this));
  tabs->addTab(tab_1, "Dashboard");
  tabs->addTab(tab_2, "Device Information");
  main_layout->addWidget(tabs);
  main_layout->addLayout(bar);
  this->setLayout(main_layout);
}

void InitialWidget::_SetupWin() {
  this->setWindowTitle("OSAB WIP");
  this->setMinimumSize(600, 400);
  this->show();
}

void InitialWidget::quit() { this->close(); }
