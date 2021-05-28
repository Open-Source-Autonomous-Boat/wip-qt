#include "widgets/initial.h"

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "base_widgets.h"

void InitialWidget::_setupWidgets() {}

void InitialWidget::_setupWin() {
  this->setWindowTitle("OSAB WIP");
  this->resize(800, 600);
  this->show();
}

void InitialWidget::quit() { this->close(); }
