#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Warp Images  //////////////////////

void main5() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	float w{ 250 }, h{ 350 };
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} }; // The pixels values of the points are dectected using Paint
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} }; // so the first point we consider is as the origin so at (0,0)

	Mat transformation_matrix, imgWarp;

	transformation_matrix = getPerspectiveTransform(src, dst); // to get the transfomation amtrix to convert 4 src to dst - just that matrix to onvert all point from src to all correspoidning points in dst
	// warpPerspective to apply the transfomration matrix , so imgWarp = img* transformation matrix, w,h is the size of img Warp
	// so 10* to warp choose 4 points to warp then appy the transformation matrix
	warpPerspective(img, imgWarp, transformation_matrix, Point(w, h));

	// just for visuliaztion - create 4 small circles at t corners of the rectangle- see image u will see the 4 red points
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED); 
	}
	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);
}
