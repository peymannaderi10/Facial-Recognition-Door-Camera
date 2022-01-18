#include <iostream>
#include <thread>
#include "Controller.h"
#include "ComputerVision.h"

/*! \fn void threadFunction()
    \brief Stream video using the ComputerVision class.

    This function is called from main() when a new thread is created. It
    creates a ComputerVision object, and calls the detectFaceinFootage()
    function so that the the system is always checking if there is a 
    person's face present.

    \author Peyman Naderi
*/
void threadFunction()
{
  ComputerVision cv;
  cv.detectFaceInFootage();
}

/*! \fn int main()
    \brief Main function to initialize the system.

    The main function initializes the system by using two threads. One
    thread is used to call the ComputerVision detectFaceInFootage() 
    member function. This function has a forever loop which constantly
    checks to see if a face is detected. If a face is detected, the owner
    of the door lock system is notified via email. The parent thread is
    used to constantly check if any of the input buttons have been pressed.
    The Controller checkInput() member function is used to do this. If a 
    button has been pressed, the Controller member in the main function
    will change the state of the system appropriately. Note that threading
    is necessary to allow the system to both see if a person is present (using
    the Computer Vision software) or see if a button has been pressed at
    any point while the system is running.

    \return 0
    \author Brandon Altieri
*/
int main() 
{
  Controller doorLock;

  // Create a thread to call the detectFaceInFootage() function
  std::thread webcam(threadFunction);


  // Create a forever loop to check if any of the buttons have been pressed
  while(true)
  {
    doorLock.checkInput();
  }

  // Join the threads
  webcam.join();

  return 0;
}
