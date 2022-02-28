/*
Author: Sakib Khan
Course: CSCI-135
Instructor: Tong Yi
Assignment: Reverse Order
Asks user for two dates and 
will give West basin elevation for 
all days in between in reverse
chronological order
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main()
{
    string first, last;
    cout << "Enter earlier date: ";
    cin >> first;
    cout << "Enter later date: ";
    cin >> last;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if it can't open file
    }
    string junk;        
    getline(fin, junk);  
    string date;
    double eastSt, eastEl, westSt, westEl, minimum, maximum;
    string dates [400]; //array for dates
    double elevations [400]; 
    int amount = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        if (date >= first && date <= last)
        {
            dates[amount] = date;
            elevations[amount] = westEl;
            amount++;
        }
    }
    fin.close();
    for (int i = amount - 1; i >= 0; i--)
        cout << dates[i] << " " << elevations[i] << endl;
    return 0;
}
