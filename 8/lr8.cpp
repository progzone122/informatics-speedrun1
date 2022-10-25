#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування
    int number; //змінна для введеного числа користувачем
    int buffer; //змінна для буферу
    int m[6]; //Початковий масив
    int max, min, minIndex, maxIndex; //змінні для максимуму та мінімуму та їх індекси

    cout << "Введіть 6 дійсних чисел\n";
    for (int i = 0; i < 6; i++) { //виконувати цикл, поки істинна умова (6 разів)
        cout << "Введіть число: ";
        cin >> number;
        if(number % 2 == 0){ //Долучити до масиву якщо парне 
            m[i] = number;
        }
    }
    //Ініциалізація
    min = m[0];
    max = m[0];
    minIndex = 0;
    maxIndex = 0;
    
    for (int i = 0; i < 6; i++){
        if(m[i] >= max){ //Знаходимо максимум
            max = m[i];
            maxIndex = i;
        }
        if(m[i] <= min){ //Знаходимо мінімум
            min = m[i];
            minIndex = i;
        }
    }

    buffer = m[maxIndex];
    m[maxIndex] = m[minIndex];
    m[minIndex] = buffer; //Оновлюємо масив

    cout << "\nРезультат:\n";
    for (int i = 0; i < 6; i++){ //Виводимо результат
        if(m[i] == 0){
            cout << "відсутній" << "\n"; 
        }else{
            cout << m[i] << "\n"; 
        }
    }
    cout << "Мінімум: " << min << "\n"
        << "Максимум: " << max << "\n";
    return 0;
}