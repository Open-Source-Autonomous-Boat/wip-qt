#include "widgets/initial.h"

#include <qboxlayout.h>
#include <qframe.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <unistd.h>

#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <cstdio>
#include <iostream>
#include <string>

#include "base_widgets.h"

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
void InitialWidget::_setupWidgets() {
  /* Tab 1 */
  pid_t pid = getpid();
  auto Tab1 = new QWidget(this);
  auto *Tab1Grid = new QGridLayout(this);
  auto *Tab1Box1 = new QBoxLayout(QBoxLayout::LeftToRight);
  auto *Tab1Box2 = new QBoxLayout(QBoxLayout::LeftToRight);
  auto *Tab1Label1_0 = new QLabel(QString("Process ID: "));
  auto *Tab1Label1_1 = new QLabel(QString::number(pid), this);
  auto *Tab1Button1 = new QPushButton("Exit", this);
  Tab1Box1->addWidget(Tab1Label1_0);
  Tab1Box1->addWidget(Tab1Label1_1);
  Tab1Box2->addWidget(Tab1Button1);
  Tab1Grid->addLayout(Tab1Box1, 0, 0);
  Tab1Grid->addLayout(Tab1Box2, 1, 0);
  Tab1->setLayout(Tab1Grid);
  connect(Tab1Button1, &QPushButton::clicked, this, &InitialWidget::quit);
  /* Final Adjustments */
  this->addTab(Tab1, "Dashboard");
}

void InitialWidget::_setupWin() {
  this->setWindowTitle("OSAB WIP");
  this->resize(800, 600);
  this->setMinimumSize(200, 200);
  this->show();
}

void InitialWidget::quit() { this->close(); }
