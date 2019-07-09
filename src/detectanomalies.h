#ifndef ANOMALYDETECTIONCPP_DETECTANOMALIES_H
#define ANOMALYDETECTIONCPP_DETECTANOMALIES_H

#include "statistics.h"

std::vector<double> detect_anomalies_global(const std::vector<double> &data);
std::vector<double> detect_anomalies_moving(const std::vector<double> &data,
                                            int window_size);
std::vector<double> detect_anomalies_mad(const std::vector<double> &data);

#endif
