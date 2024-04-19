/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:
   Dev: Jose Guamuch
   Fecha: 19 de abril
   */
#define Boton_Avance 4 
#define Boton_Retroseso 3

byte contador = 1;

struct Maquina_Dulces
{
char nombre_dulce [50];
byte cantidad_stock;
};

Maquina_Dulces dulce1 = {"Chocolate_Granada",30};
Maquina_Dulces dulce2 = {" Bombon_YO" , 30};
Maquina_Dulces dulce3 = {" Chicle_Clorence", 30 };   
Maquina_Dulces dulce4 = {" Gomitas_lulu ", 30 };

void setup(){
  Serial.begin(9600);
  pinMode(Boton_Avance, INPUT);
  pinMode(Boton_Retroseso, INPUT);
 
}
void loop()
{
  if (contador == 1){
  Serial.println(dulce1.nombre_dulce );
  Serial.print("El nombre del Dulce es :");
  Serial.println(dulce1.cantidad_stock );
  Serial.print("La cantidad del Dulce es :");
  } else if (contador == 2) {
  Serial.println(dulce2.nombre_dulce );
  Serial.print("El nombre del Dulce es :");
  Serial.println(dulce2.cantidad_stock );
  Serial.print("La cantidad del Dulce es :");
  } else if (contador == 3) {
  Serial.println(dulce3.nombre_dulce );
  Serial.print("El nombre del Dulce es :");
  Serial.println(dulce3.cantidad_stock );
  Serial.print("La cantidad del Dulce es :");
  } else if (contador == 4) {
  Serial.println(dulce4.nombre_dulce );
  Serial.print("El nombre del Dulce es :");
  Serial.println(dulce4.cantidad_stock );
  Serial.print("La cantidad del Dulce es :");
  } else if (contador > 4){
    delay(0);
    contador = 1;
  } else {
    delay(0);
    contador = 4;
  }
  if(digitalRead(Boton_Retroseso)==HIGH){
   delay(500);
    contador = contador-1;
  } else if(digitalRead(Boton_Avance)==HIGH) {
    delay(500);
    contador = contador+1;
  }
    
}
