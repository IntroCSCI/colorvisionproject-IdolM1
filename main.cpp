#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  string top, mid, bottom, name;
  fstream results;

  cout << "You stop at an intersection, what are the colors of the trsffic light using basic colors.\n";
  do
  {
    cout << "What is the color of the top light: ";
    cin >> top;
    if (top != "red" && top != "yellow" && top != "orange" && top != "green" && top != "blue" && top != "purple")
    {
      cout << "Please enter a basic color, like from a rainbow.\n";
    }
  } while (top != "red" && top != "yellow" && top != "orange" && top != "green" && top != "blue" && top != "purple");

  do
  {
    cout << "What is the color of the middle light: ";
    cin >> mid;
    if (mid != "red" && mid != "yellow" && mid != "orange" && mid != "green" && mid != "blue" && mid != "purple")
    {
      cout << "Please enter a basic color, like from a rainbow.\n";
    }
  }while (mid != "red" && mid != "yellow" && mid != "orange" && mid != "green" && mid != "blue" && mid != "purple");

  do
  {
    cout << "What is the color of the bottom light: ";
    cin >> bottom;
    if (bottom != "red" && bottom != "yellow" && bottom != "orange" && bottom != "green" && bottom != "blue" && bottom != "purple")
    {
      cout << "Please enter a basic color, like from a rainbow.\n";
    }
  } while (bottom != "red" && bottom != "yellow" && bottom != "orange" && bottom != "green" && bottom != "blue" && bottom != "purple");  

  results.open("results.txt", ios::app);
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
  results.close();

  return 0;
}
