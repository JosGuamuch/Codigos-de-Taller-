
int cont;
void setup()
{
  Serial.begin(9600);
   pinMode(8,INPUT);
   pinMode(9,INPUT);
   pinMode(2,INPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
  
}

void loop(){
 if(digitalRead(8)==HIGH){
 Serial.println("Secuencia  velocidad 1");
 for(cont=2;cont<8;cont++){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  
 }    
   for(cont=7;cont>1;cont--){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  }
   
   digitalWrite(2,HIGH); 
   digitalWrite(3,HIGH); 
   digitalWrite(4,HIGH); 
   digitalWrite(5,HIGH); 
   digitalWrite(6,HIGH); 
   digitalWrite(7,HIGH); 
   delay(500);
   digitalWrite(2,LOW); 
   digitalWrite(3,LOW); 
   digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,LOW); 
   digitalWrite(7,LOW); 
   
 }else if(digitalRead(9)==HIGH){
   Serial.println("Secuencia  velocidad 2");
   for(cont=2;cont<8;cont++){
 digitalWrite(cont, HIGH);
   delay(1000);
 digitalWrite(cont, LOW);
   delay(1000);
  }
    for(cont=7;cont>1;cont--){
 digitalWrite(cont, HIGH);
   delay(1000);
 digitalWrite(cont, LOW);
   delay(1000);
    }
 if(digitalRead(8)==HIGH){
 Serial.println("Secuencia  velocidad 1");
 for(cont=2;cont<8;cont++){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  
 }    
   for(cont=7;cont>1;cont--){
 digitalWrite(cont, HIGH);
   delay(500);
 digitalWrite(cont, LOW);
   delay(500);  
  
 }
  
    }
   digitalWrite(2,HIGH); 
   digitalWrite(3,HIGH); 
   digitalWrite(4,HIGH); 
   digitalWrite(5,HIGH); 
   digitalWrite(6,HIGH); 
   digitalWrite(7,HIGH); 
   delay(500);
   digitalWrite(2,LOW); 
   digitalWrite(3,LOW); 
   digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,LOW); 
   digitalWrite(7,LOW);
    }
  }
