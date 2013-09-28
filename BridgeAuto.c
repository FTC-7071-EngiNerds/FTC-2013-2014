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
// BridgeAuto.c
//
// Drive up the bridge and park using line following
//

#include "JoystickDriver.c"  // Include file to "handle" the Bluetooth messages.
#include "./Functions.c"

task main()
{
  waitForStart();		// Wait for the field to enter autonomous mode

  // Constants
  const int LINE_FOLLOWING_DURATION = 3000;	// ms
  const int TARGET_VALUE = 53;
  const int KP = 1;

  // Drive up the bridge; proportional line follower
  time1[T1] = 0;
  while (time1[T1] < LINE_FOLLOWING_DURATION)
  {
	 	int lightValue = SensorValue[LightSensor];
	 	int error = TARGET_VALUE - lightValue;
	 	int turn = error * KP;

	 	ArcadeDrive(-50, turn);
  }

  // Stop
  ArcadeDrive(0, 0);
}
