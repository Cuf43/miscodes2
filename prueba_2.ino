int pir1 = 9;
int verde = 10;
void setup() {
Serial.begin(9600);
pinMode(pir1, INPUT);
pinMode(verde, OUTPUT);

}

void loop() {
int Valor = digitalRead(pir1);
if(Valor == HIGH){
digitalWrite(verde, HIGH);
Serial.print(Valor);
delay(250);  
}
else{
digitalWrite(verde, LOW);
}
delay(50);
}
