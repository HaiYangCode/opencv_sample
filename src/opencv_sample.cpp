#include<stdio.h>
#include<iostream>
#include "opencv2/opencv.hpp"
#include "FaceTracking.h"

using namespace std;
using namespace cv;

#define MACOS 1
#define ANDROID 2
#define OS_TYPE MACOS
#define DEBUG 1
#define RELEASE 2
#define RUN_MODEL DEBUG

/**
 * 打开摄像头
*/
void showCamera(){
    VideoCapture pic(0);
    Mat src;//表示一个矩阵，代表一张图片
    Mat  dest;//处理后的图片
    String stdFileName = "/Users/yh/ndkSource/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalface.xml";

    cv::Ptr<CascadeDetectorAdapter> mainDetector = makePtr<CascadeDetectorAdapter>(
            makePtr<CascadeClassifier>(stdFileName));
    cv::Ptr<CascadeDetectorAdapter> trackingDetector = makePtr<CascadeDetectorAdapter>(
            makePtr<CascadeClassifier>(stdFileName));
    DetectorAgregator  *result = new DetectorAgregator(mainDetector, trackingDetector);
    result->tracker->run();
    std::vector<Rect> faces;
    while (1)
    {
        pic >> src;
        /**
         * 显示一个新窗口
         * 第一个参数：窗口名字
         * 第二个参数：显示的图像
         * 每次都会打开一个窗口，同时旧窗口也会被关闭
        */
//
#if OS_TYPE == MACOS
        //将颜色改成黑白色，用于较小加载数据的大小，因为颜色对识别轮廓没有帮助
        cvtColor(src,dest,COLOR_BGR2GRAY); 
        
#elif OS_TYPE == ANDROID
        cvtColor(src,dest,COLOR_YUV2RGB_NV12);
#endif
        //增加轮廓对比(直方图均衡)
        equalizeHist(dest,dest);
        result->tracker->process(dest);
		result->tracker->getObjects(faces);
        for (auto face:faces)
        {
            rectangle(dest,face,Scalar(255,0,255));
        }
        
        imshow("camera",dest);
        waitKey(20);
    };
    result->tracker->stop();
}

int main(){
    
    showCamera();
    return 0;
}

/**
 * 显示一张图片
*/
void showPic(){

     Mat  src = imread("/Users/yh/Documents/照片/IMG_20200315_171724.jpg");
    imshow("a",src);
    cvtColor(src,src,COLOR_BGR2GRAY);
    imshow("B",src);
    waitKey();
}