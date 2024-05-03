
int cont = 0;
#define PUL1 2
#define PUL2 3
#define PUL3 4
void setup()
{
  Serial.begin(9600);
  pinMode(PUL1,INPUT);
  pinMode(PUL2,INPUT);
  pinMode(PUL3,INPUT);
}

void loop()
{
   for(cont=0 ;cont<10 ;cont++){ 
  if(digitalRead(PUL1)== HIGH){
    delay (1000);
  } else if(digitalRead(PUL2)== HIGH){
    delay (2000);
  } else if(digitalRead(PUL3)== HIGH){
    delay (3000); }
     
  Serial.println(cont);
     delay(500);
  }
}
