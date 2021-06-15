#include "utils/psuedo_uuid_gen.h"

#include <QString>
#include <algorithm>
#include <iostream>
#include <random>

QString psuedo_uuid::gen() {
  // Declare empty QString
  QString uuid;
  for (int i = 0; i <= 8; i++) {
    /*
     * For loops of 8, add random numbers
     *
     * Add uuid + random digit and assign that to pre-existant uuid
     */
    uuid = QString(uuid + QString::number(std::rand() % 10 + 1));
  }
  // Return at last uwu
  return uuid;
}
