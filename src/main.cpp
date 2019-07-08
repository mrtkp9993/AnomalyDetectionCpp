#include <iostream>
#include <vector>
#include "detectanomalies.h"
#include "io.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: \n\tAnomalyDetectionCpp filename window_size";
    return 1;
  } else {
    std::vector<double> data = parseCsv(argv[1]);
    std::vector<double> anomalies_moving =
            detect_anomalies_moving(data, std::stoi(argv[2]));
    std::vector<double> anomalies_global = detect_anomalies(data);
    std::cout << "Detected anomalies with moving averages: " << std::endl;
    for (auto &i : anomalies_moving) {
      std::cout << i << std::endl;
    }
    std::cout << "Detected anomalies with global average: " << std::endl;
    for (auto &i : anomalies_global) {
      std::cout << i << std::endl;
    }
  }
  return 0;
}