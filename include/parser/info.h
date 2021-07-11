#pragma once

struct visl_file_info {
  int instruction_type;
};

enum visl_instruction_type {
  mission_instruction,
  instruction_msg,
  data_msg,
};
