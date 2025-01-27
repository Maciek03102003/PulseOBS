#ifndef HEART_RATE_ALGO_H
#define HEART_RATE_ALGO_H

#include <cmath>
#include <iostream>
#include <vector>
#include <obs.h>
#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "heart_rate_source.h"

class MovingAvg {
private:
	int windowSize;
	int windowStride;

	std::vector<std::vector<double_t>> windows;

	std::vector<double_t> average_keyed(std::vector<std::vector<std::tuple<double, double, double>>> rgb,
					    std::vector<std::vector<bool>> skinkey = {});

	void updateWindows(double_t frame_avg);

public:
	double calculateHeartRate(struct input_BGRA_data *BGRA_data, int preFilter = 0, int ppg = 0,
				  int postFilter = 0);
};

#endif
