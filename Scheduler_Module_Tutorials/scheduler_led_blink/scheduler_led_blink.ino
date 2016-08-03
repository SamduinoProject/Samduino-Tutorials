#include "SchedulerModule.h"  //we must include the scheduler module to use it!

int ledPin = 18;  //led will be attached to pin 18
bool ledState = false; //variable to hold the state of the led
int blinkIntervalMs = 1000;  // one second on/off interval in milliseconds
int timesToRun = 0;  //set the number of times to run.  0 means infinite!

//this is our toggle led function to be scheduled
void toggleLed() 
{
   ledState = !ledState; //change the LED state
   digitalWrite(ledPin, ledState); //write the new led state to the led pin
}

void setup() 
{
  pinMode(ledPin, OUTPUT);  //set the LED pin as an output so we can control the led
  digitalWrite(ledPin, LOW);  //start the led as off
  //schedule the task in the scheduler module
  SchedulerMillis.schedule(toggleLed, blinkIntervalMs, timesToRun, SCHEDULER_LOW_PRIORITY);  
}

void loop() 
{
  //nothing to do in loop because the scheduler handles everything!
}
