//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"
#include <cctype>

#include "smart_home_system.h"
#include "temperature_sensor.h"
#include "matrix_keypad.h"
#include "display.h"
#include "motor.h"


//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================
char pressed[2];


//=====[Declaration and initialization of public global variables]=============



//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceMatrixKeypadUpdate();
static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static bool isNumber(char str);


//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{

    userInterfaceDisplayUpdate();
    userInterfaceMatrixKeypadUpdate();
}


//=====[Implementations of private functions]==================================

static void userInterfaceMatrixKeypadUpdate()
{
    char keyReleased = matrixKeypadUpdate();

    static int refresh_time = 0; //this counter keeps track of the time to continue showing the numbers entered before clearing the display
    static int pos_x = 10;
    static int pressed_pos = 0;
    static int num_pressed = 0; //keeps count of number of times keys were pressed
    static int temp_threshold = 0;

    float current_temp = temperatureSensorReadCelsius();

    
    //refresh_time+= SYSTEM_TIME_INCREMENT_MS;

    if(num_pressed >=2)
    {
        if(num_pressed == 3)
        {
            clearDisplayRange(1, 10, 1, 15); 
        }

         refresh_time+= SYSTEM_TIME_INCREMENT_MS;

        if(refresh_time >= DISPLAY_REFRESH_TIME_MS)
        {
            clearDisplayRange(1, 10, 1, 15); 
            pos_x = 10;
            pressed_pos = 0 ;
            num_pressed = 0;
            refresh_time = 0;
        }
    }

           
       if(temp_threshold >= current_temp)
       {
           fan_off();
           temp_threshold = 0;
       }
 
  
    if( keyReleased != '\0' ) 
    {

        pressed[2] = '\0';
        pressed[pressed_pos] = keyReleased;
        pressed_pos++;
  

        displayCharPositionWrite (pos_x, 1 );
        char str3[2];
        str3[0] = keyReleased;
        str3[1] = '\0';
        displayStringWrite(str3);
     
  
      

     

        pos_x++;

        num_pressed++;

        if(num_pressed >= 2)
        {  
            int digit1 = pressed[0] - '0';
            int digit2 = pressed[1] - '0'; // convert second character to integer
            temp_threshold = digit1 * 10 + digit2;

            if(temp_threshold < current_temp)
            {
                fan_on();
            }
        }

    


                }
            }
        
 


static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
 

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Temp:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Entr Temp:" );


 }

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char temperatureString[5] = "";
  
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        sprintf(temperatureString, "%.2f", temperatureSensorReadCelsius());
        displayCharPositionWrite ( 5,0 );
        displayStringWrite( temperatureString );

    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}

static bool isNumber(char str){

    bool num = true;

     if (!isdigit(str)) {
            num = false;
     }

     return num;
}

