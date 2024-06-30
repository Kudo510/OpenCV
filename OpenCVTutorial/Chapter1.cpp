#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main1() // change to main if u wan to run this file
{
	// import image
	string img_path = "Resources\\cards.jpg";
	Mat img = imread(img_path);
	imshow("Image", img);
	waitKey(0); // set it as infinity means show the image forever until u type sth; if 1,2,3 etc measn just show it for 1,2,3 etc seconds

	// import a video
	string video_path = "Resources/test_video.mp4";
	VideoCapture cap(video_path);
	Mat video_img;
	while (true) {
		// When the video is played til the end - it will return error since there is no scene to play - fix that use break
		if (!cap.read(video_img)) {
			break;
		};
		imshow("Image", video_img);
		if (waitKey(5) >= 0) { // set to 20 to make it slower; also, break if a key is pressed
			break;
		}
	}
	//  cap.release(); and destroyAllWindows(); are called to release the video capture object and close any open windows.
	cap.release();

	// Import camera - smae as video just the path wiill be 0 as our webcam - 1,2,3 etc if u have more than 1 webcam
	VideoCapture webcam_cap(0);
	Mat webcam_img;
	while (true) {
		// When the video is played til the end - it will return error since there is no scene to play - fix that use break
		if (!webcam_cap.read(webcam_img)) {
			break;
		};
		imshow("Image", webcam_img);
		if (waitKey(5) >= 0) { // set to 20 to make it slower; also, break if a key is pressed
			break;
		}
	}

	destroyAllWindows();
}