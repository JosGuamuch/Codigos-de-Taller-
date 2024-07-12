#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define direccion_lcd 0x27  // Asegúrate de que la dirección I2C es correcta
#define filas 2
#define columnas 16

#define canal0_pot A0
#define sensor_IR 2 
#define sensor_hall 3
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

bool state_IR;
unsigned int valor_adc_pot;
unsigned int speed_motor;
volatile int contador = 0;
unsigned long tiempo_actual = 0;
unsigned long ultimo_tiempo = 0;

LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);

int paso[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

const int stepsPerRevolution = 200;  // Ajusta según tu motor paso a paso
volatile int stepCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(canal0_pot, INPUT);
  pinMode(sensor_IR, INPUT);
  pinMode(sensor_hall, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 1);
  lcd.print("Bienvenidos");
  


  attachInterrupt(digitalPinToInterrupt(sensor_hall), Interrupcion, FALLING); 
}

void loop() {
  sensor();
 
}

void Interrupcion() {
  contador++;
}

void moverMotor() {
  valor_adc_pot = analogRead(canal0_pot);
  speed_motor = map(valor_adc_pot, 0, 1023, 1000, 100);  // Ajusta la velocidad

  for (int i = 0; i < 8; i++) {
    digitalWrite(IN1, paso[i][0]);
    digitalWrite(IN2, paso[i][1]);
    digitalWrite(IN3, paso[i][2]);
    digitalWrite(IN4, paso[i][3]);
    delayMicroseconds(speed_motor);
    
    stepCounter++;
    if (stepCounter >= stepsPerRevolution) {
      stepCounter = 0;
      contador++;
    }
  }
}

void sensor() {
  state_IR = digitalRead(sensor_IR);
  if (state_IR == LOW) {
    moverMotor();
  } else {
    // Detener el motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
