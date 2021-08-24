#include "parser/line_numbers.h"

LineNumberHandler::LineNumberHandler() {}

int LineNumberHandler::CalculateFileLines(const QString a_path) {
  if (a_path == "") return 0;
  qDebug() << a_path;
  std::ifstream file(a_path.toStdString());
  int count;
  std::string line;
  for (count = 0; std::getline(file, line);) {
    ++count;
  }
  qDebug() << count;
  this->setlines_count(count);
  return count;
}

int LineNumberHandler::CalculateLineWidth(int a_max_line) {
  /* HACK: Yandere dev time :D */
  if (a_max_line < 10) {
    return 25;
  } else if (a_max_line < 100) {
    return 30;
  } else if (a_max_line < 1000) {
    return 35;
  } else {
    return 40;
  }
}

QObject* LineNumberHandler::SingletonGet(QQmlEngine* a_engine,
                                         QJSEngine* a_script_engine) {
  Q_UNUSED(a_engine);
  Q_UNUSED(a_script_engine);
  return new LineNumberHandler();
}

void LineNumberHandler::ResetBar() {
  QQmlEngine engine;
  QQmlComponent component(&engine, "./tabs/VisUtil.qml");
  QObject* object = component.create();
}

/* Properties */
int LineNumberHandler::lines_count() { return this->prop_lines_count; }
void LineNumberHandler::setlines_count(const int a_lines) {
  this->prop_lines_count = a_lines;
  qDebug() << a_lines;
  this->ResetBar();
  emit this->lines_countChanged();
}
