/*
Agung Dwi Prasetyo
G64130073
*/

char val;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if( Serial.available() >0 ) {
    val = Serial.read();
    Serial.println(val); 
}
  if( val == '1' ) {
    digitalWrite(2,HIGH); }
  else if( val == '2' ) {
    digitalWrite(3,HIGH); }
  else if( val == '3' ) {
    digitalWrite(4,HIGH); }
  else if( val == '4' ) {
    digitalWrite(5,HIGH); }
  else if( val == '5' ) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
 }
  else if( val == 'A' ) {
    digitalWrite(2,LOW); }
  else if( val == 'B' ) {
    digitalWrite(3,LOW); }
  else if( val == 'C' ) {
    digitalWrite(4,LOW); }
  else if( val == 'D' ) {
    digitalWrite(5,LOW); }
  else if( val == 'E' ) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
}
