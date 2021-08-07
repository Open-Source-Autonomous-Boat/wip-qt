#include "parser/qt_vis_parser.h"

#include "parser/url_parser.h"

QtVISParseClass::QtVISParseClass(QObject* parent) : QObject(parent) {}

QString QtVISParseClass::chosen_file() { return this->prop_chosen_file; }

void QtVISParseClass::setchosen_file(const QString file) {
  this->prop_chosen_file = file;
  qDebug() << "Hey you set the chosen file to " +
                  this->UrlToFilenameWrapper(file);
  emit this->chosen_fileChanged();
}

QObject* QtVISParseClass::SingletonGet(QQmlEngine* engine,
                                       QJSEngine* script_engine) {
  Q_UNUSED(engine);
  Q_UNUSED(script_engine);
  return new QtVISParseClass();
}

QString QtVISParseClass::UrlToFilenameWrapper(const QString text) {
  return QString(QMLUrlParser::UrlToFilename(text));
}
