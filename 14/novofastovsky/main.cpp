#include <iostream> // для вводу та виводу 
#include <Windows.h> // для кодування
#include <cstdlib>

using namespace std; 


void shift (int array[], int len) 
{
  int min = array[0];
  // find min
  for (int i = len-1; i >= 0; i--) if (array[i] < min) min = array[i];
  // Елементи, що задовольняють вказаній умові замінити нулями та розмістити в кінці масиву.
  for (int i = 0, s = len-1; i < len; i++) {
    if (array[i] == min) {
      array[i] = array[s];
      array[s] = 0;
      s--;
    }
  }
}

int afterMax(int array[], int len) {
    int max=array[0];
    int sum = 0;
    // find max
    for (int i = len-1; i >= 0; i--) if (array[i] > max) max = array[i];
    // calculate sum after max element
    for (int i = len-1; i >= 0; i--) 
        if (array[i] == max) {
            break;
        }
        else {
            sum += abs(array[i]);
        }
    return sum;
}



int main() {
  SetConsoleOutputCP(65001); // Встановлення кодування
  SetConsoleCP(65001); // Встановлення кодування
  
  int len; // Довжина масиву
  int sum = 0;
  int option; // Змінна варіанту меню
  
  
  cout << "Eneter array length: ";
  cin >> len;
  
  int array[len]; // Створення масиву введеної довжини  

  // Введеня елементів масиву 
  for (int i = 0; i < len; i++) {
    cout << "Enter array element: ";
    cin >> array[i];
  }

  cout << "\n1. Calculate sum after max element \n2. compress the array (replace it with 0) by removing all the minimal elements and also by removing the elements that satisfy the condition \n3. Stop the program" << endl;
  cout << "\nEnter option number: ";
  cin >> option;

  switch (option) {
    case 1:
      // Підрахунок суми елементів масиву між першим та останнім додатнім елементом
      sum = afterMax(array, len);
      cout << "\nSum between first and last positive element " << sum << endl;
      break;
    case 2:  
      // стиснути масив
      shift(array, len);
      // Виведення елементів масиву 
      for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
      }
      break;
    default:
      cout << "Program stopped";
      break;
  }

  return 0;
}