# final_project
Joseph Cirksey and Siddhant Deka
Code submitted for rewview at 03/10/23

# Smart home sytem module:
This module intiliatses the user interface, temperature sensor and motor control.
The module also provides a system delay of 10 ms and continuously runs userInterfaceUpdate() and temperatureSensorUpdate() functions.

# Display module:
the LCD display module contains all the functions pertaining to intilising and dispalying characters on the LCD. 

# Motor module:
Contains functions for intialising the fan to off, turning the fan on and off. 

# Temperature sensor module:
This module takes care of reading the temperature and converting to celsius.

# User interface module:
The userInterfaceMatrixKeypadUpdate() function is used to interface the fans, matrix keypad,
LCD and the temperature sensor to achieve the intended behaviours for the system. 

The code is based on the textbook code. The code for the motor module is written from scratch. The code to clear a certain section of the LCD in the display
module was found online.

# Pin diagram image below
![Pin diagram](https://github.com/SidDeka/test_code/blob/master/Screenshot%202023-03-10%20200007.png)


# Tests performed:
In order to test the system to see if it behaves as intended, the following tests were conducted:
1. A temperature level higher than the current the temperature is entered
2. Temperature level lower than the current temperature is en
3. The Temperature is roughly the same (accurate to ± 1℃ as current temperature is displayed as a float while temperature entered is an integer) as current              temperature  
4. The character that is not a number is entered
5. If the user decides that they want to change the set threshold temperature

# Results of tests:
All sub functions/goals were tested with a minimum of one scenario, ensuring that the system behaves as intended in all cases. The tests cover all intended behaviours of the system, including entering temperatures higher/lower/same as the current temperature, inputting non-numeric characters, and inputting a new temperature threshold.

Therefore, based on the tests conducted, the system appears to be functioning correctly and reliably for all intended behaviours.

Overall the system meets the ventilation required to move air back and forth fast enough to replace the air in the enclosed room with the air from outside. This result shows the effect that it has on the temperature by displaying the change in temperature. However below is a table of what went well and what didn’t go well.
