#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

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

int main(int, char **) {

    Mat source;
    cap.read(source);
    
    cout << "Capturing image...";
    takePicture(source, Size(150, 200));

    return 0;
}
