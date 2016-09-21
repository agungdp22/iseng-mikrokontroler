#include <IRremote.h>

int RECV_PIN = 5;
int relay = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(relay,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0x2FD847B){
      digitalWrite(relay,HIGH);
    }
    else if(results.value == 0x2FDB847){
      digitalWrite(relay,LOW);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(10);
}
