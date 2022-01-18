#include "ComputerVision.h"

using namespace cv;
using namespace std;

ComputerVision::ComputerVision()
{
    // My file path to the face detection model known as Haar cascade.
    // This file path may vary depending on your operating system configuration.
    this->face_detection_model_filepath = "/home/pi/opencv/samples/winrt/FaceDetection/FaceDetection/Assets/haarcascade_frontalface_alt.xml";
    
    // Allows us to scale down the webcam frame so that
    // it is smaller and easier to work with.
    this->scale = 2.0;
    
    // Also, set the colour of the rectangle that will
    // appear around the detected face.
    this->rectangle_colour = Scalar(0, 255, 0);
}

ComputerVision::~ComputerVision()
{
    //Nothing needs to be done in the destructor
}

void ComputerVision::detectFaceInFootage() 
{
    const int ESCAPE_KEY = 27;
    const int RECTANGLE_THICKNESS = 4;
    
    // CascadeClassifier performs detection.
    CascadeClassifier face_detection_cascade;
    
    // Load the pre-trained model into the classifier.
    face_detection_cascade.load(this->face_detection_model_filepath);
    
    //Start capturing video
    VideoCapture capture(0);

    // An infinite loop that retrieves frames from the webcam.
    while (true) 
    {
        Mat current_frame;
        capture >> current_frame;
        
        // grayscale_matrix stores the grayscale frame.
        // This is because certain facial detection algorithms only work on grayscale images.
        Mat grayscale_matrix;
        cvtColor(current_frame, grayscale_matrix, COLOR_BGR2GRAY);
        
        // Scale down the width and height to make the algorithm more efficient.
        int scaled_width = grayscale_matrix.size().width / this->scale;
        int scaled_height = grayscale_matrix.size().height / this->scale;
        resize(grayscale_matrix, grayscale_matrix, Size(scaled_width, scaled_height));
        face_detection_cascade.detectMultiScale(grayscale_matrix, this->faces, 1.1, 3, 0, Size(20, 20));
        
        for (Rect face_area : this->faces)
        {
            this->currently_detected_face = face_area;
            rectangle(current_frame, Point(cvRound(face_area.x * this->scale), cvRound(face_area.y * this->scale)), Point(cvRound((face_area.x + face_area.width - 1) * this->scale), cvRound((face_area.y + face_area.height - 1) * this->scale)), this->rectangle_colour, RECTANGLE_THICKNESS);
        }
        
        // Update stream with current frame
        imshow("Current frame in webcam:", current_frame);

        // If a face is detected, notify the user via email
        if (this->faces.size() != 0) 
        {
            system(R"(echo -e "Subject: Doorlock Notification\r\n\r\nSomeone is at the door!" |msmtp --debug --from=default -t altieribrandon@gmail.com)");
            this_thread::sleep_for(chrono::seconds(30));
        }
        
        if (waitKey(10) == ESCAPE_KEY)
        {
                break;
        }
    }
    
    // Destroy display window and stop webcam video.
    destroyAllWindows();
    capture.release();
}
