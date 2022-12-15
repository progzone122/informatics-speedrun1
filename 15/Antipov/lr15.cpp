#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <string> //Для роботи з рядками
#include <fstream>//Бібліотека для керування файловою системою 
#include <map>//мапа

using namespace std;

void new_file(string *FILE_NAME, int *FILE_SIZE){
    string text;//текст рядка
    ofstream out(*FILE_NAME + ".txt", ios::app);//відкриваємо поток для запису в файл
    if (out.is_open()){
        for(int i = 0; i < *FILE_SIZE; i++){
            cout << "Введіть значення: ";
            cin >> text;
            out << text << std::endl;
        }
    }
    out.close();
}
void find_file(string *FILE_NAME, string word){
    int line_index = 0;
    string line;
    int count;
    map <int, string> mp;

    ifstream fin(*FILE_NAME + ".txt", ios::app);
    if(fin.is_open()){
        cout << "-----------------------------------" << endl;
        while (getline(fin, line)){
            line_index++;
            count = 0;
            mp[line_index] = line;
            for (int pos = 0; pos < line.size(); pos += word.size()){
                pos = line.find(word, pos);

                if (pos != std::string::npos){
                    count++;
                }else{
                    break;
                }
            }
            cout << line_index << " рядок: " << count << " збігів" << endl;
    }
        mp.value_comp();
        cout << "-----------------------------------" << endl;
        cout << "Найбільше шуканих слів в рядку: " << (*(mp.rend())).first - 1 << endl;
        cout << "Текст рядка: " << mp[(*(mp.rend())).first - 1] << endl;
        cout << "-----------------------------------" << endl;
    }
    fin.close();
}
int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    int FILE_SIZE = 6; //Кількість рядків в файлі
    string FILE_NAME; //назва файлу
    string word;
    
    cout << "Введіть назву нового файлу: ";
    cin >> FILE_NAME;
    cout << "Введіть кількість рядків у новому файлі: ";
    cin >> FILE_SIZE;

    new_file(&FILE_NAME, &FILE_SIZE);
    cout << "Введіть слово для пошуку: ";
    cin >> word;
    find_file(&FILE_NAME, word);
    return 0;
}