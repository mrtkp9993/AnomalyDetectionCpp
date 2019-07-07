#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<double> parseCsv(std::string filename) {
  std::vector<double> data;
  std::fstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    data.push_back(std::stod(line));
  }
  return data;
}

double mean(std::vector<double> data) {
  double psum = std::accumulate(data.begin(), data.end(), 0.0);
  double pmean = psum / data.size();
  return pmean;
}

double stddev(std::vector<double> data) {
  double pmean = mean(data);
  double acc = 0.0;
  std::for_each(data.begin(), data.end(),
                [&](const double d) { acc += (d - pmean) * (d - pmean); });
  double sstddev = std::sqrt(acc / (data.size() - 1));
  return sstddev;
}

std::vector<double> detect_anomalies(std::vector<double> data) {
  std::vector<double> anomalies;
  double data_mean = mean(data);
  double data_stddev = stddev(data);
  for (int i = 0; i < data.size(); i++) {
    double score = data[i] - data_mean;
    if (std::abs(score) > 3 * data_stddev) {
      anomalies.push_back(data[i]);
    }
  }
  return anomalies;
}

std::vector<double> detect_anomalies_moving(std::vector<double> data,
                                            int window_size) {
  std::vector<double> anomalies;
  for (int i = window_size - 1; i < data.size(); i++) {
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

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: \n\tAnomalyDetectionCpp filename window_size";
    return 1;
  } else {
    std::vector<double> data = parseCsv(argv[1]);
    std::vector<double> anomalies_moving = detect_anomalies_moving(data, std::stoi(argv[2]));
    std::vector<double> anomalies_global = detect_anomalies(data);
    std::cout << "Detected anomalies with moving averages: " << std::endl;
    for (auto& i : anomalies_moving) {
      std::cout << i << std::endl;
    }
    std::cout << "Detected anomalies with global average: " << std::endl;
    for (auto& i : anomalies_global) {
      std::cout << i << std::endl;
    }
  }
  return 0;
}
