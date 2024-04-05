/* Kolorowa magia RGB */
//Katodę LED RGB podłącz do GND
#include "led.h"
#define DEBUG
#define RED 9     //Podłącz czerwony pod ten port przez opornik 200 - 1000 om
#define GREEN 10  //Podłącz czerwony pod ten port przez opornik 200 - 1000 om
#define BLUE 11   //Podłącz czerwony pod ten port przez opornik 200 - 1000 om
// #define POTENCJOMETR A7

Led red(RED, 100);      //Utworzono obiekt klasy Led port RED, duration 20
Led green(GREEN, 200);  //Utworzono obiekt klasy Led port GREEN, duration 15
Led blue(BLUE, 300);    //Utworzono obiekt klasy Led port BLUE, duration 10

float fmap(int input, int inputLow, int inputHigh, float outputLow, float outputHigh ){
   if (inputLow >= inputHigh) {
        // Jeśli tak, zwróć błąd
        printf("Error: inputLow must be less than inputHigh");
        return 0.0; // Zwracam 0, ale można też zwrócić wartość oznaczającą błąd
    }

    // Skalowanie wartości wejściowej do zakresu 0-1
    float normalizedInput = (float)(input - inputLow) / (float)(inputHigh - inputLow);

    // Mapowanie wartości z zakresu 0-1 na zakres outputLow-outputHigh
    float output = outputLow + normalizedInput * (outputHigh - outputLow);

    return output;

}

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif
}

void loop() {
  red.ledLoop();
  green.ledLoop();
  blue.ledLoop();
// float potencjometr = fmap(analogRead(POTENCJOMETR), 0, 1023, 0.1, 10.0);
// red.setDuration((unsigned long)(potencjometr * red.getDuration()));
// green.setDuration((unsigned long)(potencjometr * green.getDuration()));
// blue.setDuration((unsigned long)(potencjometr * blue.getDuration()));

#ifdef DEBUG
  // Serial.print("Potencjometr ");
  // Serial.print(potencjometr);
  Serial.print(" red ");
  Serial.print(red.getLed());
  Serial.print(" sinusoida(red) ");
  Serial.print(red.getLedIntensity());
  Serial.print(" green ");
  Serial.print(green.getLed());
  Serial.print(" sinusoida(green) ");
  Serial.print(green.getLedIntensity());
  Serial.print(" blue ");
  Serial.print(blue.getLed());
  Serial.print(" sinusoida(blue) ");
  Serial.println(blue.getLedIntensity());
#endif
}
