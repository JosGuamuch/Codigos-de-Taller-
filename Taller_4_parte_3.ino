int cont;


void setup()
{
  
   Serial.begin(9600);
   pinMode(A3,INPUT);
   pinMode(0,INPUT);
   pinMode(7,INPUT);
   pinMode(8,INPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
  
   
}

void loop(){
  
  if(digitalRead(7)==LOW){
    Serial.println("Practica No.4-Jose Guamuch");
    delay(3000);
  }
   if(digitalRead(8)==LOW&&digitalRead(A3)== LOW){
    Serial.println("Gracias por su atencion");
     delay(3000);
 }else if(digitalRead(8)==LOW){
 for(cont=2;cont<7;cont++){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  
 }    
   for(cont=6;cont>1;cont--){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  }
   
   digitalWrite(2,HIGH); 
   digitalWrite(3,HIGH); 
   digitalWrite(4,HIGH); 
   digitalWrite(5,HIGH); 
   digitalWrite(6,HIGH); 
  
   delay(500);
   digitalWrite(2,LOW); 
   digitalWrite(3,LOW); 
   digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,LOW); 
   
 } if(digitalRead(7)==LOW&&digitalRead(0)== LOW){
    Serial.println("Gracias por su atencion");
     delay(3000);
   }else if (digitalRead(0)==LOW){
   digitalWrite(11,HIGH); 
   digitalWrite(10,HIGH); 
   digitalWrite(A0,HIGH); 
   digitalWrite(A1,HIGH); 
     delay(1000);
   digitalWrite(11,LOW); 
   digitalWrite(10,LOW); 
   digitalWrite(A0,LOW); 
   digitalWrite(A1,LOW);
      
  
    delay(2000); 
     
     
   digitalWrite(12,HIGH); 
   digitalWrite(A2,HIGH); 
   digitalWrite(A1,HIGH); 
   digitalWrite(A0,HIGH); 
   digitalWrite(10,HIGH); 
  
   delay(1000);
   digitalWrite(10,LOW); 
   digitalWrite(A0,LOW); 
   digitalWrite(A1,LOW); 
   digitalWrite(A2,LOW); 
   digitalWrite(12,LOW); 
    delay(2000); 
     
     
     digitalWrite(11,HIGH); 
   digitalWrite(12,HIGH); 
   digitalWrite(A2,HIGH); 
   digitalWrite(A0,HIGH); 
   digitalWrite(10,HIGH); 
  digitalWrite(9,HIGH); 
   delay(1000);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW); 
   digitalWrite(A2,LOW); 
   digitalWrite(A0,LOW); 
   digitalWrite(10,LOW); 
   digitalWrite(9,LOW); 
    delay(2000); 
     
     
     digitalWrite(A1,HIGH); 
   digitalWrite(A0,HIGH); 
   digitalWrite(10,HIGH); 
   digitalWrite(9,HIGH); 
  
  
   delay(1000);
   digitalWrite(A1,LOW); 
   digitalWrite(A0,LOW); 
   digitalWrite(10,LOW); 
   digitalWrite(9,LOW); 
   
    delay(2000); 
     
       digitalWrite(11,HIGH); 
   digitalWrite(12,HIGH); 
   digitalWrite(A0,HIGH); 
   digitalWrite(10,HIGH); 
    
  
   delay(1000);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW); 
   digitalWrite(A0,LOW); 
   digitalWrite(10,LOW); 
   delay(2000); 
     
   digitalWrite(11,HIGH); 
   digitalWrite(12,HIGH); 
   digitalWrite(A2,HIGH); 
   digitalWrite(A1,HIGH); 
   digitalWrite(A0,HIGH);
   digitalWrite(10,HIGH); 
  
  
   delay(1000);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW); 
   digitalWrite(A2,LOW); 
   digitalWrite(A1,LOW); 
   digitalWrite(A0,LOW);
   digitalWrite(10,LOW); 
    delay(2000); 
     
     
     
     
     
     
     
   }   
  
}
