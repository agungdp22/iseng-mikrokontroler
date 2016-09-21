/*
Agung Dwi Prasetyo
G64130073
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float sensor1;
float sensor2;
int led = 9;
/*
int motorkanan1 = 7;
int motorkanan2 = 8;
int motorkiri1 = 9;
int motorkiri2 = 10;
 */

void setup() {
  Serial.begin(9600);
  /*
  pinMode(motorkanan1,OUTPUT);
  pinMode(motorkanan2,OUTPUT);
  pinMode(motorkiri1,OUTPUT);
  pinMode(motorkiri2,OUTPUT);
   */
  lcd.begin(16, 2);
}

void loop() {
  float sensor1 = analogRead(A0);
  float sensor2 = analogRead(A1);
  
  lcd.setCursor(0,0);
  if(sensor1<1000 || sensor2<1000){
    if((sensor2-sensor1)>10){
      //taro kodingan buat roda kiri mundur dan roda kanan maju
      //ex
      //digitalWrite(motorkanan1,HIGH);
      //digitalWrite(motorkanan2,LOW);
      //digitalWrite(motorkiri1,LOW);
      //digitalWrite(motorkiri2,HIGH);
      lcd.print("------KIRI------");
      digitalWrite(led,LOW);
    }
    else if((sensor1-sensor2)>10){
      //taro kodingan buat roda kiri maju dan roda kanan mundur
      //ex
      //digitalWrite(motorkanan1,LOW);
      //digitalWrite(motorkanan2,HIGH);
      //digitalWrite(motorkiri1,HIGH);
      //digitalWrite(motorkiri2,LOW);
      lcd.print("------KANAN-----");
      digitalWrite(led,LOW);
    }
    else{
      //taro kodingan buat semua roda maju
      //ex
      //digitalWrite(motorkanan1,HIGH);
      //digitalWrite(motorkanan2,LOW);
      //digitalWrite(motorkiri1,HIGH);
      //digitalWrite(motorkiri2,LOW);
      lcd.print("------MAJU------");
      digitalWrite(led,LOW);
    }
  }
  else {
    //taro kodingan buat roda untuk berhenti
    //ex
    //digitalWrite(motorkanan1,LOW);
    //digitalWrite(motorkanan2,LOW);
    //digitalWrite(motorkiri1,LOW);
    //digitalWrite(motorkiri2,LOW);
    lcd.print("------STOP------");
    digitalWrite(led,HIGH);
  }
  lcd.setCursor(0, 1);
  lcd.print(sensor1);
  lcd.print("  ");
  lcd.print(sensor2);
  delay(200);
}
