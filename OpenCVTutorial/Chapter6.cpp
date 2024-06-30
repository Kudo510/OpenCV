#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Color Detection  //////////////////////

void main6() {

	// Load image
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	cout << "image matrix" << img.size() << endl;

	// create HSV image of the input imge - HSV for Hue, Saturation, 
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	// detect color using the HSV image
	// Set initial values for HSV thresholds
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);

	Mat mask;

	// Create a window for trackbars
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		// Update the lower and upper HSV bounds
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		// Apply the HSV range to create a mask
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);
	}
}