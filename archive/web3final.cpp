#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "unistd.h"


using namespace cv;
using namespace std;


int midpicx = 320;
int midpicy = 240;

int base = 10;
int mob = 10;




int main( int argc, char** argv )
 {

	FILE *commande = NULL;
	commande = fopen("/dev/ttyACM0","w");
	if (commande == NULL) {printf("erreur chargement fichier\n"); return 0;}

	while(mob<150 && base<150){
		printf("rentré dans la bouycle\n");
		
		mob++;
		base ++;
		printf("%d ;%d\n",mob,base);
		
	fprintf(commande,"%d,%d",base,mob);
	usleep(50000);
	}
	return 0;
   
	 VideoCapture cap(1); //capture the video from webcam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Canot open the web cam" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
// reglage balle de ping pong


 int iLowH = 0;
 int iHighH = 84;

 int iLowS = 0; 
 int iHighS = 255;

 int iLowV = 205;
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

 //Capture a temporary image from the camera
 Mat imgTmp;
 cap.read(imgTmp); 
	

 //Create a black image with the size as the camera output
 Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;
 

    while (true)
    {
        Mat imgOriginal;
			
		

	//cout << "Width : " << imgTmp.cols << endl; 640 
	//cout << "Height : " << imgTmp.rows << endl; 480
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video



         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

  Mat imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
 
  Mat imgThresholded;

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
      
  //morphological opening (removes small objects from the foreground)
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

  //morphological closing (removes small holes from the foreground)
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
   //calculate the position of the ball
   int posX = dM10 / dArea;
   int posY = dM01 / dArea;        

   if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
   {
    
   iLastX = posX;
   iLastY = posY;
	

  }

	



//cercle de tolérance
	circle(imgOriginal, Point(300,225), 40,CV_RGB(0,200,0),2,8,0);

  //commandes moteur
	//a mettre dans le if lorsqu'on rentre dans le cercle de tolérance
	
	/*if (posX-300>20){mob++;}
	if (posY-225>20){base++;}

	if (300-posX<20){mob--;}
	if (225-posY<20){base--;}
	
	fprintf(commande,"%d,%d",mob,base);


  //Affichage de l'image
  printf("posX : %d\n posY: %d\n",posX,posY);
  printf("mob == %d\n base = %d\n",mob,base);*/
  imshow("Thresholded Image", imgThresholded); //show the thresholded image

  imgOriginal = imgOriginal + imgLines;
  imshow("Original", imgOriginal); //show the original image

	//cout << "Width : " << imgTmp.cols << endl;
	//cout << "Height: " << imgTmp.rows << endl;


        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }

}

   return 0;
}
