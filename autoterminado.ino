//Definición de variables 
//Aca definimos los pines para el puente H
int out1 = 13; //Out 1 es el sentido horario del motor uno
int out2 = 12; //Out 2 es el sentido ANTIhorarip del moto uno
int out3 = 9; //Out 3 es el sentido horario del motor dos 
int out4 = 8; //Out 4 es el sentido ANTIhorario del motor dos

//Definimos las variables para el sensor ultasonico
int echo = 5; //definimo el pin para el echo
int triger = 6; //definimos el pin para el triger

long tiempoPulso; 
float distancia; 

int valor=0; //iniciomos el valor que va a tomar el senso infrarojo en 0
const int sensorPin=4; //definimos el pin digital en donde vamos a conectar el sensor infrarojo

void setup() { 
 Serial.begin(9600); 
 //Definimos el modo de cada veriable definida
  pinMode(triger, OUTPUT); 
  pinMode(echo, INPUT);
  
  pinMode (out1, OUTPUT);
  pinMode (out2, OUTPUT);
  pinMode (out3, OUTPUT);
  pinMode (out4, OUTPUT);

  pinMode(sensorPin, INPUT);


  digitalWrite (echo, LOW);
  digitalWrite (triger, LOW);
  
    digitalWrite (out1, LOW);
    digitalWrite (out2, LOW);
    digitalWrite (out3, LOW);
    digitalWrite (out4, LOW);

}

void loop() {

  //Iniciamos las lectura del sensor ultrasonico 
  digitalWrite (triger, HIGH);
  delayMicroseconds (10);
  digitalWrite (triger, LOW);
  //Hacemos la cuenta de la distancia tomada por el sensor en cm
  tiempoPulso=pulseIn(echo,HIGH); 
  distancia= 0.034/2*tiempoPulso; 
 Serial.print(distancia);
 
      if (distancia<20){ //Decimos que si la distanca es mayor a 20cm entonces el auto va para adealnte 
        digitalWrite (out1, HIGH);
        digitalWrite (out2, LOW);
        digitalWrite (out3, LOW);
        digitalWrite (out4, LOW);
       delay(300);
         digitalWrite (out1, HIGH);
        digitalWrite (out2, LOW);
        digitalWrite (out3, LOW);
        digitalWrite (out4, HIGH);
      delay(300);
      
        digitalWrite (out1, LOW);
        digitalWrite (out2, HIGH);
        digitalWrite (out3, HIGH);
        digitalWrite (out4, LOW);
        delay(300);
        
      }
      else{ // Y si la distancia es menor de 20 entonces el auto girara 
      digitalWrite (out1, HIGH);
      digitalWrite (out2, LOW);
      digitalWrite (out3, HIGH);
      digitalWrite (out4, LOW);  
      delay(300);
     }

     valor = digitalRead(sensorPin); // Iniciamos la lectura del sensor infrarojo 
 if (valor == HIGH) { // Decimos que si el valor es HIGH (Toma la linea negra) entonces el auto va para adelante 
    Serial.println("Sin Movimientos");
    digitalWrite (out1, HIGH);
    digitalWrite (out2, LOW);
    digitalWrite (out3, HIGH);
    digitalWrite (out4, LOW);
    delay(300);
  }
  else { // Si no que el auto gire para que se acomode y encuentre otra vez la linea 
    Serial.println("Detecto");
   digitalWrite (out1, LOW);
   digitalWrite (out2, HIGH);
   digitalWrite (out3, HIGH);
   digitalWrite (out4, LOW);
  
}
  delay(50);
}
