#include <iostream>
#include <fstream> // 
#include <string> // .length
#include <sstream> // .rdbuf()
#include <vector> // .push_back()


using namespace std;

// void write(string filename)
void write(string filename) {
    fstream file_write;
    string line;
    int linesCount;

    cout << "Введіть скільки рядків ввести:";
    cin >> linesCount;

    file_write.open(filename, ios::out);
    if (file_write.is_open()) {
        for (int i = 0; i < linesCount; i++) {
            cout << "Введіть рядок:";
            cin.sync();
            getline(cin, line);
            file_write << line << endl;
        }
    }
    file_write.close();
}


// void findSmallWords(string filename) 
void findSmallWords(string filename) {
    ifstream file_read(filename);
    vector <string> stringlist;
    string line;

    if (file_read) {
        stringstream buffer;
        buffer << file_read.rdbuf();

        // pushing stream to vector
        while (getline(buffer, line, ' '))
            stringlist.push_back(line);
        
        // iterating trough each element to find element with length == 1
        for (auto i: stringlist) 
            if (i.length() == 1) 
                cout << "small word: " << i << endl;
        
        file_read.close();
    }
}


int main() {

    write("strings.txt");
    findSmallWords("strings.txt");

    return 0;
}
