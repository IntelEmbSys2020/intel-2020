#ifndef __DECTECTION_H__
#define __DECTECTION_H__

#include "main.h"

#define MIN_CENTER_DIS 100

double getDistance (Point pointO,Point pointA);
flag_detection_t DetectMark(Mat image);

#endif
