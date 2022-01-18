/*! \class Inputs
    \brief Inputs class used to read the state of the buttons.
    
    The Inputs class initializes the buttons as inputs using wiringPi and
    monitors their status (pressed or unpressed). The member functions used
    are declared as private, however the Controller class is declared as a 
    friend as the Controller class should be the only class with access
    to these member functions.

    \author Peyman Naderi
*/

#ifndef INPUTS
#define INPUTS

#include <wiringPi.h>

#define CHANGE_STATE 22
#define SET_OFF_ALARM 26

class Inputs
{
  friend class Controller;

  private:

    /*! \fn Inputs()
    \brief Default constructor for the Inputs class.

    This is the default constructor for the Inputs class. It sets
    the two button pins used as inputs and initalizes pull-down 
    resistors for these pins.

    \author Peyman Naderi
    */
    Inputs();

    /*! \fn ~Inputs()
    \brief Default destructor for the Inputs class.

    This is the default destructor for the Inputs class. It does
    not need to do anything.

    \author Peyman Naderi
    */
    ~Inputs();
  
  /*! \fn bool changeState()
    \brief This function is used to read the state of the changeState button.

    This function reads the state of the changeState button. If if has been
    pressed, the function waits until the button has been released, and 
    returns true. If it has not been pressed, it returns false.

    \return Boolean true if button has been pressed, false otherwise
    \author Peyman Naderi
    */
    bool changeState();

    /*! \fn bool setOffAlarm()
    \brief This function is used to read the state of the alarm button.

    This function reads the state of the alarm button. If if has been
    pressed, the function waits until the button has been released, and 
    returns true. If it has not been pressed, it returns false.

    \return Boolean True if button has been pressed, false otherwise
    \author Peyman Naderi
    */
    bool setOffAlarm();
};

#endif
