//for this code you need to install the NewPing libraries to your arduino software
#include <NewPing.h>  
#include <Servo.h>

#define TRIGGER_PIN  3  
#define ECHO_PIN   2   
#define MAX_DISTANCE 100


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int time;         
int distance;              
int triggerDistance = 30;
Servo servo1;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
}

void loop()
{
  scan();        
  Serial.println(distance);
  if(distance>50){
    servo1.write(0);
  }
  else{
    servo1.write(180);
  }
  delay(200);
}

void scan(){
  time = sonar.ping();               
  distance = time / US_ROUNDTRIP_CM;   
  if(distance == 0){                 
  distance = 100;                  
  }
  delay(10);
}
