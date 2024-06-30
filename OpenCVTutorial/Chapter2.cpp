#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main2() // change to main if u wan to run this file
{
	// import image
	string img_path = "Resources\\cards.jpg";
	Mat img = imread(img_path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY); // convert color image to gray image- assign this value to imgGray
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 2); // blur image using Gaussian; 5 , 0 i
	Canny(img, imgCanny, 25, 75); // detects edges in an image using the Canny edge detection algorithm.

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); //Creates a structuring element used for morphological operations.
	dilate(imgCanny, imgDil, kernel); // dilate means we increase the thickness of edges
	erode(imgCanny, imgErode, kernel); // erosion means we decrease the thickness of edges

	imshow("Image", img);
	imshow("Gray Image", imgGray);
	imshow("Blur image", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);

	waitKey(0); // set it as infinity means show the image forever until u type sth
}