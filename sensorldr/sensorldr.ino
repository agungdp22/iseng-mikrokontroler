const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

float sensorkanan;
float sensorkiri;
int ledkanandepan = 8;
int ledkiridepan = 9;
int ledkananbelakang = 10;
int ledkiribelakang = 11;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(ledkanandepan, OUTPUT);
  pinMode(ledkananbelakang, OUTPUT);
  pinMode(ledkiridepan, OUTPUT);
  pinMode(ledkiribelakang, OUTPUT);
}

void loop() {
  float sensorkanan = analogRead(A1);
  float sensorkiri = analogRead(A0);
  float baca=map (sensorkiri,0,1023,1023,0);
  //float outputkanan = (sensorkanan/1023) * 5;
  //Serial.print(sensorkanan);
  //Serial.print("\t");
  Serial.print(sensorkiri);
  Serial.print("\n");
  delay(1000);
  if(sensorkanan<1000 || sensorkiri<1000){
    if(sensorkanan<990 && sensorkiri>990){//belok kanan
      digitalWrite(ledkanandepan, LOW); 
      digitalWrite(ledkananbelakang, HIGH); 
      digitalWrite(ledkiridepan, HIGH);
      digitalWrite(ledkiribelakang, LOW); 
    }
    else if(sensorkiri<990 && sensorkanan>990){//belok kiri
      digitalWrite(ledkanandepan, HIGH); 
      digitalWrite(ledkananbelakang, LOW); 
      digitalWrite(ledkiridepan, LOW);
      digitalWrite(ledkiribelakang, HIGH); 
    }
    else{
      digitalWrite(ledkanandepan, HIGH); //maju
      digitalWrite(ledkananbelakang, LOW); 
      digitalWrite(ledkiridepan, HIGH);
      digitalWrite(ledkiribelakang, LOW);
    }
  }
  else{
    digitalWrite(ledkanandepan, LOW);
    digitalWrite(ledkananbelakang, LOW); 
    digitalWrite(ledkiridepan, LOW);
    digitalWrite(ledkiribelakang, LOW); 
  }
}
