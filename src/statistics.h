#ifndef ANOMALYDETECTIONCPP_STATISTICS_H
#define ANOMALYDETECTIONCPP_STATISTICS_H

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

double mean(const std::vector<double> &data);
double stddev(const std::vector<double> &data);
double median(const std::vector<double> &data);

#endif
