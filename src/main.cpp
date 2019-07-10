#include "detectanomalies.h"
#include "io.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: \n\tAnomalyDetectionCpp filename window_size";
    return 1;
  } else {
    std::vector<double> data = parseCsv(argv[1]);
    Result anomalies_moving = detect_anomalies_moving(data, std::stoi(argv[2]));
    Result anomalies_global = detect_anomalies_global(data);
    Result anomalies_mad = detect_anomalies_mad(data);
    std::cout << "Detected anomalies with moving averages: " << std::endl;
    for (decltype(anomalies_moving.indexes.size()) i = 0;
         i < anomalies_moving.indexes.size(); i++) {
      std::cout << "Index: " << anomalies_moving.indexes[i]
                << "\t Value: " << anomalies_moving.anomalies[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Detected anomalies with global averages: " << std::endl;
    for (decltype(anomalies_global.indexes.size()) i = 0;
         i < anomalies_global.indexes.size(); i++) {
      std::cout << "Index: " << anomalies_global.indexes[i]
                << "\t Value: " << anomalies_global.anomalies[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Detected anomalies with median absolute deviation: "
              << std::endl;
    for (decltype(anomalies_mad.indexes.size()) i = 0;
         i < anomalies_mad.indexes.size(); i++) {
      std::cout << "Index: " << anomalies_mad.indexes[i]
                << "\t Value: " << anomalies_mad.anomalies[i] << std::endl;
    }
  }
  return 0;
}