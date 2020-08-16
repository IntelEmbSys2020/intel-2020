#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/opencv.hpp"


using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat image(900,900,CV_8UC1,Scalar::all(255));
    rectangle(image,Rect(Point(60,60),Point(840,840)),Scalar::all(0),-1);
    rectangle(image,Rect(Point(120,120),Point(780,780)),Scalar::all(255),-1);
    rectangle(image,Rect(Point(180,180),Point(720,720)),Scalar::all(0),-1);
    rectangle(image,Rect(Point(240,240),Point(660,660)),Scalar::all(255),-1);
    rectangle(image,Rect(Point(300,300),Point(600,600)),Scalar::all(0),-1);
    rectangle(image,Rect(Point(360,360),Point(540,540)),Scalar::all(255),-1);
    rectangle(image,Rect(Point(400,400),Point(500,500)),Scalar::all(0),-1);

    imshow("image",image);
    imwrite("landmark.jpg",image);
    waitKey(0);
    destroyAllWindows();
}