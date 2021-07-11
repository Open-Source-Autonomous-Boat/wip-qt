#include "parser/types.h"
#include "parser/info.h"

#include <QString>
#include <fstream>
#include <iostream>
#include <string>
#pragma once


class VISLParser {
  VISLParser();
  ~VISLParser() {};
  public:
  void OpenFile(std::string path);
  void Parse();
private:
  std::ifstream *file;
  bool is_opened;
  visl_types data;
};
