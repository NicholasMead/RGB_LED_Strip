#include "RGBstrip.h"

RGBstrip::RGBstrip(int r, int g, int b): _r_pin(r), _g_pin(g), _b_pin(b), _r(0), _g(0), _b(0)
{
  pinMode(r,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
}

void RGBstrip::setColour(byte r, byte g, byte b)
{
  analogWrite(_r_pin,r);
  analogWrite(_g_pin,g);
  analogWrite(_b_pin,b);

  _r = r;
  _g = g;
  _b = b;
}

void RGBstrip::setColour(Colour _Colour)
{
  switch(_Colour)
    {
    case white:
      setColour(255,255,255);
      break;

    case red:
      setColour(255,0,0);
      break;

    case green:
      setColour(0,255,0);
      break;

    case blue:
      setColour(0,0,255);
      break;

    case cyan:
      setColour(0,255,255);
      break;
   
    case magenta:
      setColour(255,0,255);
      break;

    case yellow:
      setColour(255,255,0);
      break;

    default:
      setColour(0,0,0);
      break;
    } 
}

byte* RGBstrip::getColour(Colour _Colour)
{
  switch(_Colour)
    {
    case white:
      return new byte[3]{255,255,255};

    case red:
      return new byte[3]{255,0,0};

    case green:
      return new byte[3]{0,255,0};
        
    case blue:
      return new byte[3]{0,0,255};

    case cyan:
      return new byte[3]{0,255,255};
   
    case magenta:
      return new byte[3]{255,0,255};

    case yellow:
      return new byte[3]{255,255,0};

    default:
      return new byte[3]{0,0,0};
    } 
}

void RGBstrip::setWhite(byte w)
{
  setColour(w,w,w);
}

byte* RGBstrip::getColour()
{
  byte *Colour = new byte[3]{_r,_g,_b};
  return Colour;
}
