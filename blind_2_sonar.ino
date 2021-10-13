#include <TimerFreeTone.h>

// Include NewPing Library
#include "NewPing.h"

// Maximum Distance is 400 cm

#define TRIGGER_PIN1  10
#define ECHO_PIN1     13
#define trig2         5
#define echo2         6
#define MAX_DISTANCE 400
#define TONE_PIN 9
 
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(trig2, echo2, MAX_DISTANCE);

float duration1, distance1;
float duration2, distance2;

void setup() {
  Serial.begin (9600);
}

void loop() {
   
  duration1 = sonar1.ping();
  duration2 = sonar2.ping();
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance1 = (duration1 / 2) * 0.0343;
  distance2 = (duration2 / 2) * 0.0343;
  
  // Send results to Serial Monitor #1
  Serial.print("Distance1 = ");
  if (distance1 >= 200 || distance1 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance1);
    Serial.println(" cm");
    TimerFreeTone(TONE_PIN,1000,250,10);
     delay(500);
     
  }
 
  // Send results to Serial Monitor #2
  Serial.print("Distance2 = ");
  if (distance2 >= 50 || distance2 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance2);
    Serial.println(" cm");
    TimerFreeTone(TONE_PIN,1000,8000,10);
    delay(500);
  }
  delay(500);
}
