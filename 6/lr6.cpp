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

    cout << "Введіть 10 дійсних чисел\n";
    for (int i = 0; i < 10; i++) { //виконувати цикл, поки істинна умова (10 разів)
        cout << "Введіть число: ";
        cin >> number;
        if (atoi(number) == NULL){ //Перевірка на тип введених данних
            if(atoi(number) != 0){
                cout << "[!] Заборонено вводити рядок замість цифр! \n";
                break;
            }
        }else{
            if(atoi(number) < 0){//Додати до змінної, якщо введені данні від'ємні
                result = result + atoi(number);
            }
        }
    }

    cout << "Сумма від'ємних чисел: " << result << endl;
    
    return 0;
}