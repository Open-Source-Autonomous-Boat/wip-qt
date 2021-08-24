#include "parser/qt_vis_parser.h"

#include "parser/url_parser.h"

QtVISParseClass::QtVISParseClass(QObject* parent) : QObject(parent) {}

QString QtVISParseClass::chosen_file() { return this->prop_chosen_file; }
QString QtVISParseClass::file_contents() {
  if (this->prop_file_contents == "") {
    this->FileGetText();
  }
  return this->prop_file_contents;
}

void QtVISParseClass::setchosen_file(const QString file) {
  this->prop_chosen_file = file;
  qDebug() << "Hey you set the chosen file to " +
                  this->UrlToFilenameWrapper(file);
  this->FileGetText();
  emit this->chosen_fileChanged();
}

void QtVISParseClass::setfile_contents(const QString text) {
  QFile file(this->chosen_file());
  if (file.open(QIODevice::WriteOnly)) {
    QTextStream stream(&file);
    stream << text << Qt::endl;
    emit this->file_contentsChanged();
  } else {
    qInfo() << "Failed to open file!\n";
  }
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

void QtVISParseClass::FileGetText() {
  QFile file(this->prop_chosen_file);
  QTextStream stream(&file);
  if (file.open(QIODevice::ReadOnly)) {
    for (; !stream.atEnd();) {
      QString line = stream.readLine();
      this->prop_file_contents += line + "\n";
    }
  } else {
    qInfo("Oh fuck this broke");
  }
  file.close();
  emit this->file_contentsChanged();
}
