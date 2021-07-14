#include "parser/qt_vis_parser.h"


QtVISParseClass::QtVISParseClass(QObject* parent) : QObject(parent) {}

QString QtVISParseClass::chosenfile() { return this->prop_chosen_file; }

void QtVISParseClass::setchosenfile(const QString file) {
  this->prop_chosen_file = file;
  emit this->chosenfileChanged();
}
