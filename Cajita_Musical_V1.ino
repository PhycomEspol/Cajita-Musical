int ledPin = 11;
int ledPin2 = 12;
int ledPin3 = 13;

int trigPin = 2;
int echoPin = 3;

int trigPin2 = 5;
int echoPin2 = 6;

int trigPin3 = 9;
int echoPin3 = 10;

int buzzer = 8;
int tiempo = 100;

long DO = 523.25;//definimos las frecuencias de las notas
long RE = 587.33;
long MI = 659.26;
long FA = 698.46;
long SOL = 783.99;
long LA = 880; //PALABRA CLAVE = arduino
long SI = 987.77;
long DO6 = 1174.66; 
     



//FUNCION DEL TONE
void notaMusical(int distancia){
  if (distancia <= 30 && distancia > 24) {
    tone(buzzer, DO);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, DO);
    delay(tiempo);
  }
  else if (distancia <= 24 && distancia > 20) {
    tone(buzzer, RE);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, RE);
    delay(tiempo);
  }
  else if (distancia <= 20 && distancia > 17) {
    tone(buzzer, MI);
    delay(100);
    noTone(buzzer);
    delay(100);
    tone(buzzer, MI);
    delay(100);
  }
  else if (distancia <= 17 && distancia > 14) {
    tone(buzzer, FA);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, FA);
    delay(tiempo);
  }
  else if (distancia <= 14 && distancia > 10) {
    tone(buzzer, SOL);
    delay(100);
    noTone(buzzer);
    delay(100);
    tone(buzzer, SOL);
    delay(100);
  }
  else if (distancia <= 10 && distancia > 8) {
    tone(buzzer, LA);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, LA);
    delay(tiempo);
  }
  else if (distancia <= 8 && distancia > 6) {
    tone(buzzer, SI);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, SI);
    delay(tiempo);
  }
  else if (distancia == 6) {
    tone(buzzer, DO6);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, DO6);
    delay(tiempo);
  }
  else {
    noTone(buzzer);
    Serial.print("Apagado");
    
  }
}
void setup() {
  Serial.begin (9600);
  pinMode(buzzer, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  //SE LOS INICIALIZA CON 0
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
}

void loop() {
  
  int t1; //timepo que demora en llegar el eco al 1
  int d1; //distancia en centimetros del 1
  
  int t2; //timepo que demora en llegar el eco al 2
  int d2; //distancia en centimetros del 2
  
  int t3; //timepo que demora en llegar el eco al 3
  int d3; //distancia en centimetros del 3
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);  
  t1 = pulseIn(echoPin, HIGH); //obtenemos el ancho del pulso
  d1 = (t1 / 2) / 29.1;           //escalamos el tiempo a una distancia en cm
     
  
  //SENSOR 1
  notaMusical(d1);
  if (d1 <= 30 && d1>=6) {    
    digitalWrite (ledPin, HIGH);    
    Serial.print("Distancia del UNO: ");
    Serial.print(d1);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();   
    
  }else{
    digitalWrite (ledPin, 0);
    
  }
  //SENSOR2
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trigPin2, LOW);  
  t2 = pulseIn(echoPin2, HIGH); //obtenemos el ancho del pulso
  d2 = (t2 / 2) / 29.1;           //escalamos el tiempo a una distancia en cm
  
  notaMusical(d2);
  if (d2 <= 30 && d2>=6) {
    digitalWrite (ledPin2, HIGH);
    
    Serial.print("Distancia del DOS: ");
    Serial.print(d2);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    
    
  }else{
    digitalWrite (ledPin2, 0);
  }
  
  
  
  //SENSOR3
  
    
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trigPin3, LOW);  
  t3 = pulseIn(echoPin3, HIGH); //obtenemos el ancho del pulso
  d3 = (t3 / 2) / 29.1;            //escalamos el tiempo a una distancia en cm
  
  notaMusical(d3);
  if (d3 <= 30 && d3>=6) {
    digitalWrite (ledPin3, HIGH);
    Serial.print("Distancia del TRES: ");
    Serial.print(d3);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    
    
  }else{
   digitalWrite (ledPin3, 0);
  }

  
  //Serial.print(d1);
  //Serial.print("\n");
  
}
