#include <IRremote.h>

#define trigger 3
#define echo A0

int RECV_PIN = 7;
const int Motor1Pin1 = 9;
const int Motor1Pin2 = 8;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;
int motor1PWM = 5;
int motor2PWM = 6;
int i;
double durasi, jarak;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(Motor1Pin1,OUTPUT);
  pinMode(Motor1Pin2,OUTPUT);
  pinMode(Motor2Pin1,OUTPUT);
  pinMode(Motor2Pin2,OUTPUT);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
}

void loop() {
  scan();
  //Serial.println(jarak);
  /*
  if(jarak < 23){
    for(i=255;i>=0;i-=35){
      analogWrite(motor1PWM,i);
      analogWrite(motor2PWM,i);
      delay(50);
    }
    while(jarak < 20){
      scan();
      analogWrite(motor1PWM, 200);
      analogWrite(motor2PWM, 200);
      mundur();
      delay(100);
    }
    berhenti();
  }
  */
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if((results.value == 0x597E247B) || (results.value == 0x2FD42BD)){
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      kiri();
    }
    else if(results.value == 0xBDFF627F || (results.value == 0x2FD9867)){
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      maju();
    }
    else if(results.value == 0xFE9F719F || (results.value == 0x2FD02FD)){
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      kanan();
    }
    else if(results.value == 0xFF4AB5 || (results.value == 0x1BC0157B)){
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      mundur();
    }
    else if(results.value == 0x2FD847B || (results.value == 0xFCABFFBF)){
      analogWrite(motor1PWM,0);
      analogWrite(motor2PWM,0);
      berhenti();
    }
    else if(results.value == 0xFF7A85 || (results.value == 0x6182021B)){
      analogWrite(motor1PWM,160);
      analogWrite(motor2PWM,255);
      maju();
    }
    else if(results.value == 0xFF30CF || (results.value == 0x9716BE3F)){
      analogWrite(motor2PWM,160);
      analogWrite(motor1PWM,255);
      maju();
    }
    else if(results.value == 0xC8F3BB43 || (results.value == 0x2FDB847)){
      analogWrite(motor2PWM,160);
      analogWrite(motor1PWM,255);
      mundur();
    }
    else if(results.value == 0xFF52AD || (results.value == 0x3EC3FC1B)){
      analogWrite(motor1PWM,160);
      analogWrite(motor2PWM,255);
      mundur();
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void scan(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger,LOW);
  durasi = pulseIn(echo,HIGH);
  jarak = durasi/29/2;
}

void mundur(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void maju(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void kanan(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void kiri(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void berhenti(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
