#include "SchedulerModule.h"  //we must include the scheduler module to use it!

int ledPin = 18;  //led will be attached to pin 18
bool ledState = false; //variable to hold the state of the led
int ledOnTimeMs = 50; //time in milliseconds the led should be on
int ledOffTimeMs = 450;  //time in milliseconds the led should be off

void turnLedOff();  //prototype function definition so we can call the Led off

void turnLedOn()
{
  digitalWrite(ledPin, HIGH);
  SchedulerMillis.schedule(turnLedOff, ledOnTimeMs, 1, SCHEDULER_LOW_PRIORITY);
}

void turnLedOff()
{
  digitalWrite(ledPin, LOW);
  SchedulerMillis.schedule(turnLedOn, ledOffTimeMs, 1, SCHEDULER_LOW_PRIORITY);
}

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
  SchedulerMillis.schedule(turnLedOn, ledOnTimeMs, 1, SCHEDULER_LOW_PRIORITY);  
}

void loop() 
{
  //nothing to do in loop because the scheduler handles everything!
}
