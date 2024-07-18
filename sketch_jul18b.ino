#include <LedControl.h>
 
#define din_matrix 3
#define cs_matrix 2
#define clk_matrix 4
#define potenciometr_t A1 
LedControl Pacman_Matrix = LedControl(din_matrix, clk_matrix, cs_matrix, 1);
 
byte Pacman_boca_abierta[8] = {
B00111000,
B01000100,
B10001000,
B10010000,
B10001000, 
B01000100,
B00111000,
 };

byte Pacman_boca_Cerrada[8] = {
B00111000,
B01000100,
B10000010,
B10001110,
B10000010,
B01000100,
B00111000,
B00000000,
 };

 
void setup() {
Serial.begin(9600);
Pacman_Matrix.shutdown(0, false);
Pacman_Matrix.setIntensity(0, 15);
Pacman_Matrix.clearDisplay(0);
Serial.println("Uso de la matriz led");
 
}
 
void loop() {
int valor = analogRead(potenciometr_t);
int Tiempo= map(valor,0,1023,50,1500);
  
BocaA();
delay(Tiempo);
BocaC();
delay(Tiempo);
}

void BocaA(){
for(int i=0; i<8; i++ ){
  Pacman_Matrix.setRow(0,i, Pacman_boca_abierta[i]);
}
  
}

void BocaC(){
for(int i=0; i<8; i++ ){
  Pacman_Matrix.setRow(0,i, Pacman_boca_Cerrada[i]);
}
  
}
