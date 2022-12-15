#include <iostream>
#include <stdio.h>

using namespace std;

int main() {    
    int rows, cols, sum=0;
    int max[] = {0,0};

    cout << "enter: rows, cols" << endl; 
    cin >> rows >> cols;

    // Allocating 2d array 
    int**array = new int*[cols];
    for (int i = 0; i < cols; i++) {
        array[i] = new int [rows];
    }

    // Entering data to matrix
    cout << "enter matrix: " << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << "enter ["<<i<<","<<j<<"] element: "; 
            cin >> array[i][j]; 
        }
    }

    // printing array
    cout << "array:" << endl;
    for (int i = 0; i < cols; i++) {
        cout << endl;
        for (int j = 0; j < rows; j++) {
            printf("%3d ", array[i][j]); 
        }
    }

    // find max in matrix and count sum of positive numbers
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (array[i][j] > 0) 
                sum+= array[i][j];
            if (array[i][j] > array[max[0]][max[1]]) {
                max[0] = i;
                max[1] = j;
            }
        }
    }

    cout << "max value: " << array[max[0]][max[1]] << endl;
    cout << "sum of positive elems: " << sum << endl;

    // Deallocating 2d array 
    for (int i = 0; i < cols; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = NULL;
    
    return 0;
}
