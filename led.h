#ifndef LED_H
#define LED_H
#include <arduino.h>

class Led {
public:
  Led(uint8_t port, unsigned long duration);
  ~Led();

  uint8_t getLed();
  unsigned long getDuration();
  void setDuration(unsigned long duration);
  uint8_t getLedIntensity();
  uint8_t ledLoop();

private:
  uint8_t port;
  unsigned long PoprzedniCzas;
  unsigned long duration;
  uint8_t led;
  uint8_t ledIntensity;  //Intensywność świecenia led
  uint8_t sinusoida(uint8_t kat);
};

#endif