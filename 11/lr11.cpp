#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <string> //Для роботи з рядками

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    string s1, s2, s3; //рядки користувацьких значень
    string result; //фінальний рядок
    int s2_size = 0; //довжина рядка s2;
    int amount = 0; //змінна для кількості "*" в рядку result

    cout << "Введіть значення s1: ";
    cin >> s1;
    cout << "Введіть значення s2: ";
    cin >> s2;
    cout << "Введіть значення s3: ";
    cin >> s3;
    
    s2_size = s2.length(); //дізнаємося довжину рядка s2
    s1.insert(0, s2.substr(0, 1)); //вставляємо на початок рядка s1 перший символ s2
    s1.insert(1, s2.substr(s2.length() - 1, s2.length())); //вставляємо на початок рядка після першого символа s1 останній символ s2
    result = s2 + s3; //З'єднуємо рядки s2 та s3 і записуємо в рядок result

    //кількість "*" в рядку result
    for (size_t i = 0; result.find("*", i) != string::npos && i <= result.length(); ++i){
        amount++;
    }

    //виводимо результат на екран
    cout << "Фінальний рядок (result): " << result << endl;
    cout << "Кількість '*' в фінальному рядку (result): " << amount << endl;
    return 0;
}