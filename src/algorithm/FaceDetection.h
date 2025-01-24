#ifndef FACE_DETECT_H
#define FACE_DETECT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <obs-module.h>
#include "plugin-support.h"
#include <vector>
#include <iostream>
#include <stdexcept>

#include "heart_rate_source.h"

std::vector<std::vector<bool>>
detectFacesAndCreateMask(struct input_BGRA_data *frame);

#endif
