#include<stdio.h>
#include<iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
    printf("hello,show pic\n");
    Mat  src = imread("/Users/yh/Documents/照片/IMG_20200315_171724.jpg");
    imshow("a",src);
    cvtColor(src,src,COLOR_BGR2GRAY);
    imshow("B",src);
    waitKey();

    return 0;
}