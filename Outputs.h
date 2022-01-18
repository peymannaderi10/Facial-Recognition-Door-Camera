/*! \class Outputs
    \brief Outputs class used to control the output hardware.
    
    The Outputs class initializes all output hardware as outputs, and
    physically changes the state of the system. Also, the alarm can be set
    off using the alarm() member function. The hardware controlled by this
    class includes red and green LEDs, a solenoid (the door lock), and
    a piezo electric buzzer (alarm). The member functions used
    are declared as private, however the Controller class is declared as a 
    friend as the Controller class should be the only class with access
    to these member functions.

    \author Peyman Naderi
*/

#ifndef OUTPUTS
#define OUTPUTS

#include "lcdScreen.h"

#define GREEN_LED 0
#define RED_LED 21
#define SOLENOID 2
#define BUZZER 25

class Outputs
{
  friend class Controller;

 private:

    /*! \fn Outputs()
    \brief Default constructor for the Outputs class.

    This is the default constructor for the Outputs class. It sets
    all output pins used as outputs and unlocks the system.

    \author Syed Abdullah Tufail
    */
    Outputs();

    /*! \fn ~Outputs()
    \brief Default destructor for the Outputs class.

    This is the default destructor for the Outputs class. It unlocks the
    system.

    \author Syed Abdullah Tufail
    */
    ~Outputs();

    /*! \fn void doorLock()
    \brief This function sets all the hardware to the locked state.

    This function sets all the hardware to the locked state. Specifically,
    the green LED is turned off, the red LED is turned on, and the solenoid
    is turned on. The message on the LCD is changed to show that the system
    is locked.

    \author Syed Abdullah Tufail
    */
    void doorLock();

    /*! \fn void doorUnlock()
    \brief This function sets all the hardware to the unlocked state.

    This function sets all the hardware to the unlocked state. Specifically,
    the green LED is turned on, the red LED is turned off, and the solenoid
    is turned off. The message on the LCD is changed to show that the system
    is unlocked.

    \author Syed Abdullah Tufail
    */
    void doorUnlock();

    /*! \fn void alarm()
    \brief This function sets off the alarm.

    This function set off the piezo electric buzzer (alarm). The
    buzzer is turned on and off repeatedly to simulate an alarm.

    \author Syed Abdullah Tufail
    */
    void alarm();

    lcdScreen lcd;
};

#endif
