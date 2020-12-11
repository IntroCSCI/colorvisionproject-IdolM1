#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class color{
  private:
  string topColor;
  string midColor;
  string bottomColor;
  
  public:
  bool trueColor(string);
  string choose(string[3]);

};

#endif