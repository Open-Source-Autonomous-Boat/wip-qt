#include "parser/qt_vis_parser.h"

#include "parser/url_parser.h"

QtVISParseClass::QtVISParseClass(QObject* parent) : QObject(parent) {}

QString QtVISParseClass::chosen_file() { return this->prop_chosen_file; }
QString QtVISParseClass::file_contents() {
  if (this->prop_file_contents.isEmpty()) {
    this->FileGetText();
  }
  return this->prop_file_contents;
}

void QtVISParseClass::setchosen_file(const QString file) {
  this->prop_chosen_file = file;
  this->FileGetText();
  emit this->chosen_fileChanged();
}

void QtVISParseClass::setfile_contents(const QString text) {
  if (this->prop_chosen_file.isEmpty()) {  // If empty file sel, return
    return;
  }
  // Open QFile with the file's path properly fixed TODO: Error handling
  QFile file(this->UrlToFilenameWrapper(this->prop_chosen_file));
  if (file.open(QIODevice::WriteOnly)) {  // Open file as WO
    QTextStream stream(&file);            // Open stream of text
    stream << text << Qt::endl;         // Set text stream to text with endline
    emit this->file_contentsChanged();  // emit change
  } else {                              // If cannot open/write to file
    qInfo() << "Failed to open file!\n";
  }
  file.close();  // Close file
}

QObject* QtVISParseClass::SingletonGet(QQmlEngine* engine,
                                       QJSEngine* script_engine) {
  Q_UNUSED(engine);
  Q_UNUSED(script_engine);
  return new QtVISParseClass();
}

QString QtVISParseClass::UrlToFilenameWrapper(const QString text) {
  return QMLUrlParser::UrlToFilename(text);
}

void QtVISParseClass::FileGetText() {
  // Reset text to empty string
  this->prop_file_contents = "";
  // If no file, return
  if (this->prop_chosen_file.isEmpty()) {
    return;
  }
  // Open QFile with the file's path properly fixed TODO: Error handling
  QFile file(this->UrlToFilenameWrapper(this->prop_chosen_file));
  // Open stream of text
  QTextStream stream(&file);
  if (file.open(QIODevice::ReadOnly)) {  // Open file as RO
    for (; !stream.atEnd();) {           // While file does not end
      QString line = stream.readLine();  // Read line onto string
                                         // Append line to file content prop
      this->prop_file_contents += line + "\n";
    }
  } else if (!file.exists()) {  // If file does not exist, return
    // this->prop_file_contents = "";
    return;
  } else {  // Else, return errors
    qDebug() << "Unknown error in QtVISParseClass::FileGetText()";
  }
  // Close the file
  file.close();
  // Emit change
  emit this->file_contentsChanged();
}
