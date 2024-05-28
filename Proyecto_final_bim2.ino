#include <Wire.h>               //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#include <Servo.h>              //Libreria que me permite usar el servomotor
#include <Keypad.h>    
//Teclado
#define filas_teclado 2  
#define columnas_teclado 3
//LCD
#define direccion_lcd 0x20
#define filas 2
#define columnas 16
//Contador
int i;
int l;
int cont;
int M;


LiquidCrystal_I2C LCDGuamuch(direccion_lcd, columnas, filas);


char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3'},
  {'4','5','6'},
 };

byte pines_filas[filas_teclado] = {2,3};
byte pines_columnas[columnas_teclado] = {4,5,6};

Keypad Teclado = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);






//Variable Display
void secuencia_led(int Led){
  switch(Led){
    case 1:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(8,LOW);
    break;
    case 2:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    break;
    case 3:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(8,LOW);
    break;
    case 4:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(13,LOW);
    break;
    
    case 5:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    break; 
  
   case 6:
    digitalWrite(8,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    break; 
  
     case 7:
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    break;  
  }
}

void setup()
{
     
  LCDGuamuch.init();
  LCDGuamuch.backlight(); 
  LCDGuamuch.setCursor(2,0);
  LCDGuamuch.print("Jose Guamuch");
  LCDGuamuch.setCursor(0,1);
  LCDGuamuch.print("Proyecto F BIM2");
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
 
  
}

void loop()
{
  Serial.begin(9600);
  char key = Teclado.getKey();
  
  if(key =='1'){
  for (int i = 0; i < 100; i++) {  
      Serial.println(i);
    delay(300);}
  } 
  
  if(key =='2'){
    for (int l = 99; l > 0; l--){  
      Serial.println(l);
      delay(300);}
  }
  
   if(key =='3'){
   
 for(cont=A0;cont<A4;cont++){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  
 }    
   for(cont=A3;cont>0;cont--){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  }
   }  

  
   if(key =='4'){
    for(int M=1;M<8;M++){
    secuencia_led(M);
      delay(1000);}
   }
  


  
  
  
  
  
  
  
  
}
