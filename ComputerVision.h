/*! \class ComputerVision
    \brief ComputerVision class used to detect faces.
    
    The ComputerVision class streams the video taken from the Raspberry
    Pi's webcam. The detectFaceinFootage method streams the video and
    sends an email to notify the user whenever a face is detected.

    \author Peyman Naderi
*/

#ifndef COMPUTER_VISION_H
#define COMPUTER_VISION_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class ComputerVision 
{
  public:
  /*! \fn ComputerVision()
    \brief Default constructor for the ComputerVision class.

    This is the default constructor for the ComputerVision class. It
    sets the path to the facial detection model, the scale for the webcam
    frames, and the colour of the rectangle that is drawn around a 
    detected face.

    \author Nikita Vladimirovich Nemtcev
    */
    ComputerVision();

    /*! \fn ~ComputerVision()
    \brief Default destructor for the ComputerVision class.

    This is the default destructor for the ComputerVision class. It
    does not need to do anything.

    \author Nikita Vladimirovich Nemtcev
    */
    ~ComputerVision();

    /*! \fn void detectFaceInFootage()
    \brief Streams webcam footage and detects if theres a face in the frame.
 
    The detectFaceInFootage() function streams the video captured by the Pi's
    webcam and detects when there is a face in the frame. When a face is detected,
    an email is sent to notify the user. The function then delays for 30 seconds
    so that emails are not sent indefinitely until the person in front of the webcam
    moves.

    \author Nikita Vladimirovich Nemtcev
    */
    void detectFaceInFootage();

  private:
    cv::Rect currently_detected_face;
    std::string face_detection_model_filepath;
    double scale;
    std::vector<cv::Rect> faces;
    cv::Scalar rectangle_colour;
};

#endif
