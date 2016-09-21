//for this code you need to install the NewPing libraries to your arduino software
#include <NewPing.h>  

#define TRIGGER_PIN  3  
#define ECHO_PIN   2   
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int time;         
int distance;    
int count = 0; 
int led = 8;         
int triggerDistance = 30;

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop()
{
  scan();
  if(distance<30){
    count++;
  }
  else count=0;
  if(count>15){
    digitalWrite(led,HIGH);
  }
  else digitalWrite(led,LOW);
  Serial.print(count);
  Serial.print("\t");
  Serial.println(distance);
  delay(100);
}

void scan(){
  time = sonar.ping();               
  distance = time / US_ROUNDTRIP_CM;   
  if(distance == 0){                 
    distance = 100;                  
  }
  delay(10);
}
