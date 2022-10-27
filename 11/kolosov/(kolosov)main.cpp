#include <iostream>
#include <windows.h> 
#include <string> // getline, substr
#include <bits/stdc++.h> // count

using namespace std;

int main(){
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001); 

    string strOne, strTwo, strThree; //s1 & s2

    /* Ввести рядки s1 та s2. | strOne, strTwo
    (просто якщо все називати як в лабі сказано, то ніхто в житті цей код не розбере)
    Другу половину s2 з’єднати з першою половиною  s1 та в отриманому рядку порахувати кількість ‘0’.    */

    cout << "Введіть перший рядок: ";    
    getline(cin, strOne);
    cout << "Введіть другий рядок: ";
    getline(cin, strTwo);

    cout << "\n  Введені рядки:" << endl 
    << "  1: " << strOne << endl 
    << "  2: " << strTwo << endl;

    // lenght() функція для визначення довжини рядка | str.lenght()
    // substr функція яка приймає два параметри (початок, кінець) для того щоб обрізати рядок | str.substr(0, 3)
    // str = "012345", str.substr(0, 3) == "012"
    // cout(початок, кінець, 'шуканий елемент') | count(strThree.begin(), strThree.end(), '0')
    // count - функція яка рахує скільки разів елемент зустрічається у рядку

    strThree = strOne.substr(0, strOne.length()/2) + strTwo.substr(strTwo.length()/2, strTwo.length());
    cout << "Фінальний рядок: " << strThree << endl 
    << "кількість 0 у рядку: "<< count(strThree.begin(), strThree.end(), '0') << endl;

    return 0;
}