#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <string> //Для роботи з рядками
#include <fstream>//Бібліотека для керування файловою системою 

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    int FILE_SIZE = 6; //Кількість рядків в файлі
    string FILE_NAME; //назва файлу
    string text;//текст рядка

    cout << "Введіть назву нового файлу: ";
    cin >> FILE_NAME;
    cout << "Введіть кількість рядків у новому файлі: ";
    cin >> FILE_SIZE;

    ofstream out(FILE_NAME + ".txt", ios::app);//відкриваємо поток для запису в файл
    if (out.is_open()){
        for(int i = 0; i < FILE_SIZE; i++){
            cout << "Введіть значення: ";
            cin >> text;
            out << text << std::endl;
        }
    }
    out.close(); 
    return 0;
}