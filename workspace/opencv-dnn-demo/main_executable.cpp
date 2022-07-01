#include <iostream>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono> 

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

//#include "crow.h"

using namespace std;
using namespace std::chrono; 
using namespace cv;

CascadeClassifier eyes_cascade;


int main(int argc, char **argv) {
    std::cout << "Hello from main.." << std::endl;

    string image_file;
    if  (argc == 1)
    {
        // cout << "Please pass image filename to read as cmd argument" << endl;
        // return -1;
        image_file = "../resources/image.jpg";
    }
    else if (argc == 2)
    {
        image_file = argv[1];
    }

    //// 2
    /// flag value 1 to imread means -- cv2.IMREAD_COLOR:
    /// It specifies to load a color image. 
    /// Any transparency of image will be neglected. It is the default flag. Alternatively, we can pass integer value 1 for this flag.
    cv::Mat frame = cv::imread(image_file.c_str(), 1);

    if (frame.empty())
    {
        fprintf(stderr, "cv::imread %s failed\n", image_file.c_str());
        return -1;
    }
    std::cout << "cv::imread Test: image reading done successfully.. " << image_file << std::endl;

    dnn::Net model;
    std::string model_path = "../resources/effi-model.pb";
    model = cv::dnn::readNet(model_path);
    std::cout << "dnn test: Model loaded successfully..." << std::endl;

}