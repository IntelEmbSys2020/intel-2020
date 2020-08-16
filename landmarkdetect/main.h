#ifndef __MAIN_H_
#define __MAIN_H_

#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/opencv.hpp"
#include"Eigen/Dense"


#define PI 3.1514926

using namespace std;
using namespace cv;


struct flag_detection_t{
    double img_area;
    double square_area = 441;
    Point3d Pc;
    Point3d Pw;
    Point2d center;
};

struct Eular_t{
    double yaw;
    double pitch;
    double roll;
};

#endif // !__MAIN_H_
 