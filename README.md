# Color Identification

## Description

The program is to find out what colors a person can and cannot distinguish. The user will enter a color for what they see at a traffic light with simple colors.

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