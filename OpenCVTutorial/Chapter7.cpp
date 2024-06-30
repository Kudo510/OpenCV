#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Shape/Contour Detection  //////////////////////

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size()); // means the size of conpoly cannot exceed contours.size()
	vector<Rect> boundRect(contours.size()); // same for bound rect

	//All lb just try to get a shape of an object - 3 points on contours as triangle, 4 then rectangle/square, more than 4 is a circle
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]); // to calculate area of a region/countour
		cout << area << endl;
		string objectType;
		//only care contour of obejct with area >100
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true); // find the perimeter of contours
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			// 3 points on contours as triangle, 4 then rectangle / square, more than 4 is a circle
			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

int main7() // change to main if u wan to run this file
	{
		// import image
		string img_path = "Resources\\shapes.png";
		Mat img = imread(img_path);

		//Find the edges and find the contour points

		// Get all iamge blur, image canny, imgdil, imgerode - the step is preprocessing the image
		Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
		cvtColor(img, imgGray, COLOR_BGR2GRAY); // convert color image to gray image- assign this value to imgGray
		GaussianBlur(img, imgBlur, Size(7, 7), 5, 2); // blur image using Gaussian; 5 , 0 i
		Canny(img, imgCanny, 25, 75); // detects edges in an image using the Canny edge detection algorithm.
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); //Creates a structuring element used for morphological operations.
		dilate(imgCanny, imgDil, kernel); // dilate means we increase the thickness of edges

		getContours(imgDil, img);
		imshow("Image", img);
		//imshow("gray image", imgGray);
		//imshow("blur image", imgBlur);
		//imshow("image canny", imgCanny);
		//imshow("image dilation", imgDil);

		// see that image dil is better than imag canny- cos in image canny when u zoom it in, it doesn look good
		// So we use ImgDil to get contour

		waitKey();
		return 0;
	}
	