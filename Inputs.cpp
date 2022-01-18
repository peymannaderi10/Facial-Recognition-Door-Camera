#include "Inputs.h"

Inputs::Inputs()
{
  wiringPiSetup();

  // Declare the CHANGE_STATE button as an input
  pinMode(CHANGE_STATE, INPUT);

  // Call the pulldown resistor for this pin
  pullUpDnControl(CHANGE_STATE, PUD_DOWN);

  // Declare the SET_OFF_ALARM button as an input
  pinMode(SET_OFF_ALARM, INPUT);

  // Call the pulldown resistor for this pin
  pullUpDnControl(SET_OFF_ALARM, PUD_DOWN);
}

Inputs::~Inputs()
{

}

bool Inputs::changeState()
{
  bool changeState = false;

  /* While loop to only exit the function when
  the button has been released */
  while (digitalRead(CHANGE_STATE) == 1)
  {
    delay(0.5); // Delay for half a second
    changeState = true;
  }
  
  return changeState;
}

bool Inputs::setOffAlarm()
{
  bool alarm = false;

  /* While loop to only exit the function when
  the button has been released */
  while (digitalRead(SET_OFF_ALARM) == 1)
  {
    delay(0.5); // Delay for half a second
    alarm = true;
  }
  
  return alarm;
}
