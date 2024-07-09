#include <Adafruit_NeoPixel.h>
#define pin 2
#define num_pixels 1
#define pin_trig 11
#define pin_echo 3

Adafruit_NeoPixel pixel(num_pixels, pin, NEO_GRB + NEO_KHZ800);

bool cont[11][7]
{
  {0,1,1,1,1,1,1},
  {0,0,1,0,0,0,1},
  {1,0,1,1,1,1,0},
  {1,0,1,1,0,1,1},
  {1,1,1,0,0,0,1},
  {1,1,0,1,0,1,1},
  {1,1,1,1,0,1,1},
  {0,0,1,1,0,0,1},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,0,1},
  {0,0,0,0,0,0,0},
};

int fil_cont=0;
int col_cont=0;
float max = 10;
float min = 6;

float distancia (void);
void display (void);

void setup()
{
  Serial.begin(9600);
  Serial.println("Contador de Aforo");
  pixel.begin();
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(pin_trig, LOW);
}

void loop()
{
  pixel.setPixelColor(0, pixel.Color(0,200,0));
 
  distancia();
  if (fil_cont<9)
  {
    display();
    pixel.setPixelColor(0, pixel.Color(0,200,0));
    pixel.show();

  }
  if (fil_cont==9)
  {
    display();
    pixel.setPixelColor(0, pixel.Color(0,200,0));
    pixel.show();
    delay (1000);
    display();
    fil_cont=11;
  }
  if (fil_cont==11)
  {
    pixel.setPixelColor(0, pixel.Color(200,0,0));
    pixel.show();
    for(int c=4; c<=10; c++)
    {
    digitalWrite(c,LOW);
    col_cont++;
    }
    digitalWrite(4, HIGH);
  }
  delay (100);
  Serial.print(fil_cont);
  }

float distancia (void)
{
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
 
  long tiem_echo = pulseIn(pin_echo, HIGH);
  long dis = tiem_echo/59;
 
  if (dis<max && dis>min)
  {
    fil_cont++;
  }

  return dis;
}

void display (void)
{
  col_cont=0;
  for(int c=4; c<=10; c++)
  {
    digitalWrite(c, cont[fil_cont][col_cont]);
    col_cont++;
  }
}
