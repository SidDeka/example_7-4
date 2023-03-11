# final_project
Joseph Cirksey and Siddhant Deka
Code submitted for rewview at 03/10/23

#Smart home ssytem module:
This module intiliatses the user interface, temperature sensor and motor control.
The module also provides a system delay of 10 ms and continuously runs userInterfaceUpdate() and temperatureSensorUpdate() functions.

#Display module:
the LCD display module contains all the functions pertaining to intilising and dispalying characters on the LCD. 

#Motor module:
Contains functions for intialising the fan to off, turning the fan on and off. 

#Temperature sensor module:
This module takes care of reading the temperature and converting to celsius.

#User interface module:
The userInterfaceMatrixKeypadUpdate() function is used to interface the fans, matrix keypad,
LCD and the temperature sensor to achieve the intended behaviours for the system. 

The code is based on the textbook code. The code for the motor module is written from scratch. The code to clear a certain section of the LCD in the display
module was found online.

![Pin diagram](https://github.com/SidDeka/test_code/blob/master/Screenshot%202023-03-10%20200007.png)
