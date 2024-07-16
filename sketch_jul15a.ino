#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

long int movimiento;
long int movimiento1;
long int movimiento2;
long int MV;
int MV1;

ADXL345 acelerometro_ADXL345 = ADXL345();

int x;
int y;
int z;

SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

long int customSqrt(long int val) {
  long int res = 0;
  long int bit = 1L << 30; // The second-to-top bit is set.

  // "bit" starts at the highest power of four <= the argument.
  while (bit > val) {
    bit >>= 2;
  }

  while (bit != 0) {
    if (val >= res + bit) {
      val -= res + bit;
      res = (res >> 1) + bit;
    } else {
      res >>= 1;
    }
    bit >>= 2;
  }
  return res;
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Uso del acelerometro ADXL345");
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(8);

  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer Mini not detected.");
    while (true);
  }
  myDFPlayer.volume(20);  // Set volume to 20 (range from 0 to 30)

  for (int i = 2; i <= 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void loop() {
  acelerometro_ADXL345.readAccel(&x, &y, &z);
  Serial.print("La aceleracion en x es de: ");
  Serial.println(x);
  Serial.print("La aceleracion en y es de: ");
  Serial.println(y);
  Serial.print("La aceleracion en z es de: ");
  Serial.println(z);
  delay(500);

  movimiento = (x * x) + (y * y) + (z * z);
  movimiento1 = customSqrt(movimiento);
  movimiento2 = movimiento1 / 0.06;

  MV = map(movimiento2, 465, 2000, 45, 15000);
  MV1 = map(MV, 45, 15000, 0, 11);
  Serial.println(MV1);

  for (int i = 2; i <= 12; i++) {
    if (i <= MV1 + 1) {
      digitalWrite(i, LOW);  // Turn on the LEDs up to the current level
    } else {
      digitalWrite(i, HIGH); // Turn off the LEDs above the current level
    }
  }

  // Play sound when the highest level is reached
  if (MV1 >= 11) {
    myDFPlayer.play(1); // Play the first MP3 file on the SD card
    delay(5000);        // Delay to prevent multiple triggers
  }
}
