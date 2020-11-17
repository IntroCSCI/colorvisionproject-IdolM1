#include <iostream>
#include <fstream>
#include "libraries/bitmap.h"
#include <vector>
using namespace std;

void colorCheck(string);
bool trueColor(string);
void writeFile(fstream &, string, string, string);
int colorConcentrate();

int main()
{
  string top, mid, bottom, choice;
  int vertical = 0;
  int concentrateValue [3] = {0,0,0};
  fstream results;
  Bitmap light;
  vector <vector <Pixel> > bmp;
  Pixel rgb;

  cout << "You stop at an intersection, what are the colors of the trsffic light using basic colors.\n";
  do
  {
    cout << "What is the color of the top light: ";
    cin >> top;
    colorCheck(top);
  } while (trueColor(top));

  do
  {
    cout << "What is the color of the middle light: ";
    cin >> mid;
    colorCheck(mid);
  }while (trueColor(mid));

  do
  {
    cout << "What is the color of the bottom light: ";
    cin >> bottom;
    colorCheck(bottom);
  } while (trueColor(bottom));  

  results.open("results.txt", ios::app);
  if (results.fail())
  {
    cout << "Error, file did not open.\n";
    return 0;
  }
  
  writeFile(results, top, mid, bottom);
  results.close();
  
  light.open("trafficLight.bmp");
  
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
      for (vertical = 201; vertical < 300; vertical++)
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

void colorCheck(string color)
{
  if (trueColor(color))
    {
      cout << "Please enter a basic color, like from a rainbow.\n";
    }
}

bool trueColor(string color)
{
  if(color != "red" && color != "yellow" && color != "orange" && color != "green" && color != "blue" && color != "purple")
  {
    return true;
  }
  else
  {
    return false;
  }
}

void writeFile(fstream &results, string top, string mid, string bottom)
{
  string name;
  cout << "Please enter your first name for saving results: ";
  cin >> name;
  results << name << endl;
  if(top != "red")
  {
    results << "Can not distinguish red, " << name << " sees " << top << ".\n";
  }
  else
  {
    results << "Can distinguish red.\n";
  }
  if(mid != "yellow")
  {
    results << "Can not distinguish yellow, " << name << " sees " << mid << ".\n";
  }
  else
  {
    results << "Can distinguish yellow.\n";
  }
  if(bottom != "green")
  {
    results << "Can not distinguish green, " << name << " sees " << bottom << ".\n";
  }
  else
  {
    results << "Can distinguish green.\n";
  }
  results << endl;
}
