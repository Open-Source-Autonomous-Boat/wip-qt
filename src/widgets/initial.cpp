#include "widgets/initial.h"

#include <qboxlayout.h>
#include <qbrush.h>
#include <qframe.h>
#include <qgridlayout.h>
#include <qlabel.h>
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

#include "base_widgets.h"

QPushButton* tab_1_widgets::ExitButton(InitialWidget* parent) {
  auto* new_widget = new QPushButton("Exit", parent);
  QObject::connect(new_widget, &QPushButton::clicked, parent,
                   &InitialWidget::quit);
  return new_widget;
}

QGridLayout* tab_1_widgets::Grid(InitialWidget* parent) {
  auto* grid = new QGridLayout(parent);
  auto* main_dash = new QBoxLayout(QBoxLayout::TopToBottom);
  auto* bottom_bar = new QBoxLayout(QBoxLayout::LeftToRight);
  bottom_bar->addWidget(tab_1_widgets::ExitButton(parent));
  main_dash->addLayout(tab_1_widgets::dash_board::DeviceName(parent));
  grid->addLayout(main_dash, 0, 0);
  grid->addLayout(bottom_bar, 1, 0);
  return grid;
}


QBoxLayout *tab_1_widgets::dash_board::DeviceName(InitialWidget* parent) {
  auto box = new QBoxLayout(QBoxLayout::LeftToRight);
  auto label = new QLabel("Device Name");
  auto value = new QLabel("Unkown");
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
  /* Tab 2 */
  /* Final Adjustments */
  this->setLayout(tab_1_widgets::Grid(this));
}

void InitialWidget::_SetupWin() {
  this->setWindowTitle("OSAB WIP");
  this->setMinimumSize(200, 200);
  this->show();
}

void InitialWidget::quit() { this->close(); }
