/*! \class Controller
    \brief Controller class used to control the hardware Inputs and Outputs.
    
    The Controller class controls the physical state of the door by storing
    the current state of the system (locked or unlocked) and calling the appropriate
    methods of both the Inputs and Outputs classes. 

    \author Peyman Naderi
*/

#ifndef CONTROLLER
#define CONTROLLER

#include "Inputs.h"
#include "Outputs.h"

class Controller
{
  public:

  /*! \fn Controller()
    \brief Default constructor for the Controller class.

    This is the default constructor for the Controller class. It sets
    the boolean value used to store the state of the system as false
    (unlocked).

    \author Muhammed Askri
    */
    Controller();

    /*! \fn ~Controller()
    \brief Default destructor for the Controller class.

    This is the default destructor for the Controller class. It unlocks
    the door.

    \author Muhammed Askri
    */
    ~Controller();

    /*! \fn void checkInput()
    \brief Checks for inputs from the Input class.

    The checkInput() function checks if either the changeState 
    or alarm buttons have been pressed, and calls the appropriate
    function if either button has been pressed. The Inputs changeState()
    and setOffAlarm() member functions are used to check if either
    button has been pressed using the private Input member.

    \author Muhammed Askri
    */
    void checkInput();
    

  private:
    Inputs userInput;
    Outputs doorOutput;
    bool isDoorLocked;

    /*! \fn void changeState()
    \brief Calls the changeState() method in the Outputs class.

    The changeState() function calls the Output changeState() method using the
    private Outputs member.

    \author Muhammed Askri
    */
    void changeState();

    /*! \fn void ringAlarm()
    \brief Calls the alarm() method in the Output class.

    The ringAlarm() function calls the Outputs alarm() method using the
    private Outputs member.

    \author Muhammed Askri
    */
    void ringAlarm();
};

#endif
