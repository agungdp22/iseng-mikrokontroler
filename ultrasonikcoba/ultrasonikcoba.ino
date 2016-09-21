//for this code you need to install the NewPing libraries to your arduino software
#include <NewPing.h>
#include <Servo.h>  

#define TRIGGER_PIN  3  
#define ECHO_PIN 	2   
#define MAX_DISTANCE 100

const int Motor1Pin1 = 9;
const int Motor1Pin2 = 8;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;
int pwm1 = 5;
int pwm2 = 6;
Servo servo1;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int time;       	 
int distance;            	 
int triggerDistance = 20;    
int fDistance;           	 
int lDistance;
int rDistance;
int pos = 90;


void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  analogWrite(pwm1,245);
  analogWrite(pwm2,255);
  servo1.attach(7);
}

void loop()
{       
      for(pos=65;pos<=115;pos+=5){
        servo1.write(pos);
        scan(); 
        if(distance < triggerDistance){   
          moveBackward();
          delay(200);  
          parkir();
        }
        else if(distance >= triggerDistance) {
          moveForward();                   
        }              
        delay(15); 
      }
      for(pos=115;pos>=65;pos-=5){
        servo1.write(pos);
        scan(); 
        Serial.println(distance);
        if(distance < triggerDistance){ 
          moveBackward();
          delay(200);   
          parkir();
        }
        else if(distance >= triggerDistance) {
          moveForward();                   
        }              
        delay(15); 
      }      	 
      
}

void scan(){
  time = sonar.ping();             	 
  distance = time / US_ROUNDTRIP_CM;   
  if(distance == 0){               	 
	  distance = 100;                	 
  }
  delay(10);
}

void parkir(){
  moveBackward();                   
  delay(200);
  moveStop();
  for(pos = 90; pos >= 30; pos -= 5){ 
    servo1.write(pos);              
    delay(15);                       
  }                                            
  scan();                          
  rDistance = distance;  
  delay(100);             
  for(pos = 30; pos <= 150; pos += 5){ 
    servo1.write(pos);              
    delay(15);                       
  }                
  scan();                          
  lDistance = distance;
  delay(100);
  for(pos = 150; pos >=90 ; pos -= 5){ 
    servo1.write(pos);          
    delay(15);                      
  }            
  if(lDistance < rDistance){         
    moveRight();           
    delay(500);
    moveForward();                 
  }
  else{
    moveLeft();                  
    delay(500);
    moveForward();                 
  }
}

void moveBackward(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveForward(){
  digitalWrite(Motor1Pin1, 200);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveRight(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveLeft(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveStop(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
