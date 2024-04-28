//Bryce Johnson
//Header files
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

//Create method to handle two digit place values for time
string twoDigitString(unsigned int n) {
    stringstream stringStream;
    //Convert digit to string object
    stringStream << n;

    string timeStamp = stringStream.str();

    //If new string has only one character 0-9, add '0' to the beginning
    if (timeStamp.size() == 1) {
        timeStamp = "0" + timeStamp;
    }
    return timeStamp;
}

//Create method to format input into time structure
string formatTime24(int hour, int minute, int second) {
    string formattedTime = twoDigitString(hour) + ":" + twoDigitString(minute) + ":" + twoDigitString(second);

    return formattedTime;
}

//Create method for printing multiple characters
string nCharString(size_t i, char c) {
    string finalChar;
    for (int j = 0; j < i; ++j) {
        finalChar += c;
    }

    return finalChar;
}

//Create method for menu
void printMenu(string strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*') << endl;
    for (int i = 0; i < numStrings; ++i) {
        cout << "* ";
        cout << i + 1 << " - " << strings[i];
        string currentString = strings[i];
        int spaces = width - 8 - currentString.length();

        cout << nCharString(spaces, ' ');

        cout << " *" << endl;
        if (i != 3) {
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}

int main() {
    //Initiate variables
    string period;
    int display_hour;
    int hour = 0;
    int minute = 0;
    int second = 0;
    int choice = 0;
    string strings[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};

    printMenu(strings, 4, 26);

    //Begin loop for menu screen and time display
    while (choice != 4) {
        cin >> choice;
        //Create different choices to match menu
        if (choice == 1) {
            hour = (hour + 1) % 24;
        }
        else if (choice == 2) {
            minute = (minute + 1) % 60;
        }
        else if (choice == 3) {
            second = (second + 1) % 60;
        }
        //Exit statement
        else if (choice == 4) {
            cout << "Exiting program..." << endl;
        }
        //Error statement
        else {
            continue;
        }

        //Print format to simulate columns
        cout << nCharString(61, '*') << endl;
        cout << "*        12-Hour Clock        *        24-Hour Clock        *" << endl;
        cout << nCharString(61, '*') << endl;

        //Selection of morning or afternoon
        if (hour < 12) {
            period = "AM";
        }
        else {
            period = "PM";
        }

        //Change 24-hour format to 12-hour format
        if (hour == 0) {
            display_hour = 12;
        }
        else {
            if (hour > 12) {
                display_hour = hour - 12;
            }
            else {
                display_hour = hour;
            }
        }

        //Print custom time values
        cout << setw(10) << left << "*" << formatTime24(display_hour, minute, second) << " " << period << setw(10) << right << "*";
        cout << setw(18) << formatTime24(hour, minute, second) << setw(12) << "*" << endl;
        cout << nCharString(61, '*') << endl;
    }

    return 0;
}