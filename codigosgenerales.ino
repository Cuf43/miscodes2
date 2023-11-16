//codigo principal para aumento de pines 
int latchPin = 8;
int clockPin = 2;
int dataPin = 12;
byte myByte = 0b01010101;
void setup() {
 Serial.begin(9600); 

 pinMode(latchPin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST, myByte); 
  digitalWrite(latchPin, HIGH);
 }


#include <LiquidCrystal.h>  //codigo principal para pantalla led

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); 
  lcd_1.print("hello world!");
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd_1.print(seconds);
  delay(1000); // Wait for 1000 millisecond(s)
  seconds += 1;
}