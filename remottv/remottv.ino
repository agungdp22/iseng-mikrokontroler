#include <IRremote.h>


int RECV_PIN = 7;
const int Motor1Pin1 = 9;
const int Motor1Pin2 = 8;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;
int motor1PWM = 5;
int motor2PWM = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(Motor1Pin1,OUTPUT);
  pinMode(Motor1Pin2,OUTPUT);
  pinMode(Motor2Pin1,OUTPUT);
  pinMode(Motor2Pin2,OUTPUT);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0x2FD42BD){//kiri
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,165);
      maju();
    }
    else if(results.value == 0x2FD9867){//maju
      analogWrite(motor1PWM,245);
      analogWrite(motor2PWM,255);
      maju();
    }
    else if(results.value == 0x2FD02FD){//kanan
      analogWrite(motor1PWM,165);
      analogWrite(motor2PWM,255);
      maju();
    }
    else if(results.value == 0x2FDB847){
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      mundur();
    }
    else if(results.value == 0x2FD847B){
      analogWrite(motor1PWM,0);
      analogWrite(motor2PWM,0);
      berhenti();
    }
    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
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
