#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування
    int ARRAY_SIZE = 6; //змінна розміру масиву
    int *m; //Вказівник для виділення пам'яті під масив
    int min, jmin; //мінімальний елемент та його номер
    int i, j;
    m = new int[ARRAY_SIZE]; //виділяємо пам'ять
    cout << "Введіть 6 дійсних чисел\n";
    for (int i = 0; i < ARRAY_SIZE; i++) { //виконувати цикл, поки істинна умова (ARRAY_SIZE разів)
        cout << "Введіть число: ";
        cin >> m[i]; //Запис в масив
    }
    for (int i = 0; i < ARRAY_SIZE - 1; i++){ //цикл проходу по масиву
        for (j = 0; j < ARRAY_SIZE - i - 1; j++){ // цикл попарного порівняння сусідніх елементів
            if (m[j] > m[j + 1]){ // обмін елементів з номерами j  та j+1
                int a = m[j]; 
                m[j] = m[j + 1]; 
                m[j + 1] = a; 
            }
        }
    }
    cout << "Відсортований массив:\n";
    for (int i = 0; i < ARRAY_SIZE; i++){
        cout << m[i] << "\n";
    }

    return 0;
}