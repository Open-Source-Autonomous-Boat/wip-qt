#include "db.h"

DBManager::DBManager() {
  // If on Windows, get home directory and set cache to respective sub-dir
#if defined(_WINDOWS) || defined(__MINGW64__) || defined(__MINGW32__) || \
    defined(_MSC_VER)
  // Why Windows whyyyyy????!?!??
  int buf_size = 65535;
  std::wstring buff;  
  buff.resize(buf_size);
  buf_size = GetEnvironmentVariableW(L"USERPROFILE", &buff[0], buf_size);
  if (!buf_size) {
    qDebug() << "Failed to get environment variable";
    return;
  }
  buff.resize(buf_size);
  const QString home_dir = QString::fromWCharArray(buff.c_str());
  const QString cache_dir(QString("%1/AppData/Roaming/osab").arg(home_dir));
#elif defined(__unix__)  // if on *NIX, same as above
  const QString home_dir = std::getenv("HOME");
  const QString cache_dir(QString("%1/.cache/osab").arg(home_dir));
#else                    // if on some esotheric OS
  const QString cache_dir(QString("./"));
  std::cerr << "Unknown/Unhandled OS"
            << std::endl;  // Please open GitHub issue for such events uwu
#endif
  const QString path(QString("%1/db.sql").arg(cache_dir));
  QDir db_dir(cache_dir);
  if (!db_dir.exists()) {  // Creates directory just in case <3
    db_dir.mkpath(cache_dir);
  }
  // Checks if DB is already open
  if (!QSqlDatabase::contains("main_db")) {
    // If so, add new DB with QT driver and name
    this->db = QSqlDatabase::addDatabase("QSQLITE", "main_db");
    // Set path for the DB, wtf is path called "name"
    this->db.setDatabaseName(path);
  } else {
    // Otherwise just set DB to pre-existing DB
    this->db = QSqlDatabase::database("main_db");
  }
  // Open it too
  this->db.open();
  this->query = new QSqlQuery(this->db);  // Initialize querys boiii
  /* Fancy SQLite to create table in case table does not exist
   *
   * info - Name of table
   * key - The key of table, \\
   * but in string/text for convinience(Please fix spelling thx)
   * value - Value of key
   */
  this->query->exec(
      "CREATE TABLE IF NOT EXISTS info(key TEXT PRIMARY KEY, value TEXT)");
}

// Delete dangling pointers
DBManager::~DBManager() { delete this->query; };

QString DBManager::GetValue(QString key) {
  // Prepare to get value from key in table
  this->query->prepare("SELECT value FROM info WHERE key=:key");
  // Bind values to the respective strings
  this->query->bindValue(":key", key);
  if (!this->query->exec()) {
    // Print error if error <3
    qDebug() << this->query->lastError().text();
    return "";  // Returns NULL if empty
  }
  if (this->query->next()) {                  // Checks if exists in DB
    return this->query->value(0).toString();  // Returns value UwU
  } else {
    return "";  // Returns NULL
  }
}

void DBManager::SetValue(QString key, QString value) {
  // Prepare to update or insert key and value into DB
  this->query->prepare(
      "INSERT INTO info(key, value) VALUES(:key, :value)"
      "ON CONFLICT(key) DO UPDATE SET value=excluded.value");
  // Bind values to the respective strings
  this->query->bindValue(":key", key);
  this->query->bindValue(":value", value);
  if (!this->query->exec()) {  // Execute
                               // Print error if error <3
    qDebug() << this->query->lastError().text();
  }
}

void DBManager::RemValue(QString key) {
  // Prepare to delete key and value from table
  this->query->prepare("DELETE FROM info WHERE key=:key");
  // Bind values to the respective strings
  this->query->bindValue(":key", key);
  if (!this->query->exec()) {
    // Print error if error <3
    qDebug() << this->query->lastError().text();
  }
}
