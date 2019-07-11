#include "detectanomalies.h"
#include "io.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    std::cerr << "For usage, please look README file.";
    return 1;
  } else {
    std::vector<double> data = parseCsv(argv[1]);
    std::string method = argv[2];
    if (method == "tsg") {
      Result anomalies = detect_anomalies_global(data);
      std::cout << "Detected anomalies with global averages: " << std::endl;
      for (decltype(anomalies.indexes.size()) i = 0;
           i < anomalies.indexes.size(); i++) {
        std::cout << "Index: " << anomalies.indexes[i]
                  << "\t Value: " << anomalies.anomalies[i] << std::endl;
      }
    } else if (method == "tsr") {
      if (argc <= 3) {
        std::cerr << "You must type window size.";
        return 1;
      }
      Result anomalies = detect_anomalies_moving(data, std::stoi(argv[3]));
      std::cout << "Detected anomalies with moving averages: " << std::endl;
      for (decltype(anomalies.indexes.size()) i = 0;
           i < anomalies.indexes.size(); i++) {
        std::cout << "Index: " << anomalies.indexes[i]
                  << "\t Value: " << anomalies.anomalies[i] << std::endl;
      }
    } else if (method == "mad") {
      Result anomalies = detect_anomalies_mad(data);
      std::cout << "Detected anomalies with median absolute deviation: "
                << std::endl;
      for (decltype(anomalies.indexes.size()) i = 0;
           i < anomalies.indexes.size(); i++) {
        std::cout << "Index: " << anomalies.indexes[i]
                  << "\t Value: " << anomalies.anomalies[i] << std::endl;
      }
    } else {
      std::cerr << "Please type correct algorithm.";
      return 1;
    }
  }
  return 0;
}