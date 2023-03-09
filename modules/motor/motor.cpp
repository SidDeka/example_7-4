//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor.h"

//=====[Declaration of private defines]========================================

#define MOTOR_UPDATE_TIME 9

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut motorM1Pin(PF_2);
DigitalOut motorM2Pin(PE_3);



void motorControlInit()
{
    motorM1Pin = OFF;
    motorM2Pin = OFF;
}


void fan_on(){
    motorM1Pin = OFF;
    motorM2Pin = ON;
}

void fan_off(){
    motorM1Pin = OFF;
    motorM2Pin = OFF;
}

//=====[Implementations of private functions]==================================
