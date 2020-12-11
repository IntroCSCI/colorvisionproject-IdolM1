#include <iostream>
#include <fstream>
#include "libraries/bitmap.h"
#include <vector>
#include "color.h"
using namespace std;

void writeFile(fstream &, string[]);
int colorConcentrate();
void colorReset(Bitmap &, Pixel &, vector <vector <Pixel>> &);

int main()
{
  color user;
  string colorSeen [3];
  string choice, input;
  int vertical = 0;
  int concentrateValue [3] = {0,0,0};
  fstream results;
  Bitmap light;
  vector <vector <Pixel> > bmp;
  Pixel rgb;

  light.open("trafficLight.bmp");
  cout << "Do you want to reset the colors of the traffic light? type y to reset or type anything else to continue" << endl;
  cin >> input;
  if(input == "y")
  {
  colorReset(light, rgb, bmp);
  }

  cout << "You stop at an intersection, what are the colors of the trsffic light using basic colors.\n";
 
  colorSeen[2] = user.choose(colorSeen);
  
  results.open("results.txt", ios::app);
  if (results.fail())
  {
    cout << "Error, file did not open.\n";
    return 0;
  }
  
  writeFile(results, colorSeen);
  results.close();
  
  
  
  do
  {
    cout << "Which light would you like to alter the colors of?\n top, mid, bottom, (type quit for no change)\n";
    cin >> choice;
    if(choice == "top")
    {
      cout << "Red concentration: ";
      concentrateValue[0] = colorConcentrate();
      cout << "Green concentration: ";
      concentrateValue[1] = colorConcentrate();
      cout << "Blue concentration: ";
      concentrateValue[2] = colorConcentrate();
      cout << "Please wait\n";
      for (vertical = 0; vertical < 100; vertical++)
      {
        for(int horizontal = 0; horizontal < 100; horizontal++)
        {
          bmp = light.toPixelMatrix();
          rgb = bmp [horizontal] [vertical];
          rgb.red = concentrateValue[0];
          rgb.green = concentrateValue[1];
          rgb.blue = concentrateValue[2];
          bmp [horizontal] [vertical] = rgb;
          light.fromPixelMatrix(bmp);
        }
      }
      cout << "Changed color\n";
    }
    if(choice == "mid")
    {
      cout << "Red concentration: ";
      concentrateValue[0] = colorConcentrate();
      cout << "Green concentration: ";
      concentrateValue[1] = colorConcentrate();
      cout << "Blue concentration: ";
      concentrateValue[2] = colorConcentrate();
      cout << "Please wait\n";
      for (vertical = 0; vertical < 100; vertical++)
      {
        for(int horizontal = 101; horizontal < 200; horizontal++)
        {
          bmp = light.toPixelMatrix();
          rgb = bmp [horizontal] [vertical];
          rgb.red = concentrateValue[0];
          rgb.green = concentrateValue[1];
          rgb.blue = concentrateValue[2];
          bmp [horizontal] [vertical] = rgb;
          light.fromPixelMatrix(bmp);
        }
      }
      cout << "Changed color\n";
    }
    if(choice == "bottom")
    {
      cout << "Red concentration: ";
      concentrateValue[0] = colorConcentrate();
      cout << "Green concentration: ";
      concentrateValue[1] = colorConcentrate();
      cout << "Blue concentration: ";
      concentrateValue[2] = colorConcentrate();
      cout << "Please wait\n";
      for (vertical = 0; vertical < 100; vertical++)
      {
        for(int horizontal = 201; horizontal < 300; horizontal++)
        {
          bmp = light.toPixelMatrix();
          rgb = bmp [horizontal] [vertical];
          rgb.red = concentrateValue[0];
          rgb.green = concentrateValue[1];
          rgb.blue = concentrateValue[2];
          bmp [horizontal] [vertical] = rgb;
          light.fromPixelMatrix(bmp);
        }
      }
      cout << "Changed color\n";
    }
  
    light.save("trafficLight.bmp");
  } while (choice != "quit");

  return 0;
}


int colorConcentrate()
{
  int num;
  cout << "Choose a number between 0 and 255, the higher the number increases the concentration of that color. 0 is none while 255 is all.\n";
  do 
  {
    cin >> num;
  }while(num < 0 || num > 255);
  return num;

}

void writeFile(fstream &results, string list[3])
{
  string name;
  cout << "Please enter your first name for saving results: ";
  cin >> name;
  results << name << endl;
  if(list[0] != "red")
  {
    results << "Can not distinguish red, " << name << " sees " << list[0] << ".\n";
  }
  else
  {
    results << "Can distinguish red.\n";
  }
  if(list[1] != "yellow")
  {
    results << "Can not distinguish yellow, " << name << " sees " << list[1] << ".\n";
  }
  else
  {
    results << "Can distinguish yellow.\n";
  }
  if(list[2] != "green")
  {
    results << "Can not distinguish green, " << name << " sees " << list[2] << ".\n";
  }
  else
  {
    results << "Can distinguish green.\n";
  }
  results << endl;
}

void colorReset(Bitmap & light, Pixel & rgb, vector <vector <Pixel>> &bmp)
{
  for (int vertical = 0; vertical < 100; vertical++)
  {
    for(int horizontal = 0; horizontal < 100; horizontal++)
    {
      bmp = light.toPixelMatrix();
      rgb = bmp [horizontal] [vertical];
      rgb.red = 255;
      rgb.green = 0;
      rgb.blue = 0;
      bmp [horizontal] [vertical] = rgb;
      light.fromPixelMatrix(bmp);
    }
  }
  for (int vertical = 0; vertical < 100; vertical++)
  {
    for(int horizontal = 101; horizontal < 200; horizontal++)
    {
      bmp = light.toPixelMatrix();
      rgb = bmp [horizontal] [vertical];
      rgb.red = 255;
      rgb.green = 255;
      rgb.blue = 0;
      bmp [horizontal] [vertical] = rgb;
      light.fromPixelMatrix(bmp);
    }
  }
  for (int vertical = 0; vertical < 100; vertical++)
  {
    for(int horizontal = 201; horizontal < 300; horizontal++)
    {
      bmp = light.toPixelMatrix();
      rgb = bmp [horizontal] [vertical];
      rgb.red = 0;
      rgb.green = 255;
      rgb.blue = 0;
      bmp [horizontal] [vertical] = rgb;
      light.fromPixelMatrix(bmp);
    }
  }
  light.save("trafficLight.bmp");
}