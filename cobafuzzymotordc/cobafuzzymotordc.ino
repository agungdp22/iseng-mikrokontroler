/*
Agung Dwi Prasetyo
G64130073
*/
//for this code you need to install the NewPing libraries to your arduino software
const int Motor1Pin1 = 9;
const int Motor1Pin2 = 8;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;
int motor1PWM = 5;
int motor2PWM = 6;
 
int brightness = 0;
int fadeAmount = 5;  


void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
}

void loop()
{
  moveForward();
  
  analogWrite(motor2PWM, brightness);
  analogWrite(motor1PWM, 255-brightness);
  brightness = brightness + fadeAmount;

 if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  Serial.print(brightness);
  Serial.print("\t");
  Serial.println(255-brightness);
  delay(100);
}

void moveForward(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}
