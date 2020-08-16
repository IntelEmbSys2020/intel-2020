#include "detection.h"

double getDistance (Point pointO,Point pointA)
{ 
    double distance;  
    distance = powf((pointO.x - pointA.x),2) + powf((pointO.y - pointA.y),2);  
    distance = sqrtf(distance);  
    return distance;   
}

flag_detection_t DetectMark(Mat image)
{
    double time = getTickCount();
    flag_detection_t td;
    Mat th_img;
    cvtColor(image,th_img,COLOR_BGR2HSV);
    inRange(th_img,Scalar(0,0,80),Scalar(180,255,120),th_img);
    //cvtColor(image,th_img,COLOR_BGR2GRAY);
    //Mat th_img;
    //threshold(th_img, th_img, 100,255,THRESH_BINARY);
    namedWindow("1",0);
    imshow("1",th_img);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(th_img,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_NONE);
    
    vector<Point> approxout;
    vector<vector<Point>> square_v;
    vector<Point> center_v;
    Point center_temp;
    for(int i = 0; i < contours.size();i++){
        approxPolyDP(Mat(contours[i]),approxout,arcLength(Mat(contours[i]),true)*0.03,true);
        if(approxout.size() == 4 &&
           fabs(contourArea(Mat(approxout))) > 1000 &&
           isContourConvex(Mat(approxout))){
               square_v.push_back(approxout);
               for(auto iter = approxout.begin(); iter != approxout.end(); iter++){
                   center_temp.x += (*iter).x;
                   center_temp.y += (*iter).y;
               }
               center_temp.x /= 4;
               center_temp.y /= 4;
               center_v.push_back(center_temp);
               center_temp = Point(0,0);
           }
        approxout.clear();
    }

    //使用矩形聚类排除干扰
    vector<vector<int>> result;
    vector<int> centers_index;
	vector<int> result_temp;
	int index_i;
	int index_j;
    int result_count = 0;
	for(int i = 0; i < center_v.size(); i++){
		centers_index.push_back(i);    //save the index of squares centers
	}
 
	for(int i = 0; i < centers_index.size(); i++){
		result_temp.push_back(centers_index[i]);
		for(int j = i + 1; j < centers_index.size(); j++){
			index_i = centers_index[i];
			index_j = centers_index[j];
			if( getDistance( center_v[index_i], center_v[index_j] ) < MIN_CENTER_DIS )
			{
				result_temp.push_back(centers_index[j]);
				centers_index.erase(centers_index.begin() + j - 1);
				j--;
			}
		}
		result.push_back(result_temp);
		result_temp.clear();
	}
    for(auto iter = result.begin(); iter != result.end(); iter++){
        if((*iter).size() > result_count){
            result_temp = (*iter);
            result_count = (*iter).size();
        }
    }
    Point2d center;
    vector<double> areas;
    vector<vector<Point>> square_result;
    for(int i = 0; i < result_temp.size(); i++){
        square_result.push_back(square_v[result_temp[i]]);
        center.x += center_v[result_temp[i]].x;
        center.y += center_v[result_temp[i]].y;
        areas.push_back(contourArea(square_v[result_temp[i]]));
    }
    center.x /= result_temp.size();
    center.y /= result_temp.size();
    sort(areas.begin(), areas.end());
    td.img_area = areas[0];
    td.center = center;
    time = (double)getTickCount() - time;
    cout << time / getTickFrequency() * 1000 << "ms" << endl;

    Mat temp;
    image.copyTo(temp);
    polylines(temp,square_result,true,Scalar(0,255,0),5);
    namedWindow("test",0);
    imshow("test",temp);

    return td;
}