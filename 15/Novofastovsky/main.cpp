#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    fstream file; // file
    string line; // buffer for reading lines from file 
    int rows; // rows in file 
    char c; // specific character
    string lessSpecCharStr; // string that contains minimum amount of specific characters in the end of the words
    // counters 
    int minCounter = 9999999; // counter for words that ends with specific character
    int nowCounter; // current (in cycle) counter for words that ends with specific character

    // entering no of rows
    cout << "Enter number of rows in file: ";
    cin >> rows; 
    // opening the file 
    cout << "Enter rows" << endl;
    file.open("Novofastovskiy.txt", ios::out);
    if (file.is_open()) { // check if file is opened
        // entering lines in file  
        for (int i = 0; i < rows; i++) {
            cout << "Row #" << i << ": ";  
            cin.sync();
            getline(cin, line);
            file << line << " " << endl;
        }        
        file.close(); 
    }

    // find specific character
    cout << " Enter the symbol that should end with the words that will be counted\n--symbol: ";
    cin >> c;
    file.open("Novofastovskiy.txt", ios::in);
    if (file.is_open()) { // check if file is opened
        while(getline(file, line)) {
            nowCounter = 0;
            for (int i=0; i<=line.length(); i++) { // check every element
                if (line[i-1] == c && line[i] == ' ') {
                    nowCounter++;
                }
            }
            if (nowCounter < minCounter && nowCounter > 0) {
                minCounter = nowCounter;
                lessSpecCharStr = line; // saving line for later
            }
        }
        file.close(); 
    }

    if (minCounter != 9999999) {
        cout << "The line with the least number of words with searched element" << endl << lessSpecCharStr << endl;
    }
    else {
        cout << "No word was found in all lines ending with the searched element" << endl;
    }

    return 0;
}