#include <IRremote.h>
#include <LiquidCrystal.h>

int RECV_PIN = 5;
LiquidCrystal lcd(12,11,10,9,8,7);

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  lcd.begin(16, 2);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    lcd.setCursor(0,0);
    if((results.value == 0xFFA25D) || (results.value == 0xE318261B)){
      lcd.clear();
      lcd.write("CH-");
    }
    else if(results.value == 0xFF629D || (results.value == 0x511DBB)){
      lcd.clear();
      lcd.write("CH");
    }
    else if(results.value == 0xFFE21D || (results.value == 0xEE886D7F)){
      lcd.clear();
      lcd.write("CH+");
    }
    else if(results.value == 0xFF22DD || (results.value == 0x52A3D41F)){
      lcd.clear();
      lcd.write("PREV");
    }
    else if(results.value == 0xFF02FD || (results.value == 0xD7E84B1B)){
      lcd.clear();
      lcd.write("NEXT");
    }
    else if(results.value == 0xFFC23D || (results.value == 0x20FE4DBB)){
      lcd.clear();
      lcd.write("PLAY/PAUSE");
    }
    else if(results.value == 0xFFE01F || (results.value == 0xF076C13B)){
      lcd.clear();
      lcd.write("VOL-");
    }
    else if(results.value == 0xFFA857 || (results.value == 0xA3C8EDDB)){
      lcd.clear();
      lcd.write("VOL+");
    }
    else if(results.value == 0xFF906F || (results.value == 0xE5CFBD7F)){
      lcd.clear();
      lcd.write("EQ");
    }
    else if(results.value == 0xFF6897 || (results.value == 0xC101E57B)){
      lcd.clear();
      lcd.write("0");
    }
    else if(results.value == 0xFF9867 || (results.value == 0x97483BFB)){
      lcd.clear();
      lcd.write("100+");
    }
    else if(results.value == 0xFFB04F || (results.value == 0xF0C41643)){
      lcd.clear();
      lcd.write("200+");
    }
    else if(results.value == 0xFF30CF || (results.value == 0x9716BE3F)){
      lcd.clear();
      lcd.write("1");
    }
    else if(results.value == 0xFF18E7 || (results.value == 0x3D9AE3F7)){
      lcd.clear();
      lcd.write("2");
    }
    else if(results.value == 0xFF7A85 || (results.value == 0x6182021B)){
      lcd.clear();
      lcd.write("3");
    }
    else if(results.value == 0xFF10EF || (results.value == 0x8C22657B)){
      lcd.clear();
      lcd.write("4");
    }
    else if(results.value == 0xFF38C7 || (results.value == 0x488F3CBB)){
      lcd.clear();
      lcd.write("5");
    }
    else if(results.value == 0xFF5AA5 || (results.value == 0x449E79F)){
      lcd.clear();
      lcd.write("6");
    }
    else if(results.value == 0xFF42BD || (results.value == 0x32C6FDF7)){
      lcd.clear();
      lcd.write("7");
    }
    else if(results.value == 0xFF4AB5 || (results.value == 0x1BC0157B)){
      lcd.clear();
      lcd.write("8");
    }
    else if(results.value == 0xFF52AD || (results.value == 0x3EC3FC1B)){
      lcd.clear();
      lcd.write("9");
    }
    else {
      lcd.clear();
      lcd.write("Error");
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
