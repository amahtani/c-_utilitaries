#include <iostream>
#include <sstream>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); //capture the video from webcam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"


//couleur à définir, actuellement sur jaune tendant vers le vert
 int iLowH = 4;
 int iHighH = 100;

 int iLowS = 0; 
 int iHighS = 255;

 int iLowV = 153;
 int iHighV = 255;

 //Create trackbars in "Control" window
 createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
 createTrackbar("HighH", "Control", &iHighH, 179);

 createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
 createTrackbar("HighS", "Control", &iHighS, 255);

 createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
 createTrackbar("HighV", "Control", &iHighV, 255);

 int iLastX = -1; 
 int iLastY = -1;

//img temporaire
 Mat imgTmp;
 cap.read(imgTmp); 

//crée une image en noir vide pour les lignes
 Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;
 
//crée une image

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

  Mat imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
 
  Mat imgThresholded; //image noir et blanc

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV, 255), Scalar(iHighH, iHighS, iHighV, 255), imgThresholded); //Threshold the image
 
  
  //morphological opening (remove small objects from the foreground)
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

  //morphological closing (fill small holes in the foreground)
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 
 
 //Calculate the moments of the thresholded image
  Moments oMoments = moments(imgThresholded);

  double dM01 = oMoments.m01;
  double dM10 = oMoments.m10;
  double dArea = oMoments.m00;

  // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
  if (dArea > 10000)
  {
   //position de l'objet
   int posX = dM10 / dArea;
   int posY = dM01 / dArea;

   printf("position(%d,%d)\n",posX,posY);     
   if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
   {
    //trace une ligne
    //line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
   
   //il faut effacer les cercles precedents
   
   //trace un cercle
   //circle(imgLines, Point(posX, posY), 100, Scalar(255,255,255), 5, 8, 0);
	
   
   }
   iLastX = posX;
   iLastY = posY;
  }
      
 
	 
  imshow("Thresholded Image", imgThresholded); //image noir et blanc
  
  imgOriginal = imgOriginal + imgLines;
  imshow("Original", imgOriginal); //image de la webcam avec les lignes
  //imgLines.release();  //effface les cercles
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }
	
	
	 
   return 0;

}
