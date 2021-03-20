#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char** argv)
{
	VideoCapture cap;
	
	if(!cap.open(0))
	return 0;

	while(1)
	{
	  Mat frame;
	  cap >> frame;
	  if( frame.empty() ) break; // end of video stream
	  imshow("Webcam", frame);
	  if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
	}
	// the camera will be closed automatically upon exit
	// cap.close();
	return 0;
}
