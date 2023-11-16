int in1 = 13; //Out 1 es el sentido horario del motor uno
int in2 = 12; //Out 2 es el sentido ANTIhorarip del moto uno
int in3 = 9; //Out 3 es el sentido horario del motor dos 
int in4 = 8; //Out 4 es el sentido ANTIhorario del motor dos

int echo = 5; //definimo el pin para el echo
int triger = 6; //definimos el pin para el triger

long tiempoPulso; 
float distancia; 

int valor=0; //iniciomos el valor que va a tomar el senso infrarojo en 0
const int sensorPin=4; //definimos el pin digital en donde vamos a conectar el sensor infrarojo

void atras (){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  //motor drc
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

}

void adelante()
{
  //motor izq
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  //motor drc
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

}

void parar()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
 
  //motor drc
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

}

void izquierda()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  //motor drc
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

}

void derecha()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  //motor drc
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void setup() { 
 Serial.begin(9600); 
 //Definimos el modo de cada veriable definida
  pinMode(triger, OUTPUT); 
  pinMode(echo, INPUT);
  
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);

  pinMode(sensorPin, INPUT);

  digitalWrite (echo, LOW);
  digitalWrite (triger, LOW);
  }
  void loop(){
    digitalWrite (triger, HIGH);
  delayMicroseconds (10);
  digitalWrite (triger, LOW);
  //Hacemos la cuenta de la distancia tomada por el sensor en cm
  tiempoPulso=pulseIn(echo,HIGH); 
  distancia= 0.034/2*tiempoPulso; 
 Serial.print(distancia);
   
   if(distancia<10){
    derecha();
    delay(470);
    izquierda();
    delay(270);
   }
   else{
    adelante(); 
   }
   valor = digitalRead(sensorPin); // Iniciamos la lectura del sensor infrarojo 
 if (valor == HIGH) { 
  adelante();
  }
  else { // Si no que el auto gire para que se acomode y encuentre otra vez la linea 
   Serial.println("Detecto");
   izquierda();
   delay(470);
   derecha();
   delay(470);
  
  }
  }
  
