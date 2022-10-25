#include <iostream>

using namespace std;


int main()
{

    int width, height, sum = 0, flag = 0;

    cout << "Введіть розміри масиву (Висота та Ширина через пробіл): ";
    cin >> height >> width;
    
    int array[height][width];

    // Ввід масиву
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
                cout << "Введіть [" << i << "," << j << "] елемент: ";
                cin >> array[i][j];
        }

    // Обраховування масиву 
    // Обчислити суму додатних непарних елементів у кожному із стовпчиків.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
                if (array[i][j] % 2 > 0 && array[i][j] > 0) {
                    sum += array[i][j];
                    flag = 1;
                }
            }
    }
    // Вивід масиву
    cout << "\nмассив: ";
    for (int i = 0; i < height; i++) {
        cout << "\n";
        for (int j = 0; j < width; j++) {
                cout << array[i][j]<< " ";
            }
    }

    if (flag == 1) 
        cout << "\nСумма непарних елементів: " << sum << endl;
    else
        cout << "\nВ масиві не було знайдено жодного непарного елемента.\n";

    return 0;
}