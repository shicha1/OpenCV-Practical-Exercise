// face_detection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "face_detection.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using namespace std;
using namespace cv;
using namespace cv::dnn;

string faceCascadePath = "./model/haarcascade_frontalface_default.xml";

string caffeConfigFile = "./model/deploy.prototxt";
string caffeWeightFile = "./model/res10_300x300_ssd_iter_140000_fp16.caffemodel";
string tensorflowConfigFile = "./model/opencv_face_detector.pbtxt";
string tensorflowWeightFile = "./model/opencv_face_detector_uint8.pb";

int main(void)
{
	Mat frame = imread("d:/1.jpg");
	Mat resultImg_Harr = detectFaceHaar(frame, faceCascadePath);
	Mat resultImg_OpenCVCaffe = detectFaceOpenCVDNN(frame, caffeConfigFile, caffeWeightFile);
	Mat resultImg_OpenCVTf = detectFaceOpenCVDNN(frame, tensorflowConfigFile, tensorflowWeightFile);
	return 0;
}