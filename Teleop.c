#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     SonarSensor,    sensorSONAR)
#pragma config(Sensor, S3,     LightSensor,    sensorLightActive)
#pragma config(Sensor, S4,     Touch,          sensorTouch)
#pragma config(Motor,  motorA,          vacuumA,       tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          vacuumB,       tmotorNXT, openLoop, reversed)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftMotor,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightMotor,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//
// Teleop.c
//
// Main teleop program for FTC Team 7071, the EngiNerds.
//

#include "JoystickDriver.c"     // Tells ROBOTC to include the driver file for the joystick.
#include "./Functions.c"				// Shared functions between Auto & Teleop

//
// Starting point for the program.
//
task main()
{
	waitForStart();	// Wait for the field to enter teleop mode

	// Constants
	const int TURN_SPEED = 50;

	// Main loop
	while(true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks

		// Driving
		int turn = joystick.joy2_x2;
	  if (joy2Btn(7))
	  {
	  	turn = -TURN_SPEED;
	  }
	  else if (joy2Btn(8))
	  {
	  	turn = TURN_SPEED;
	  }

		ArcadeDrive(joystick.joy2_y1, turn);

		// Block Intake
		if (joy1Btn(2) == 1)	// if Button 1 is pressed on joy1:
		{
			motor[vacuumA] = 100;		// Turn Motor A On at full power
	    motor[vacuumB] = -100;  //  Turn Motor B on at full power reversed
		}
		else if (joy1Btn(3) == 1)    // if Button 1 is pressed on joy1:
		{
		  motor[vacuumA] = -100;	// Turn Motor A On at full power reversed
	    motor[vacuumB] = 100;   // Turn Motor B on at full power
  	}
	  else
	  {
  		motor[vacuumA] = 0;	// Turn Motor A Off
	    motor[vacuumB] = 0;	// Turn Motor B off
	  }
	}
}
