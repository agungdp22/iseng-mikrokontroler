int x = 9;
int y = 10;

void setup() {
  // set up the LCD's number of columns and rows: 
  pinMode(x,OUTPUT);
  pinMode(y,OUTPUT);
}

void loop() {
  digitalWrite(x,HIGH);
  digitalWrite(y,LOW);
  delay(10000);
  digitalWrite(y,HIGH);
  digitalWrite(x,LOW);
  delay(10000);
}
