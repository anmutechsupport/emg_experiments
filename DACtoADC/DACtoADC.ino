#include "analogWave.h"

analogWave wave(DAC);
int freq = 200;
int v;
int v_amp;

void setup() {
  Serial.begin(115200);
  analogWriteResolution(12);  
  wave.sine(freq);
  // wave.freq(freq);
  wave.start();
}

void loop() {
  // v = map(analogRead(A5), 0, 1024, 0, 5);
  v = analogRead(A4);
  // Serial.println(v);
  Serial.print(v);Serial.print(",");

  v_amp = analogRead(A5);
  Serial.println(v_amp);
  // wave.freq(freq);
  // delay(1000);
}