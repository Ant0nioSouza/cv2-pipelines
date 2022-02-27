#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

#define PIC_PATH "/home/isomeister/pic1.png"

using namespace std;
using namespace cv;


VideoCapture cap(0);

/**
 * @brief save the gived frame in a file.
 * 
 * @param video The frame in format of cv::Mat.
 * @param resolution The resolution that the picture must be saved.
 */
void takePicture(Mat video, Size resolution) {
    Mat dst;
    resize(video, dst, resolution);
    imwrite(PIC_PATH, dst);
}

void recognize(string path, bool redSide) {
    Mat res, gray, tresh;
    
    resize(imread(path), res, Size(200, 200));
    cvtColor(res, gray, COLOR_BGR2GRAY);
    threshold(gray, gray, 80, 255, 0);

    imshow("resized", res);
    imshow("marked", gray);
    //imshow("treshold", tresh);
    waitKey(0);
}

int main(int, char **) {

    Mat source;
    cap.read(source);
    
    cout << "Capturing image...";
    takePicture(source, Size(150, 200));
    cout << "Recognizing image...";
    recognize("/home/isomeister/Pictures/Screenshot from 2022-02-27 19-24-12.png", false);

    return 0;
}
