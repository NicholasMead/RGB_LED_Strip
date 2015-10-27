#ifndef __RBGstrip_h__
#define __RBGstrip_h__

#include <arduino.h>

//#typedef byte;

enum Colour
{
  white=0,
  red,
  green,
  blue,
  cyan,
  magenta,
  yellow 
};

class RGBstrip
{
 private:
  int _r_pin, _g_pin, _b_pin;
  byte _r, _g, _b;

 public:

  RGBstrip(int,int,int);

  void setColour(byte, byte, byte);
  void setColour(Colour);
  void setWhite(byte);

  byte* getColour();
  static byte* getColour(Colour);
  };



#endif
