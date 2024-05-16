int cont = 1;

void secuencia_led(int Led){
  switch(Led){
    case 1:
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;
   case 2:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    break;
    case 3:
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(6,LOW);
    break;
    case 4:
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  
    break;
    case 5:
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;
    
    case 6:
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);

    break;
    
    case 7:
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    break;
    
    
    case 8:
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
    delay(500);    
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(5,LOW);
    break;
    
    case 9:
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    break;
    
    case 10:
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    delay(500);
     digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(4,LOW);
    tone(3,250);
    delay(500);
    noTone(3);
    digitalWrite(11, LOW);  
    delay(500);
    digitalWrite(11, HIGH);
    break;     
  }
}

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT); 
  digitalWrite(11, HIGH);
   for(cont=1;cont<11;cont++){
    secuencia_led(cont);
    delay(1000);}  
}

void loop()
{
 
}
