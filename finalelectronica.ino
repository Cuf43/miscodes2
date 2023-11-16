#include <LiquidCrystal_I2C.h> 
#include <Servo.h>
#include <Wire.h>

int pir1 = 11;
int pirdato1;
int pir2 = 10;
int pirdato2;
int pir3 = 9;
int pirdato3;

int seconds = 0;

LiquidCrystal_I2C lcd_1(0x27,20,4);


int servoPin = 3;

Servo myservo;


int verde = 8;
int rojo = 2;



int sensor1TriggerPin = 7;
const int sensor1EchoPin = 6;
const int sensor2TriggerPin = 5;
const int sensor2EchoPin = 4;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);
  
  lcd_1.begin(16, 2);
  
  myservo.attach(servoPin);

  

  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT); 
  
  pinMode(sensor1TriggerPin, OUTPUT);
  pinMode(sensor1EchoPin, INPUT);
  pinMode(sensor2TriggerPin, OUTPUT);
  pinMode(sensor2EchoPin, INPUT);

   lcd_1.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd_1.backlight();
  lcd_1.print("HOLAA");
  delay(2000);
  lcd_1.clear();
  delay(50);
  lcd_1.print("HOLAA");
  delay(2000);
  lcd_1.clear();
 
}

void loop() {
  
 
  
 
  
  long duration1, distance1;
  long duration2, distance2;

  // Primer sensor ultrasónico
  digitalWrite(sensor1TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor1TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor1TriggerPin, LOW);
  duration1 = pulseIn(sensor1EchoPin, HIGH);
  distance1 = (duration1 / 2) / 29.1; // Convertir la duración en distancia en centímetros

  // Segundo sensor ultrasónico
  digitalWrite(sensor2TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor2TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor2TriggerPin, LOW);
  duration2 = pulseIn(sensor2EchoPin, HIGH);
  distance2 = (duration2 / 2) / 29.1; // Convertir la duración en distancia en centímetros

  // Imprimir las distancias en el monitor serie
  Serial.print("Distancia Sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distancia Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  
  
    if (distance1>20){ //sersor 1
    
  delay(250);
  myservo.write(0);
  digitalWrite(verde, LOW);
  digitalWrite(rojo,HIGH);
  delay(250);
  }
  
  if(distance1<20) { //sersor 1
  delay(250);
    myservo.write(180);
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW); 
   delay(250);
    }



  if (distance2<30) {
   
   lcd_1.clear();
   lcd_1.print("Cambiar Basura");
    }
  else {
    lcd_1.clear();
  }
  
  delay(10);
  
  
  
  pirdato1 = digitalRead(pir1);
  if (pirdato1 == HIGH)
  {
   lcd_1.clear();
   lcd_1.print("Tiro un plastico");
   Serial.print("El 1 tomo"); 
  }
  else
    {
     lcd_1.clear();
    }
  delay(10);
  pirdato2 = digitalRead(pir2);  
  if (pirdato2 == HIGH)
  {
   lcd_1.clear();
   lcd_1.print("Tiro un papel");
    
  }
  else
    {
     lcd_1.clear();
    }
  delay(10);
   pirdato3 = digitalRead(pir3);  
  if (pirdato3 == HIGH)
  {
   lcd_1.clear();
   lcd_1.print("Tiro un metal");
    
  }
  else
    {
     lcd_1.clear();
    }
  delay(100);
}
