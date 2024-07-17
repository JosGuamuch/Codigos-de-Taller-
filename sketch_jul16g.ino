/* Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Variables de medición e indicaciones sonoras
   Dev: Jose Guamuch
   Fecha: 16 de Julio
*/
#include <Wire.h>
#include <SparkFun_ADXL345.h> 
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

SoftwareSerial softSerial(A1, A2); // Conexiones RX y TX del DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;
ADXL345 acelerometro_ADXL345 = ADXL345();
int x, y, z;
float Mx, My, Mz, MR;

void setup() {
  softSerial.begin(9600);
  Serial.begin(9600);

  if (!myDFPlayer.begin(softSerial)) {
    Serial.println("Error en la inicialización del DFPlayer Mini");
    // No detener el programa, continuar con la inicialización de los LEDs
  }
  myDFPlayer.volume(15); // Ajusta el volumen a un nivel más alto
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(8);
  
  for (int i = 2; i <= 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH); // Asegúrate de que los LEDs estén apagados al inicio
  }
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A1, HIGH); // Asegúrate de que el pin A1 esté en alto al inicio
  digitalWrite(A2, HIGH); // Asegúrate de que el pin A2 esté en alto al inicio
}

void loop() {
  // Leer datos del acelerómetro
  acelerometro_ADXL345.readAccel(&x, &y, &z);
  Mx = x * 0.4; 
  My = y * 0.4;
  Mz = z * 0.4;

  MR = sqrt(Mx * Mx + My * My + Mz * Mz);

  Serial.print("La magnitud resultante de la aceleracion es de: ");
  Serial.println(MR);

  // Mapear MR a un rango de 0 a 10
  int Rango = map(MR, 24, 100, 0, 10); 

  Serial.print("Rango calculado: ");
  Serial.println(Rango);

  // Reproducción de sonido y control de pines según el rango
  switch (Rango) {
    case 0:
      digitalWrite(2, LOW);
      break;
    case 1:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      apagar();
      break;
    case 2:
      for (int i = 2; i <= 4; i++) {
        digitalWrite(i, LOW);
      }
      apagar();
      break;
    case 3:
      for (int i = 2; i <= 5; i++) {
        digitalWrite(i, LOW);
      }
      apagar();
      break;
    case 4:
      for (int i = 2; i <= 6; i++) {
        digitalWrite(i, LOW);
      }
      apagar();
      break;
    case 5:
      for (int i = 2; i <= 7; i++) {
        digitalWrite(i, LOW);
      }
      apagar();
      break;
    case 6:
      myDFPlayer.play(1);
      for (int i = 2; i <= 8; i++) {
        digitalWrite(i, LOW);
      }
      apagar();
      break;
    case 7:
      myDFPlayer.play(1);
      for (int i = 2; i <= 9; i++) {
        digitalWrite(i, LOW);
      }
      apagar(); 
      break;
    case 8:
      myDFPlayer.play(1);
      for (int i = 2; i <= 10; i++) {
        digitalWrite(i, LOW);
      }
      digitalWrite(A2, LOW);
      apagar();
      break;
    case 9:
      myDFPlayer.play(1);
      for (int i = 2; i <= 11; i++) {
        digitalWrite(i, LOW);
      }
      digitalWrite(A2, LOW);
      digitalWrite(A1, LOW);
      apagar();
      break;
    case 10:
      myDFPlayer.play(1);
      for (int i = 2; i <= 12; i++) {
        digitalWrite(i, LOW);
      }
      digitalWrite(A2, LOW);
      digitalWrite(A1, LOW);
      apagar();
      break;
    default:
      for (int i = 2; i <= 12; i++) {
        digitalWrite(i, LOW);
      }
      digitalWrite(A2, LOW);
      digitalWrite(A1, LOW);  
      myDFPlayer.play(1);
      apagar();
  }
}

void salidas() {
  for (int i = 2; i <= 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH); // Apagar LEDs
  }
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  digitalWrite(A2, HIGH); // Apagar pin A2
  digitalWrite(A1, HIGH); // Apagar pin A1
}

void apagar() {
  delay(2000);
  for (int i = 2; i <= 12; i++) {
    digitalWrite(i, HIGH); // Apagar LEDs
  }
  digitalWrite(A2, HIGH); // Apagar pin A2
  digitalWrite(A1, HIGH); // Apagar pin A1
}
