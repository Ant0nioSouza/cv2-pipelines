#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>

#define PIC_PATH "/home/isomeister/cap1.jpg"

using namespace std;
using namespace cv;


VideoCapture cap(0);

int  t1 = 204, t2 = 255, t3 = 0;


/**
 * @brief save the gived frame in a file.
 * 
 * @param video The frame in format of cv::Mat.
 * @param resolution The resolution that the picture must be saved.
 */
void takePicture(Mat video, Size resolution) {
    Mat dst;
    resize(video, dst, resolution);
    //imwrite(PIC_PATH, dst);
}

/**
 * @brief 
 * 
 * @param path 
 * @param redSide 
 */
void recognize(Mat path, bool redSide) {
    Mat res, gray, tresh;
    
    resize(path, res, Size(200, 200));
    cvtColor(res, gray, COLOR_BGR2GRAY);


    imshow("resized", res);
    imshow("marked", gray);
    threshold(gray, gray, t1, t2, t3);


}

int main(int, char **) {

    Mat source;
    
    cap.read(source);
    
    //cout << "Capturing image...";
    //takePicture(source, Size(150, 200));
    cout << "Recognizing image...";
    recognize(imread(PIC_PATH), false);

    return 0;
}
