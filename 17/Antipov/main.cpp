#include <iostream>
#include <windows.h>

using namespace std;

int main() {
SetConsoleCP(65001);
SetConsoleOutputCP(65001);

int rows, cols;
cout << "Введіть кількість рядків та стовпців: " << endl;
cin >> rows >> cols;

// виділяємо пам'ять для двовимірного динамічного масиву
int **array = new int *[rows];
for (int i = 0; i < rows; i++) {
array[i] = new int[cols];
}

cout << "Введіть матрицю:" << endl;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
cout << "Введіть [" << i << "," << j << "] елемент: ";
cin >> array[i][j];
}
}

cout << "Матриця:" << endl;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
cout << array[i][j] << " ";
}
cout << endl;
}

// проходимо по кожному стовпцю матриці
for (int j = 0; j < cols; j++) {
int max_elem = array[0][j];
double sum = 0;
int count = 0;

// проходимо по кожному елементу в стовпці
for (int i = 0; i < rows; i++) {
  if (array[i][j] < 0) {
    sum += array[i][j];
    count++;
  }
  if (array[i][j] > max_elem) {
    max_elem = array[i][j];
  }
}

cout << "Максимальний елемент в стовпці " << j << ": " << max_elem << endl;
if (count == 0) {
  cout << "У стовпці " << j << " немає від'ємних елементів" << endl;
} else {
  double avg = sum / count;
  cout << "Середнє арифметичне від'ємних елементів в стовпці " << j
       << ": " << avg << endl;
}

}

// звільняємо виділену пам'ять
for (int i = 0; i < rows; i++) {
delete[] array[i];
}
delete[] array;

return 0;
}