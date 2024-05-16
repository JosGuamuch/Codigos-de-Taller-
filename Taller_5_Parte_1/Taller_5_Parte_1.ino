/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:Parte 1 Practica 5
   Dev: Jose Guamuch
   Fecha: 03 de mayo
   */
int cont =1;
float Constante_Libra = 2.20462;
float Constante_MicroAm =1000;
float Conversion_lb_Kg(float Kilogramos){
float resultado;
  resultado=Constante_Libra* Kilogramos;
  return resultado;
} 
float Conversion_Am_Micro(float Amperios){
 float resultado2;
  resultado2= Constante_MicroAm*Amperios;
  return resultado2;
}
    
void secuencia_led(int Led){
  switch(Led){
    case 1:
    digitalWrite(4,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(7,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    break;
    case 2:
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    break;
    case 3:
    digitalWrite(5,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    break;
    case 4:
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    digitalWrite(1,LOW);
    digitalWrite(7,LOW);
  
    break;
    case 5:
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break;
  }
}

void setup()
{
  Serial.begin(9600);
  float Conversion;
  Conversion= Conversion_lb_Kg(3);
  Serial.println("Conversion de lb a KG");
  Serial.println(Conversion);
  
  float Conversion2;
  Conversion2 = Conversion_Am_Micro(5);
  Serial.println("Conversion de Amperios a MicroAm");
  Serial.println(Conversion2);
  
  digitalWrite(2,OUTPUT);
  digitalWrite(3,OUTPUT);
  digitalWrite(4,OUTPUT);
  digitalWrite(5,OUTPUT);
  digitalWrite(6,OUTPUT);
  digitalWrite(7,OUTPUT);
  digitalWrite(8,OUTPUT); 
}

void loop()
{
    for(cont=1;cont<6;cont++){
    secuencia_led(cont);
    delay(1000);
  }  
}
