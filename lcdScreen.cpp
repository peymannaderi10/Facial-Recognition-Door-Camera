#include "lcdScreen.h"

lcdScreen::lcdScreen()
{
  fd = wiringPiI2CSetup(I2C_ADDR);
  // Initialise display
  lcd_byte(0x33, LCD_CMD); // Initialise
  lcd_byte(0x32, LCD_CMD); // Initialise
  lcd_byte(0x06, LCD_CMD); // Cursor move direction
  lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
  lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
  lcd_byte(0x01, LCD_CMD); // Clear display
  delayMicroseconds(500);
}

lcdScreen::~lcdScreen()
{
 
}

void lcdScreen::lcd_byte(int bits, int mode)
{
  int bits_high;
  int bits_low;

  // uses the two half byte writes to LCD
  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;

  // High bits
  wiringPiI2CReadReg8(fd, bits_high);
  lcd_toggle_enable(bits_high);

  // Low bits
  wiringPiI2CReadReg8(fd, bits_low);
  lcd_toggle_enable(bits_low);
}

void lcdScreen::lcd_toggle_enable(int bits)
{
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
  delayMicroseconds(500);
}

void lcdScreen::ClrLcd(void)
{
  lcd_byte(0x01, LCD_CMD);
  lcd_byte(0x02, LCD_CMD);
}

void lcdScreen::typeln(const char *s)
{

  while ( *s ) lcd_byte(*(s++), LCD_CHR);

}

void lcdScreen::lcdLoc(int line)
{
  lcd_byte(line, LCD_CMD);
}
