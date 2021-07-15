#include "parser/qt_vis_parser.h"

QtVISParseClass::QtVISParseClass(QObject* parent) : QObject(parent) {}

QString QtVISParseClass::chosenfile() { return this->prop_chosen_file; }

void QtVISParseClass::setchosenfile(const QString file) {
  this->prop_chosen_file = file;
  emit this->chosenfileChanged();
}

QObject* QtVISParseClass::SingletonGet(QQmlEngine* engine,
                                       QJSEngine* script_engine) {
  Q_UNUSED(engine);
  Q_UNUSED(script_engine);
  return new QtVISParseClass();
}
