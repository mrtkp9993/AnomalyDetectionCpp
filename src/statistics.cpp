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

double median(const std::vector<double> &data) {
  std::vector<double> data_copy(data.size());
  std::copy(data.begin(), data.end(), data_copy.begin());
  std::sort(data_copy.begin(), data_copy.end());
  double median;
  if (data_copy.size() % 2 == 0) {
    int first_index = data.size() / 2;
    int second_index = data.size() / 2 + 1;
    median = (data_copy[first_index] + data_copy[second_index]) / 2;
  } else {
    median = data_copy[(data.size() + 1)/2];
  }
   return median;
}