#include "io.h"

std::vector<double> parseCsv(const std::string &filename) {
  std::vector<double> data;
  std::fstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    data.push_back(std::stod(line));
  }
  return data;
}