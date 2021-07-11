#include "parser/parser.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

VISLParser::VISLParser(){};

void VISLParser::OpenFile(std::string path) {
  this->file->open(path);
  this->is_opened = true;
  this->Parse();
}

void VISLParser::Parse() {
  std::vector<std::string>tokens;
  if (!this->is_opened) return;
  for (std::string line; std::getline(*this->file, line);) {
    if (line.rfind("(#|//)", 0)) {
      continue;
    }
  }
}
