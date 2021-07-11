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
  if (!this->is_opened) return;
  for (std::string line; std::getline(*this->file, line);) {
    if (line.rfind("(#|//)", 0)) {
      continue;
    }
    this->FindTypeInString(line, visl_types::h1);
  }
}

void VISLParser::FindTypeInString(std::string line, visl_types type) {
  int index;
  switch (type) {
  case (visl_types::h1): {
    std::regex reg("h1", std::regex_constants::icase);
    auto it = std::sregex_iterator(line.begin(), line.end(), reg);
    if (!it->position()) {
      std::cerr << "Failed to find type: " << std::to_string(type) << std::endl;
      return;
    }
    break;
  }
  default:
    break;
  }
}
