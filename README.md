# Color Identification

## Description

The program is to find out what colors a person can and cannot distinguish. The user will enter a color for what they see at a traffic light with simple colors.

#v0.2 Updates

The program will now ask if you would like to alter the colors of the trafficlight. The user can choose the concentration of red, green, or blue from 0 to 255 to alter the color of the chosen light. 

#v1.0 Updates

The program will ask if the user would like to reset the colors of the traffictlight bit map before selecting their colors. The program now has a class that is used to recieve a chosen color and checks for a specific color, then will return the three choices.

## Developer

Idol Moua

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
What is the color of the top light: red
What is the color of the middle light: yellow
What is the color of the bottom light: green
```

## C++ Guide

### Variables and Data Types

Three variables (top, mid, bottom) will store the color as entered and be dtermined if what was entered will match correctly. 

    string top, mid, bottom, name;

### Input and Output

The user will be asked to input three colors for top, mid and bottom.

    cout << "What is the color of the top light: ";
    cin >> top;

### Decisions

If a color does not match the traffic light, the program will choose to write if a person can or cannot see that color for all three.

    if(top != "red")
    {
    results << "Can not distinguish red, " << name << " sees " << top << ".\n";
    }
    else
    {
    results << "Can distinguish red.\n";
    }

### Iteration

If the user does not enter a basic color or mispells, they will be told to enter a basic color and have to renter again. 

    do
    {
    cout << "What is the color of the top light: ";
    cin >> top;
    if (top != "red" && top != "yellow" && top != "orange" && top != "green" && top != "blue" && top != "purple")
    {
    cout << "Please enter a basic color, like from a rainbow.\n";
    }
    } while (top != "red" && top != "yellow" && top != "orange" && top != "green" && top != "blue" && top != "purple");

### File Input and Output

What the user entered will be written and saved to a text file, stating if they can distinguish either of the three colors.

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

### Arrays/Vectors
  The array of three variables will hold the numerical value for red, green, and blue to be used in the bitmap. 

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
          rgb.blue = concentrateValue[1];
          rgb.green = concentrateValue[2];
          bmp [horizontal] [vertical] = rgb;
          light.fromPixelMatrix(bmp);
        }
      }
      cout << "Changed color\n";
    }

### Functions
  Functions are used to remove simpler, lenthgy code out of int main. For the trueColor function would have to be used multiple times in the pregram but, as a function makes it easier to just type out the function instead.

    void colorCheck(string);
    bool trueColor(string);

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

### Classes
  The class is used for collecting color choices and determining if they are basic colors. The three color choices will be returned.

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