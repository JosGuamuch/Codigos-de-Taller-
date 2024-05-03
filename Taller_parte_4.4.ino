int cont ;

void setup()
{
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  
  Serial.begin(9600);
  while(digitalRead(3)==HIGH)
        {
    if(cont<100){
         Serial.println(cont);
         cont++;
    delay (100);
        }
  }
   
  while(digitalRead(4)==HIGH)
        {
    if(cont<100&&cont>=0){
         Serial.println(cont);
         cont--;
    delay (100);
        }
  }
}
