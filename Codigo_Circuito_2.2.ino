/*
Fundacion Kinal 
Centro educativo tecnico laborsl kinal
Quinto Perito
Quinto electronica
Codigo tecnico:EB5AM
Curso:Taller de electronica digital y reparacion de computadoras
Proyecto:Como leer un pin digital
Dev:Jose Guamuch
Fecha: 12 de abril
*/
#define LedNaranja 4
#define tiempo_espera 500


void setup()
{
  pinMode(LedNaranja , OUTPUT);//Pin como salida
  digitalWrite(LedNaranja, LOW);//LED conectadoal pin 13 inicia el apagado
  
}

void loop()
{
  digitalWrite(LedNaranja, HIGH);
  delay(tiempo_espera ); 
  digitalWrite(LedNaranja, LOW);
  delay(tiempo_espera );
}
