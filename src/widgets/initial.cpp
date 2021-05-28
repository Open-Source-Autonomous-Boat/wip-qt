#include "widgets/initial.h"

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "base_widgets.h"

void InitialWidget::_setupWidgets() {
  QWidget *lol = new QWidget();
  QPushButton *but = new QPushButton("K lol", lol);
  QPushButton *but1 = new QPushButton("Ya got bamboozeld", lol);
  QGridLayout *grid = new QGridLayout(lol);
  grid->addWidget(but, 0, 0);
  grid->addWidget(but1, 1, 0);
  lol->setLayout(grid);
  connect(but, &QPushButton::clicked, this, &InitialWidget::quit);
  this->addTab(lol, "1st Tab");
}

void InitialWidget::_setupWin() {
  this->setWindowTitle("OSAB WIP");
  this->resize(800, 600);
  this->show();
}

void InitialWidget::quit() { this->close(); }
