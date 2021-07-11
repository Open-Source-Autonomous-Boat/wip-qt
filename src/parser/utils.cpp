#include "parser/utils.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>


std::vector<std::string> string_utils::split_string(std::string text,
                                                    std::string delim) {
  std::string tmp;
  std::vector<std::string> tmp_vector;
  while (getline(text, tmp, ' ')) {
    tmp_vector.push_back(tmp);
  }
  return tmp_vector;
}
