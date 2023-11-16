int disparo = 2; // Definimos el pin Triger del sensor como disparo en el pin 4 del arduino
int eco = 4; // Definimos el pin echo del sensor como eco en el pin 2 del arduino

int ledTest = 13; // definimos el ledtest para la comprobacion del la conexcion de la compu con la arduino

long Pulso; // definimos pulso como una variable de unidad decimal 
float Medida; // definimos medidia como una variable de unidad entera larga


void setup() { // comenzamos el setup 
  Serial.begin (9600); // iniciamos la transmicion de datos entre la compu y el arduino
  
  pinMode (disparo,OUTPUT); // declaramos a disparo con un pin de salida
  pinMode(eco, INPUT);// declaramos a eco con un pin de entrada
  pinMode (ledTest, OUTPUT);// declaramos a ledtest con un pin de salida

  digitalWrite (disparo, LOW); // se apaga el pin triger del sensor 
  digitalWrite (ledTest, LOW); // apagamos el pin del ledTest para qeu no este prendido 
 // saludo inicial para comprobar la conexcion 
  digitalWrite (ledTest, HIGH);
  delay (500);
  digitalWrite (ledTest, LOW);
   digitalWrite (ledTest, HIGH);
  delay (500);
  digitalWrite (ledTest, LOW);
   digitalWrite (ledTest, HIGH);
  delay (500);
  digitalWrite (ledTest, LOW);
}

void loop() {
  //el sensor empieza a leer las distancia y el tiempo tomado 
 digitalWrite (disparo, HIGH);
 delayMicroseconds (10);
 digitalWrite (disparo, LOW);

  Pulso = pulseIn (eco, HIGH);
  Medida = 0.0340 / 2 * Pulso;
 //se escribe en el monitor de serie la distancia y el tiempo que lee el sensor 
  Serial.println ("Tiempo / Distancia");
  Serial.print (Pulso);
  Serial.print ("/");
  Serial.println(Medida);

  delay (500);
 
   
}
