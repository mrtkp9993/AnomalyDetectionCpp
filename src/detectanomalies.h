#ifndef ANOMALYDETECTIONCPP_DETECTANOMALIES_H
#define ANOMALYDETECTIONCPP_DETECTANOMALIES_H

#include "statistics.h"

struct Result {
  std::vector<int> indexes;
  std::vector<double> anomalies;
};

Result detect_anomalies_global(const std::vector<double> &data);
Result detect_anomalies_moving(const std::vector<double> &data,
                                            int window_size);
Result detect_anomalies_mad(const std::vector<double> &data);

#endif
