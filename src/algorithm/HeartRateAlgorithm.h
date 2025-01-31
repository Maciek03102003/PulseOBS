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
	int windowSize = 60;
	int windowStride = 1;
	int fps = 30;
	int maxNumWindows = 8;

	std::vector<std::vector<std::vector<double_t>>> windows;

	std::vector<std::vector<bool>> latestSkinKey;
	bool detectFace = false;

	std::vector<double_t> averageRGB(std::vector<std::vector<std::vector<uint8_t>>> rgb,
					 std::vector<std::vector<bool>> skinKey = {});

	void updateWindows(std::vector<double_t> frame_avg);

	double welch(std::vector<double_t> ppgSignal);

public:
	double calculateHeartRate(struct input_BGRA_data *BGRA_data, std::vector<struct vec4> &face_coordinates,
	int preFilter = 0, int ppg = 0, int postFilter = 0);
};

#endif
