//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "smart_home_system.h"
#include "user_interface.h"
#include "temperature_sensor.h"
#include "motor.h"




void smartHomeSystemInit()
{
    userInterfaceInit();
    temperatureSensorInit();
    motorControlInit();

}

void smartHomeSystemUpdate()
{
    userInterfaceUpdate();
    temperatureSensorUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
