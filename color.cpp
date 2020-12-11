#include "color.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

bool color::trueColor(string color){
  if(color != "red" && color != "yellow" && color != "orange" && color != "green" && color != "blue" && color != "purple")
  {
    cout << "Please enter a basic color, like from a rainbow.\n";
    return true;
  }
  else
  {
    return false;
  }
}

string color::choose(string list[3]){
  do
  {
    cout << "What is the color of the top light: ";
    cin >> topColor;
  } while (trueColor(topColor));
  list[0] = topColor;
  do
  {
    cout << "What is the color of the middle light: ";
    cin >> midColor;
  }while (trueColor(midColor));
  list[1] = midColor;
  do
  {
    cout << "What is the color of the bottom light: ";
    cin >> bottomColor;
  } while (trueColor(bottomColor));  
  list[2] = bottomColor;
  return list[2];
}
