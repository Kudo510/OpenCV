#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//////////////  Draw Shapes and Text //////////////////////

void main4() {

	// Create a blank image with size (512,512) with 8 bits U for unsigned means each pixel has value from 0 to 255; define our color using Scalar - 0,0,0 will be black image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// Create a circle 
	// Point as cnter point of the cirlle here at 256,256; then comes radius, then comes the color; fill the cirlle
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED); 

	// Create a rectangle in the image
	// 2 point as point upper left and point bottom right
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED); 
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, String("newbie at Opencv"), Point(382, 286), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 255, 255));

	imshow("Image", img);
	waitKey(0);
}