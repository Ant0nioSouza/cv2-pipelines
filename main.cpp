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

vector<Point> biggerContour;

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

void getCountours(Mat img, Mat source) {


    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(source, contours, -1, Scalar(255, 0, 255), 2);

    int biggerArea = 150;

    for (int i = 0; i < contours.size(); i++) {

        //cout << "\nX " << boundingRect(contours[i]).x << "Y " << boundingRect(contours[i]).y << "W ", boundingRect(contours[i]).width, "H ", boundingRect(contours[i]).height;
        //cout << "| Area: " << boundingRect(contours[i]).area() << "\n";

        if (boundingRect(contours[i]).y > 40 || boundingRect(contours[i]).x > 155) {
            
            if (boundingRect(contours[i]).y < 10) {
                continue;
            }
        }

        int area = contourArea(contours[i]);
                if (area > biggerArea) {
                    biggerContour = contours[i];
                    cout << "\nX " << boundingRect(biggerContour).x << "Y " << boundingRect(biggerContour).y << "W ", boundingRect(biggerContour).width, "H ", boundingRect(biggerContour).height;
                    cout << "| Area: " << boundingRect(biggerContour).area() << "\n";
                    continue;
                }

        /*
        circle(res, Point(20, 17), 10, Scalar(173, 24, 11), FILLED);
        circle(res, Point(81, 31), 10, Scalar(250, 228, 85), FILLED);
        circle(res, Point(145, 30), 10, Scalar(35, 233, 250), FILLED);
        */

    }
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


    
    threshold(gray, gray, t1, t2, t3);
    getCountours(gray, res);

    cout << "AREA BIG CONTOUR: " << boundingRect(biggerContour).area() << "\n";


    circle(res, Point(boundingRect(biggerContour).x, boundingRect(biggerContour).y), 10, Scalar(250, 228, 85), FILLED);
    //drawContours(res, biggerContour, -1, Scalar(255, 0, 255), 2);
    

    imshow("resized", res);
    imshow("marked", gray);
    waitKey(0);
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
