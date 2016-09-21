const int buzzerPin = 9;
float sensor1;
float suara;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  sensor1 = analogRead(A0);
  suara = map(sensor1,0,1023,0,8);
  if(suara<8 && sensor1 >=7) tone(buzzerPin,262,200);
  else if(suara<7 && sensor1 >=6) tone(buzzerPin,294,200);
  else if(suara<6 && sensor1 >=5) tone(buzzerPin,330,200);
  else if(suara<5 && sensor1 >=4) tone(buzzerPin,349,200);
  else if(suara<4 && sensor1 >=3) tone(buzzerPin,392,200);
  else if(suara<3 && sensor1 >=2) tone(buzzerPin,440,200);
  else if(suara<2 && sensor1 >=1) tone(buzzerPin,494,200);
  else if(suara<1 && sensor1 >=0) tone(buzzerPin,523,200);
  else tone(buzzerPin,0,200);
  Serial.println(suara);
}
