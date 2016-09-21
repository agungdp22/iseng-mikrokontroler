/*
* SevenSegment sketch
* Shows numerals ranging from 0 through 9 on a single-digit display
* This example counts seconds from 0 to 9
*/
// bits representing segments A through G (and decimal point) for numerals 0-9
const byte numeral[16] = {
  //ABCDEFG /dp
  B1111110, // 0
  B0110000, // 1
  B1101101, // 2
  B1111001, // 3
  B0110011, // 4
  B1011011, // 5
  B1011111, // 6
  B1110000, // 7
  B1111111, // 8
  B1111011, // 9
  B1110111, // A
  B0011111, // B
  B1001110, // C
  B0111101, // D
  B1001111, // E
  B1000111, // F
};
// pins for decimal point and each segment
// dp,G,F,E,D,C,B,A
const int segmentPins[8] = { 12,11,10,9,8,7,6};
int dot = 13;

void setup(){
  Serial.begin(9600);
  for(int i=0; i < 8; i++){
    pinMode(segmentPins[i], OUTPUT); // set segment and DP pins to output
  }
  pinMode(dot,OUTPUT);
}

void loop(){
  for(int i=0; i <16; i++){
    showDigit(i);
    digitalWrite(dot,HIGH);
    delay(300);
  }
  
    digitalWrite(dot,LOW);
  //delay(2000); // pause two seconds with the display off
}

void showDigit( int number){
  boolean isBitSet;
  for(int segment = 0; segment < 8; segment++){
    if( number < 0 || number > 15){
      isBitSet = 0; // turn off all segments
    }
    else{
      // isBitSet will be true if given bit is 1
      isBitSet = bitRead(numeral[number], segment);
    }
    //isBitSet = ! isBitSet; // remove this line if common cathode display
    digitalWrite( segmentPins[segment], isBitSet);
  }
}
