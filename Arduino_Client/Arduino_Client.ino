#include "RGBstrip.h"

//#define __debug__

RGBstrip LED(10, 9, 11);

void setup() {
  LED.setColour (255, 255, 255);
  randomSeed(analogRead(0));
#ifdef __debug__
  Serial.begin(9600);
#endif
}

void loop() {

  byte* colourStart = LED.getColour();

  byte* colourFade = new byte[3] {0, 0, 0};

  Colour newColour = static_cast<Colour>(random(7));
  byte* colourEnd = RGBstrip::getColour(newColour);

#ifdef __debug__
  Serial.println();
  Serial.print("**");
  for (int i(0); i < 3; i++)
  {
    Serial.print(colourEnd[i]);
    Serial.print(" | ");
  }
#endif

  for (int i(0); i < 256; i++)
  {
    for (int j(0); j < 3 ; j++)
    {
      colourFade[j] = map(i , 0, 255, colourStart[j], colourEnd[j]);
    }
    LED.setColour(colourFade[0], colourFade[1], colourFade[2]);
    delay(25);
    
#ifdef __debug__
    Serial.println();
    for (int i(0); i < 3; i++)
    {
      Serial.print(colourFade[i]);
      Serial.print(" | ");
    }
#endif

  }

  delay (10000);

  delete[] colourFade;
  delete[] colourEnd;

}
