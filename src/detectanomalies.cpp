#include "detectanomalies.h"
#include <iostream>

Result detect_anomalies_global(const std::vector<double> &data) {
  Result res;
  double data_mean = mean(data);
  double data_stddev = stddev(data);
  for (decltype(data.size()) i = 0; i < data.size(); i++) {
    double score = data[i] - data_mean;
    if (std::abs(score) > 3 * data_stddev) {
      res.indexes.push_back(i);
      res.anomalies.push_back(data[i]);
    }
  }
  return res;
}

Result detect_anomalies_moving(const std::vector<double> &data,
                                            int window_size) {
  Result res;
  std::vector<double> anomalies;
  for (decltype(data.size()) i = window_size - 1; i < data.size(); i++) {
    std::vector<double> window = std::vector<double>(
        data.begin() + i - window_size + 1, data.begin() + i + 1);
    double moving_mean = mean(window);
    double moving_stddev = stddev(window);
    double score = data[i] - moving_mean;
    if (std::abs(score) > 3 * moving_stddev) {
      res.indexes.push_back(i);
      res.anomalies.push_back(data[i]);
    }
  }
  return res;
}

Result detect_anomalies_mad(const std::vector<double> &data) {
  Result res;
  std::vector<double> data_copy(data.size());
  std::copy(data.begin(), data.end(), data_copy.begin());
  std::vector<double> anomalies;
  double dmedian = median(data_copy);
  double mad = 1.4826 * median(data_copy);
  for (decltype(data_copy.size()) i = 0; i < data_copy.size(); i++) {
    double score = std::abs(data_copy[i] - dmedian) / mad;
    if (score > 3) {
      res.indexes.push_back(i);
      res.anomalies.push_back(data[i]);
    }
  }
  return res;
}