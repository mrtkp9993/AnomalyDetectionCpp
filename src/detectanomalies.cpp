#include "detectanomalies.h"

std::vector<double> detect_anomalies(const std::vector<double> &data) {
  std::vector<double> anomalies;
  double data_mean = mean(data);
  double data_stddev = stddev(data);
  for (decltype(data.size()) i = 0; i < data.size(); i++) {
    double score = data[i] - data_mean;
    if (std::abs(score) > 3 * data_stddev) {
      anomalies.push_back(data[i]);
    }
  }
  return anomalies;
}

std::vector<double> detect_anomalies_moving(const std::vector<double> &data,
                                            int window_size) {
  std::vector<double> anomalies;
  for (decltype(data.size()) i = window_size - 1; i < data.size(); i++) {
    std::vector<double> window = std::vector<double>(
        data.begin() + i - window_size + 1, data.begin() + i + 1);
    double moving_mean = mean(window);
    double moving_stddev = stddev(window);
    double score = data[i] - moving_mean;
    if (std::abs(score) > 3 * moving_stddev) {
      anomalies.push_back(data.at(i));
    }
  }
  return anomalies;
}