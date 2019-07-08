#include "statistics.h"

double mean(const std::vector<double> &data) {
  double psum = std::accumulate(data.begin(), data.end(), 0.0);
  double pmean = psum / data.size();
  return pmean;
}

double stddev(const std::vector<double> &data) {
  double pmean = mean(data);
  double acc = 0.0;
  std::for_each(data.begin(), data.end(),
                [&](const double d) { acc += (d - pmean) * (d - pmean); });
  double sstddev = std::sqrt(acc / (data.size() - 1));
  return sstddev;
}
