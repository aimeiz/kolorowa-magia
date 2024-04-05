#include "led.h"

Led::Led(uint8_t port, unsigned long duration) {
  this->duration = duration;
  this->port = port;
  pinMode(this->port, OUTPUT);
}
Led::~Led() {
  pinMode(this->port, INPUT);
}

uint8_t Led::sinusoida(uint8_t kat) {
  float radianValue = kat * 2 * PI / 255;
  float sinusValue = sin(radianValue);
  // Przeskalowanie wartości sinusoidalnej do zakresu 0-1
  float normalizedSinusValue = (sinusValue + 1) / 2.0;
  // Przemnożenie przez 255, aby uzyskać wartość w zakresie 0-255
  uint8_t sinusUint8_t = normalizedSinusValue * 255;
  return sinusUint8_t;
}

uint8_t Led::ledLoop() {
  long AktualnyCzas = millis();          //aktualny czas systemowy red
  if (AktualnyCzas > this->PoprzedniCzas + this->duration) {
    this->led++;
    this->PoprzedniCzas = AktualnyCzas;
    // analogWrite(port, led);
    this->ledIntensity = sinusoida(this->led);
    analogWrite(this->port, this->ledIntensity);
  }
  return this->led;
}

uint8_t Led::getLed(){
  return this->led;
}

unsigned long Led::getDuration(){
  return this->duration;
}

void Led::setDuration(unsigned long duration){
  this->duration = duration;
}

uint8_t Led::getLedIntensity(){
  return this->ledIntensity;
}
