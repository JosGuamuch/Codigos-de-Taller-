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

// Directivas de procesasor
#define push_button 2 //Push button conectado al pin2
#define led 3

void setup()
{
  pinMode(push_button,INPUT);//pin 2 como entrada 
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("lectura de un pulsador");
  
}


void loop()
{
  //Variable local , que se encarga de almacenar el valor ( abieto o cerrado)
  // del pulsador conectado al pin 2 
  bool estado_boton = digitalRead(push_button);
  if(estado_boton == HIGH)
    {
    // Si lo eh presionado 
    digitalWrite(led, LOW); //Apago el led 
   }
  else{
  
  //Si no lo eh presionado 
    digitalWrite(led,HIGH);//Mantengo encedido el led 
  
       }
  
}
