#include "main.h"
#include "detection.h"
#include "estimate.h"


int main(int argc, char **argv){
    Mat image = imread("03.jpg");
    flag_detection_t td;
    Eular_t current_att;
    current_att.pitch = 0;
    current_att.yaw = 0;
    current_att.roll = 0;
    td = DetectMark(image);
    Estimate(&td, current_att);
    cout << td.Pw.x << " " << td.Pw.y << " " << td.Pw.z << endl;
    waitKey(0);
    destroyAllWindows();
}