/*
Agung Dwi Prasetyo
G64130073
*/

// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float sensor;
float suhu;
Servo servo1;
//float cahaya;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  servo1.attach(9);
  // Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  float sensor = analogRead(A0);
  //float cahaya=analogRead(A1);
  suhu=(sensor/255)*100;
  lcd.setCursor(0,0);
  lcd.print("Cahaya: ");
  if(sensor>1000){
    lcd.print("Gelap ");
    servo1.write(90);
  }
  else if(sensor>700){
    lcd.print("Terang");
    servo1.write(-90);
  }
  else{
    servo1.write(180);
  }
  lcd.setCursor(0, 1);
  lcd.print("R=");
  lcd.print(sensor);
  delay(300);
}
