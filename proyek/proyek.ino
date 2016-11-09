#include <NewPing.h>
#include <Servo.h>  

#define TRIGGER_PIN  3  
#define ECHO_PIN   2   
#define MAX_DISTANCE 100
#define toleransicelah 5

const int Motor1Maju = 9;   //1 = motor kanan
const int Motor1Mundur = 8;
const int Motor2Maju = 10;    //2 = motor kiri
const int Motor2Mundur = 11;
int motor1PWM = 5;
int motor2PWM = 6;
Servo servo1;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned long time;
int distance;    
int celah = 0; 
int led = 8;         
int triggerDistance = 30;
int kiri;
int kanan;
int pos = 90; //posisi mula mula servo 90 derajat(menghadap ke depan)
boolean belokkanan = false;
boolean belokkiri = false;
boolean SUKSESPARKIR = false;

void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Maju, OUTPUT);   
  pinMode(Motor1Mundur, OUTPUT);   
  pinMode(Motor2Maju, OUTPUT);   
  pinMode(Motor2Mundur, OUTPUT);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  servo1.attach(6);
  analogWrite(motor1PWM,255);
  analogWrite(motor2PWM,255);
}

void loop()
{
  scan();
  Serial.println(distance);
  if(distance < triggerDistance){
    parkir();
  }
  else if(distance >= triggerDistance){
    maju();
    Serial.print("Maju\t");
  }
  if(SUKSESPARKIR){
    Serial.println("SUKSES PARKIR");
    Stop();
    delay(5000);
    celah = 0;
    SUKSESPARKIR = false;
    belokkanan = false;
    belokkiri = false;
  }
}

void scan()
{
  time = sonar.ping();               
  distance = time / US_ROUNDTRIP_CM;   
  if(distance == 0){                 
    distance = 100;                  
  }
  delay(10);
}

void parkir()
{
  mundur();
  Serial.println("Mundur");
  delay(500);
  Stop();
  Serial.println("Stop");
  for(pos = 90; pos >= 30; pos -= 5){ 
    servo1.write(pos);              
    delay(15);                       
  }   //servo ke kanan sejauh 60 derajat dari posisi awal
  Serial.println("Servo ke kanan");
  scan();
  kanan = distance;
  Serial.print("kanan= ");
  Serial.println(kanan);
  delay(500);
  for(pos = 30; pos <= 150; pos += 5){ 
    servo1.write(pos);
    delay(15);
  }  //servo ke kiri sejauh 150 derajat dari posisi semula
  Serial.println("Servo ke kiri");
  scan();
  kiri = distance;
  Serial.print("kiri= ");
  Serial.println(kiri);
  delay(1000);
  if(kiri < kanan){
    belokkanan = true;
    for(pos = 150; pos <= 180; pos += 5){ 
      servo1.write(pos);
      delay(15);                       
    } //servo ke kiri ngadep penghalang sebelah kiri, tegak lurus sama mobil
    moveKanan();
    Serial.println("Belok kanan");
    delay(400);
    maju();
  }
  else {
    belokkiri = true;
    for(pos = 150; pos >= 0; pos -= 5){ 
      servo1.write(pos);              
      delay(15);                       
    }//servo ke kanan ngadep penghalang sebelah kiri, tegak lurus sama mobil
    moveKiri();
    Serial.println("Belok kiri");
    delay(400);
    maju();
  }
  delay(1500);
  SUKSESPARKIR = false; //mobil dalam keadaan belum terparkir (masih nyari)
  while(!SUKSESPARKIR){ //nyari tempat parkir
    scan();
    Serial.println(distance);
    maju();
    //mengatur jarak agar tetap konstan, fuzifikasi
    if(belokkanan){
      if(distance <20) {
        analogWrite(motor1PWM,127);
        celah = 0;
      }
      else if(distance >=20 && distance <=25) {
        analogWrite(motor1PWM,255);
        analogWrite(motor2PWM,255);
        celah = 0;
      }
      else if(distance >25 && distance <30){
        analogWrite(motor2PWM,127);
        celah = 0;
      }
      else {
        celah++;
      }
    }
    else{
      if(distance < 20) {
        analogWrite(motor2PWM,127);
        celah = 0;
      }
      else if(distance >= 20 && distance <=25) {
        analogWrite(motor1PWM,127);
        analogWrite(motor2PWM,127);
        celah = 0;
      }
      else if(distance >25 && distance <30){
        analogWrite(motor1PWM,127);
        celah = 0;
      }
      else {
        celah++;
      }
    }
    Serial.println("Maju nyari parkir");
    Serial.print(distance);
    Serial.print("\t");
    Serial.println(celah);
    delay(500);
    if(celah > toleransicelah){   //,udah deteksi ada tempat parkir, kalo count-nya gede kan berari celahnya gede juga
      analogWrite(motor1PWM,255);
      analogWrite(motor2PWM,255);
      mundur();
      Serial.println("Mundur parkir");
      delay(400);
      if(belokkanan){ //dicek keadaan sebelumnya klo dia belok kanan kan calon tempat parkirnya di sebelah kirinya
        moveKiri();
        Serial.println("parkir sebelah kiri");
        delay(1000);
        maju();
        delay(1000);
        for(pos = 180; pos >= 90; pos -= 1){ 
          servo1.write(pos);              
          delay(15);                       
        }
        SUKSESPARKIR = true; // sukses terparkir
      }
      else{       //lawannya yg di atas(belok kanan)
        moveKanan();
        Serial.println("parkir sebelah kanan");
        delay(1000);
        maju();
        delay(1000);
        for(pos = 0; pos <= 90; pos += 1){ 
          servo1.write(pos);              
          delay(15);                       
        }
        SUKSESPARKIR = true;
      }
    }
  }
}

void mundur(){
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, HIGH);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, HIGH);
}

void maju(){
  digitalWrite(Motor1Maju, HIGH);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, HIGH);
  digitalWrite(Motor2Mundur, LOW);
}

void moveKanan(){
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, HIGH);
  digitalWrite(Motor2Maju, HIGH);
  digitalWrite(Motor2Mundur, LOW);
}

void moveKiri(){
  digitalWrite(Motor1Maju, HIGH);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, HIGH);
}

void Stop(){
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, LOW);
}
//the code writen by agung dwi prasetyo dept computer science ipb
