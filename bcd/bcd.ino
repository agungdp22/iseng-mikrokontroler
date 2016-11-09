/*
Agung Dwi Prasetyo
G64130073
*/
// bits representing segments A through G (and decimal point) for numerals 0-9
const byte numeral[10] = {
  //ABCDEFG /dp
  B11111110, // 0
  B10110000, // 1
  B11101101, // 2
  B11111001, // 3
  B10110011, // 4
  B11011011, // 5
  B11011111, // 6
  B11110000, // 7
  B11111111, // 8
  B11111011, // 9
};
// pins for decimal point and each segment
// dp,G,F,E,D,C,B,A
const int segmentPins[8] = { 12,11,10,9,8,7,6};

void setup(){
  Serial.begin(9600);
  for(int i=0; i < 8; i++){
    pinMode(segmentPins[i], OUTPUT); // set segment and DP pins to output
  }
}

void loop(){
  int sensor = analogRead(A0) - 400;
  int angka = map(sensor,0,623,9,0);
  //for(int i=0; i <10; i++){
    showDigit(angka);
  Serial.print(sensor);
  Serial.print("\t");
  Serial.println(angka);
    //delay(1000);
  //}
  //delay(2000); // pause two seconds with the display off
}

void showDigit( int number){
  boolean isBitSet;
  for(int segment = 0; segment < 8; segment++){
    if( number < 0 || number > 9){
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
