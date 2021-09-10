#include "parser/url_parser.h"

QString QMLUrlParser::UrlToString(const QString url) {
  const QUrl url_super(url);
  if (url_super.isLocalFile()) {
    // Convert to native path
    return QDir::toNativeSeparators(url_super.toLocalFile());
  } else {
    return url;  // Oh well
  }
  return QString();
}

QString QMLUrlParser::UrlToFilename(const QString url) {
  return QUrl(url).toLocalFile();
}
