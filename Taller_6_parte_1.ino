#include <LiquidCrystal.h>

#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LiquidCrystal Jose_G( RS, E,D4,D5,D6,D7);

void setup()
{
  Jose_G.begin(16,2);
  Jose_G.setCursor(3,0);
  Jose_G.print("Jose Guamuch");
  Jose_G.setCursor(5,1);
  Jose_G.print("2023069");      
}

void loop()
{
}
