#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdlib>

int* HSVtoRGB(int h, double s, double v)
{
  double c = s*v;

  double x = c * (1 - ((h/60) % 2 - 1));

  double m = v - c;

  double* _RGB;

  if (0 <= h && h < 60) _RGB = new double[3]{c,x,0};
  else if (60 <= h && h < 120) _RGB = new double[3]{x,c,0};
  else if (120 <= h && h < 180) _RGB = new double[3]{0,c,x};
  else if (180 <= h && h < 240) _RGB = new double[3]{0,x,c};
  else if (240 <= h && h < 300) _RGB = new double[3]{x,0,c};
  else if (300 <= h && h < 360) _RGB = new double[3]{c,0,x};

  int* RGB = new int[3]
    {
      static_cast<int>((_RGB[0]+m)*255),
      static_cast<int>((_RGB[1]+m)*255),
      static_cast<int>((_RGB[2]+m)*255)
    };

  return RGB;
}

int main(int argc, char** argv)
{
  if (argc < 4 || argc > 4)
    std::cerr << "Please provide <R> <G> <B>" << std::endl;
  else
    {
      int* RGB = HSVtoRGB(atoi(argv[1]), atof(argv[2]), atof(argv[3])); 
      std::cout << RGB[0] << " | "
		<< RGB[1] << " | "
		<< RGB[2] << std::endl;
    }
  return 0;
}

