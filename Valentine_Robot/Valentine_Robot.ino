/*
  Valentine Robot
 
  Whistles, raises eyebrows up and down and flashes eyes on and off
*/

#include <Servo.h> 

#define WHISTLE_PIN             9       
#define EYEBROWS_PIN            10
#define EYES_PIN                7

#define WHISTLE_TOP_FREQ_A      2000         
#define WHISTLE_BOTTOM_FREQ_A   1200     
#define WHISTLE_TOP_FREQ_B      1800       
#define WHISTLE_BOTTOM_FREQ_B   1100

#define EYEBROWS_UP             65     // Servo degrees; 90deg is center      
#define EYEBROWS_DOWN           95    // Servo degrees; 90deg is center

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
void setup() 
{
  initEyebrows();
  initEyes();
  
  raiseEyebrows();
  lowerEyebrows();
  raiseEyebrows();
  lowerEyebrows();
  
  whistle();
  
  turnOnEyes();
  turnOffEyes();
  turnOnEyes();
  turnOffEyes();  
  turnOnEyes();
  turnOffEyes();
  turnOnEyes();
  turnOffEyes();
}

void loop() 
{
  // Empty; there is no loop function
}

void whistle(void)
{
  unsigned int loop_count;
  
  for(loop_count = WHISTLE_BOTTOM_FREQ_A; loop_count < WHISTLE_TOP_FREQ_A; loop_count += 10)
  {
    // play the pitch:
    tone(WHISTLE_PIN, loop_count);
    delay(4);
  }
  
  noTone(WHISTLE_PIN);
  delay(150);

  for(loop_count = WHISTLE_BOTTOM_FREQ_B; loop_count < WHISTLE_TOP_FREQ_B; loop_count += 10)
  {
    // play the pitch:
    tone(WHISTLE_PIN, loop_count);
    delay(2);
  }

  for(loop_count; loop_count > WHISTLE_BOTTOM_FREQ_B; loop_count -= 10)
  {
    // play the pitch:
    tone(WHISTLE_PIN, loop_count);
    delay(2);
  }
  
  delay(20);
  
  noTone(WHISTLE_PIN);
}


void initEyebrows(void)
{
  myservo.attach(EYEBROWS_PIN);      // attaches the servo on pin 9 to the servo object 
}


void raiseEyebrows(void)
{
  myservo.write(EYEBROWS_UP);        // Put eyebrows in "up" position 
  delay(200);                        // Waits 200ms  
}


void lowerEyebrows(void)
{
  myservo.write(EYEBROWS_DOWN);      // Put eyebrows in "down" position 
  delay(200);                        // Waits 200ms  
}


void initEyes(void)
{
  pinMode(EYES_PIN, OUTPUT);
  turnOffEyes();                     // Turn eyes off 
}


void turnOnEyes(void)
{
  digitalWrite(EYES_PIN, LOW);       // Turn eyes on 
  delay(125);                        // Waits 125ms  
}


void turnOffEyes(void)
{
  digitalWrite(EYES_PIN, HIGH);      // Turn eyes off 
  delay(125);                        // Waits 125ms  
}

