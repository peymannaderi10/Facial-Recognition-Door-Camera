/*! \class lcdScreen
    \brief lcdScreen class used to communicate with the LCD screen via I2C.
    
    The lcdScreen uses wiringPi and wiringPiI2C to communicate with the LCD
    screen via the I2C communication protocol.  The member functions used
    are declared as private, however the Outputs class is declared as a 
    friend as the Outputs class should be the only class with access
    to these member functions.
    
    \author Peyman Naderi
*/

#ifndef LCDSCREEN
#define LCDSCREEN

#include <wiringPi.h>
#include <wiringPiI2C.h>

// Define some device parameters
#define I2C_ADDR   0x27 // I2C device address

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

#define LCD_BACKLIGHT   0x08  // On

#define ENABLE  0b00000100 // Enable bit

class lcdScreen
{
  friend class Outputs;

  private:

    /*! \fn lcdScreen()
    \brief Default constructor for the lcdScreen class.

    This is the default constructor for the lcdScreen class. It
    initializes the display so that it can be controlled via I2C.

    \author Brandon Altieri
    */

    lcdScreen();

    /*! \fn ~lcdScreen()
    \brief Default destructor for the lcdScreen class.

    This is the default destructor for the lcdScreen class. It
    does not need to do anything.

    \author Brandon Altieri
    */
    ~lcdScreen();

    /*! \fn void lcd_byte(int bits, int mode)
    \brief This function is used to send a byte of data to the LCD.

    This function is used to send a byte (8 bits) of data to the LCD
    screen through I2C.

    \param bits is the data to be sent
    \param mode is the mode of operation (mode = 1 for data, 0 for command)
    \author Brandon Altieri
    */
    void lcd_byte(int bits, int mode);

    /*! \fn void lcd_toggle_enable(int bits)
    \brief This function is used to toggle the enable pin.

    This function is used to flip the LCD's enable pin via I2C.

    \param bits is the data to be sent
    \author Brandon Altieri
    */
    void lcd_toggle_enable(int bits);

    /*! \fn void ClrLcd()
    \brief This function clears the LCD.

    This function is used to clear the LCD's screen via I2C.

    \author Brandon Altieri
    */
    void ClrLcd();

    /*! \fn void typeln(const char *s)
    \brief This function prints a string to the LCD.

    This function is used to print a string to the LCD's screen via I2C.

    \param s is the pointer to the first character of the string to be printed.
    \author Brandon Altieri
    */
    void typeln(const char *s);

    /*! \fn void lcdLoc(int line);
    \brief This function puts the LCD cursor at the specified line.

    This function is used to change the location of the cursor. The next time
    a print is done, it will print starting at the new cursor location.

    \param line is the line to move the cursor to (line 1 or line 2)
    \author Brandon Altieri
    */
    void lcdLoc(int line);
    
    int fd;
};

#endif
