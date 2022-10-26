#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <string> //Для роботи з рядками

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    string s[3]; //массив користувацьких значень
    string result; //фінальний рядок
    int s2_size = 0; //довжина рядка s2;
    int amount = 0; //змінна для кількості "*" в рядку result

    for(int i = 0; i <= 2; i++){
        cout << "Введіть значення s" << i + 1 << ": ";
        cin >> s[i];
    }
    
    s2_size = s[1].length(); //дізнаємося довжину рядка s2
    s[0].insert(0, s[1].substr(0, 1)); //вставляємо на початок рядка s1 перший символ s2
    s[0].insert(1, s[1].substr(s[1].length() - 1, s[1].length())); //вставляємо на початок рядка після першого символа s1 останній символ s2
    result = s[1] + s[2]; //З'єднуємо рядки s2 та s3 і записуємо в рядок result

    //кількість "*" в рядку result
    for (int i = 0; (i = result.find("*", i)) != string::npos; i++){
        amount++;
    }

    //виводимо результат на екран
    cout << "Фінальний рядок (result): " << result << endl;
    cout << "Кількість '*' в фінальному рядку (result): " << amount << endl;
    return 0;
}