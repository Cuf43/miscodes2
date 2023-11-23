#include <LiquidCrystal_I2C.h> 
#include <Servo.h>
#include <Wire.h>

int seconds = 0;

LiquidCrystal_I2C lcd_1(0x27,20,4);


int servoPin = 3;

Servo myservo;


int verde = A2;
int rojo = A1;



int sensor1TriggerPin = 13;
const int sensor1EchoPin = 12;
const int sensor2TriggerPin = 11;
const int sensor2EchoPin = 10;
int sensor3TriggerPin = 9;
const int sensor3EchoPin = 8;
const int sensor4TriggerPin = 7;
const int sensor4EchoPin = 6;
const int sensor5TriggerPin = 5;
const int sensor5EchoPin = 4
;
void setup() {
  
  Serial.begin(9600);
  
  
  lcd_1.begin(16, 2);
  
  myservo.attach(servoPin);

  

  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT); 
  
  pinMode(sensor1TriggerPin, OUTPUT);
  pinMode(sensor1EchoPin, INPUT);
  pinMode(sensor2TriggerPin, OUTPUT);
  pinMode(sensor2EchoPin, INPUT);
  pinMode(sensor3TriggerPin, OUTPUT);
  pinMode(sensor3EchoPin, INPUT);
  pinMode(sensor4TriggerPin, OUTPUT);
  pinMode(sensor4EchoPin, INPUT);
  pinMode(sensor5TriggerPin, OUTPUT);
  pinMode(sensor5EchoPin, INPUT);

 lcd_1.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd_1.backlight();
  lcd_1.setCursor(3,0);
  lcd_1.print("Bienvenido");
  delay(2000);
  lcd_1.setCursor(4,1);
  lcd_1.print("De vuelta");
  delay(2000);
  lcd_1.clear();


 
}

void loop() {
  long duration1, distance1;
  long duration2, distance2;
  long duration3, distance3;
  long duration4, distance4;
  long duration5, distance5;
  // Primer sensor ultrasónico
  digitalWrite(sensor1TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor1TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor1TriggerPin, LOW);
  duration1 = pulseIn(sensor1EchoPin, HIGH);
  distance1 = (duration1 / 2) / 29.1; // Convertir la duración en distancia en centímetros
delay(50);
  // Segundo sensor ultrasónico
  digitalWrite(sensor2TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor2TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor2TriggerPin, LOW);
  duration2 = pulseIn(sensor2EchoPin, HIGH);
  distance2 = (duration2 / 2) / 29.1; // Convertir la duración en distancia en centímetros
  
   digitalWrite(sensor3TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor3TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor3TriggerPin, LOW);
  duration3 = pulseIn(sensor3EchoPin, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  digitalWrite(sensor4TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor4TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor4TriggerPin, LOW);
  duration4 = pulseIn(sensor4EchoPin, HIGH);
  distance4 = (duration4 / 2) / 29.1;

    digitalWrite(sensor5TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor5TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor5TriggerPin, LOW);
  duration5 = pulseIn(sensor5EchoPin, HIGH);
  distance5 = (duration5 / 2) / 29.1;
  
  // Imprimir las distancias en el monitor serie
  Serial.print("Distancia Sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distancia Sensor 2: ");
  Serial.print(distance3);
  Serial.println(" cm");

  Serial.print("Distancia Sensor 2: ");
  Serial.print(distance3);
  Serial.println(" cm");

  Serial.print("Distancia Sensor 2: ");
  Serial.print(distance4);
  Serial.println(" cm");

  Serial.print("Distancia Sensor 2: ");
  Serial.print(distance5);
  Serial.println(" cm");
  
  
  
    if (distance1>10){ //sersor 1
  myservo.write(60);
  analogWrite(verde, LOW);
  digitalWrite(rojo,HIGH);
  delay(250);
  lcd_1.clear();
  }
  
  if(distance1<10) { //sersor 1
    myservo.write(160);
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);
   delay(250);
    }


  if (distance2<10) { 
   
   lcd_1.clear();
   lcd_1.print("Cambiar Basura");
   delay(1000);
    }

    if (distance3<10) { 
   
   lcd_1.clear();
   lcd_1.print("Tiro un metal");
    delay(1000);
     lcd_1.clear();
    }


      if (distance4<10) { 
   
   lcd_1.clear();
   lcd_1.print("Tiro un papel");
   delay(1000);
   lcd_1.clear();
    }


      if (distance5<10) { 
   
   lcd_1.clear();
   lcd_1.print("Tiro un plastico"); 
   delay(1000);
   lcd_1.clear();
    }

delay(300);
}
