#include <iostream>
#include <windows.h> //Для установки кодировки

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    int value; //Змінна зберігання вибору користвуча
    int x, a, c, b; //Невідомі числа в рівнянні

    cout << "1) 1 / a * x - b\n"
        << "2) x - a / x\n"
        << "3) 10 * x / c - 4\n\n"
        << "Виберіть рівняння (1-3): ";
    cin >> value;

    switch(value){
        case 1:
            cout << "Введіть a: ";
            cin >> a;
            cout << "Введіть x: ";
            cin >> x;
            cout << "Введіть b: ";
            cin >> b;
            if(a * x - b > 0){
                cout << "Результат: " <<  1 / a * x - b << "\n";   
            }else{
                cout << "Функція не визначена!\n";   
            }
            break;
        case 2:
            cout << "Введіть a: ";
            cin >> a;
            cout << "Введіть x: ";
            cin >> x;
            if(x > 0){
                cout << "Результат: " <<  x - a / x << "\n";   
            }else{
                cout << "Функція не визначена!\n";   
            }
            break;
        case 3:
            cout << "Введіть x: ";
            cin >> x;
            cout << "Введіть c: ";
            cin >> c;
            if(c - 4 > 0){
                cout << "Результат: " <<  10 * x / c - 4 << "\n";   
            }else{
                cout << "Функція не визначена!\n";   
            }
            break;
    }

	return 0;
}
