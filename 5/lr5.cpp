#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <cstdlib> //Бібліотека для перетворення типів змінних

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування
    
    char number[12]; //Змінна для введеного числа
    int result = 0; //Змінна для результату обчислень

    cout << "Введіть цілі числа по порядку (крім 100): \n";
    cout << "Введіть число 100 для вихіду з циклу \n\n";
    while (atoi(number) != 100) {
        cout << "Введіть число: ";
        cin >> number;
        if (atoi(number) == NULL){ //Перевірка на тип введених данних
            cout << "[!] Заборонено вводити рядок замість цифр! \n";
            break;
        }else{
            result = result + atoi(number);
        }
        if(atoi(number) == 100){ //Виводимо результат якщо було введне число 100
            cout << "Результат: " << result << "\n";
            break;
        }
    }
    
    return 0;
}