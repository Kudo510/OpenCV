
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Resize and Crop //////////////////////

void main3() // change to main if u wan to run this file
{
	// import image
	string img_path = "Resources\\cards.jpg";
	Mat img = imread(img_path);
	cout << img.size() << endl;

	// Resize image using cv:resize
	Mat resized_image, croped_img;
	// resize(img, resized_image, Size(640, 480));
	// to scale the image by zB haf at x and y direction instead of fixed size like (640,480) do lb
	resize(img, resized_image, Size(), 0.5, 0.5);

	// Crop an image from a bb  (x,y,w,h) - define the bbox here we call roi then just img(roi) la xong
	Rect roi(200, 100, 300, 300); // create a region of interest as a rectangle/bounding box (x,y,w,h)
	croped_img = img(roi);

	imshow("Image", img);
	imshow("Resized Image", resized_image);
	imshow("Image Crop", croped_img);
	waitKey(0);
}