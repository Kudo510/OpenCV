#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Face Detection  //////////////////////

int main() {
    // Path to image
    string img_path{ "Resources\\test.png" };
    Mat img = imread(img_path);

    // Check if image is loaded
    if (img.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // Load the Haar cascade file for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("Resources/haarcascade_frontalface_default.xml")) {
        cout << "Error loading Haar cascade file" << endl;
        return -1;
    }

    // Detect faces
    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    // Draw rectangles around the detected faces
    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
    }

    // Show the result
    imshow("Image", img);
    waitKey(0);

    return 0;
}
