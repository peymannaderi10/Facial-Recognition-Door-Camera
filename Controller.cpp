#include "Controller.h"
#include <iostream>

Controller::Controller()
{
   wiringPiSetup();
    isDoorLocked = false;
}

Controller::~Controller()
{
  doorOutput.doorUnlock();
  isDoorLocked = false;
}

void Controller::checkInput()
{
  bool change = userInput.changeState();
  
  if (change == true)
  {
    changeState();
  }

  bool alarm = userInput.setOffAlarm();
  if (alarm == true)
  {
    ringAlarm();
  }

}

void Controller::changeState()
{
  if (isDoorLocked == true)
  {
    doorOutput.doorUnlock();
  }

  else
  {
    doorOutput.doorLock();
  }
  
  // Flip the state of the isDoorLocked boolean member
  isDoorLocked = !isDoorLocked;
}

void Controller::ringAlarm()
{
  doorOutput.alarm();
}
