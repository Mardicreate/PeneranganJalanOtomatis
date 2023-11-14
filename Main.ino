#include <Arduino.h>

// Var_Declare
uint8_t LDR = A0, pinled = 6, sensorpir = 4;
uint32_t data;
bool PIR = 0;

void setup() {
  pinMode(LDR, INPUT);      // Set LDR pin as input
  pinMode(pinled, OUTPUT);  // Set pinled pin as output
  pinMode(sensorpir, INPUT);
  digitalWrite(pinled, LOW);
  Serial.begin(9600);
}

void loop() {
  // SENSOR_READING---------------------
  PIR = (bool)digitalRead(sensorpir);
  data = analogRead(LDR);
  //-----------------------------------

  Serial.println(PIR);
  Serial.println(data);
  // LOGIC_SECTION-----------
  if (PIR == 1 && data <= 500) {
    digitalWrite(pinled, HIGH);
  } else {
    digitalWrite(pinled, LOW);
  }
}
