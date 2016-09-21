//common cathode
#define ON LOW
#define OFF HIGH

//common anode
//#define ON HIGH
//#define OFF LOW


//definisikan pin segmen
#define A 6
#define B 7
#define C 8
#define D 9
#define E 10
#define f 11
#define G 12

//definisikan pin digit
#define D1 3
#define D2 4
#define D3 5
#define D4 2

int ms=1000;
int sensor;

void setup(){
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(f,OUTPUT);  //kalau F huruf besar jadi error
  pinMode(G,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
}

void loop(){
  sensor=2212;
  tampilkanAngka(1,sensor%10);
  clearLED();
  sensor=sensor/10;
  tampilkanAngka(2,sensor%10);
  clearLED();
  sensor=sensor/10;
  tampilkanAngka(3,sensor%10);
  clearLED();
  sensor=sensor/10;
  tampilkanAngka(4,sensor%10);
  clearLED();
}

void clearLED(){
  delay(5);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
}

void tampilkanAngka(int digit, int angka){
  switch (digit) {
    case 1:
      digitalWrite(D1,HIGH);
      break;
    case 2:
      digitalWrite(D2,HIGH);
      break;
    case 3:
      digitalWrite(D3,HIGH);
      break;
    case 4:
      digitalWrite(D4,HIGH);
      break;
      
  }
  switch (angka){
    case 0:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, OFF);
        break;
     case 1:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, OFF);
        break;
    case 2:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, OFF);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, OFF);
        digitalWrite(G, ON);
        break;
    case 3:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, ON);
        break;
    case 4:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 5:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 6:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 7:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, OFF);
        break;
    case 8:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 9:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
  }
}
