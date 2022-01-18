#include "Outputs.h"

Outputs::Outputs()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(SOLENOID, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  doorUnlock();
}

Outputs::~Outputs()
{
  doorUnlock();
}

void Outputs::doorLock()
{
  digitalWrite(GREEN_LED, 0);
  digitalWrite(RED_LED, 1);
  digitalWrite(SOLENOID, 1);
  lcd.lcdLoc(0x80); //line 1
  lcd.ClrLcd();
  lcd.typeln("Door is Locked");
}

void Outputs::doorUnlock()
{
  digitalWrite(GREEN_LED, 1);
  digitalWrite(RED_LED, 0);
  digitalWrite(SOLENOID, 0);
  lcd.ClrLcd();
  lcd.typeln("Door is Unlocked");
}

void Outputs::alarm()
{
  digitalWrite(BUZZER, 1);
  delay(1000);
  digitalWrite(BUZZER, 0);
  delay(500);
  digitalWrite(BUZZER, 1);
  delay(1000);
  digitalWrite(BUZZER, 0);
  delay(500);
  digitalWrite(BUZZER, 1);
  delay(1000);
  digitalWrite(BUZZER, 0);
}
