#include <iostream>
#include <cmath> // Математична бібліотека
#include <windows.h> //Для установки кодировки
#include <string> //Для роботи з рядками
#include <vector>

using namespace std;
//Бульбашкове сортування
void bubble_sort(int *a, int *ARRAY_SIZE){
    int j;
    for (int i = 0; i < *ARRAY_SIZE - 1; i++){ //цикл проходу по масиву
        for (j = 0; j < *ARRAY_SIZE - i - 1; j++){ // цикл попарного порівняння сусідніх елементів
            if (a[j] > a[j + 1]){ // обмін елементів з номерами j  та j+1
                int v = a[j]; 
                a[j] = a[j + 1]; 
                a[j + 1] = v; 
            }
        }
    }
}
//Добуток елементів масиву, розташованих між першим та другим нульови-ми елементами
int funcA(int *a, int *ARRAY_SIZE){
    int a2 = 0; //змінна для добутка знайдених елементів, які розташовані між першим та другим нульови-ми елементами
    int first_zero = 0; //чи знайшли перший нуль 
    for (int i = 0; i < *ARRAY_SIZE; i++){
        if(a[i] == 0){ //Якщо знайшли нуль
            first_zero++; //Міняємо в змінній значення на +1
        }
        if(first_zero <= 2){//Перевірка щоб були тільки перші два нулі
            if(first_zero != 0){ //Якщо знайшли перший нуль
                if(a2 != 0){//Перевірка на присутність елементів в змінній
                    a2 = a2 * a[i];
                }else{
                    a2 = a[i];
                }
            }
        }
    }
    return a2;
}
//Перетворити масив таким чином, щоб у першій його половині розташовувались елементи, що стоять у непарних позиціях , а у другій половині – елементи , що стоять у парних позиціях
void funcB(int *a, int *ARRAY_SIZE){
    vector<int> a2; //вектор масива парних чисел
    vector<int> a3;//вектор масива не парних чисел
    for(int i = 0; i < *ARRAY_SIZE; i++){
        if(a[i] % 2 == 0){//якщо парне
            a2.push_back(a[i]);
        }else{//якщо не парне
            a3.push_back(a[i]);
        }
    }
    vector<int> v(a3);
    v.insert(v.end(), a2.begin(), a2.end());
    cout << "Результат: \n";
    for (int i = 0; i < *ARRAY_SIZE; i++){
        cout << v[i] << "\n";
    }
}
//Функція визову меню
void menu(int *menu_var, int *a, int *ARRAY_SIZE){
    cout << "1) Добуток елементів масиву, розташованих між першим та другим нульови-ми елементами\n"
        << "2) Перетворити масив таким чином, щоб у першій його половині розташовувались елементи, що стоять у непарних позиціях , а у другій половині – елементи , що стоять у парних позиціях.\n"
        << "3) Вихід з програми\n"
        << ">> ";
    cin >> *menu_var;
    switch (*menu_var){
        case 1:
            cout << "Результат: " << funcA(a, ARRAY_SIZE);
            cout << endl;
            menu(menu_var, a, ARRAY_SIZE);
            break;
        case 2:
            funcB(a, ARRAY_SIZE);
            cout << endl;
            menu(menu_var, a, ARRAY_SIZE);
            break;
        case 3:
            exit(0); //Програма завершена успішно
            break;
        default:
            cout << "\n[!] Невірне число!\n\n";
            menu(menu_var, a, ARRAY_SIZE);
            break;
    }
}
//Функція для ведень значень в масив a
int form(int *a, int *ARRAY_SIZE){
    int n;
	cout << "\n Введіть кількість елементів масиву ";
	cin >> *ARRAY_SIZE;
	for(int i = 0; i < *ARRAY_SIZE; i++){
		cout<<"Введіть елемент А[" << i + 1 << "]  ";
		cin >> a[i];
        cout << endl;
    }
	return n;
}
//
int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування

    int menu_var = 0; //Змінна для меню
    int a[100]; //змінна для користувацьких значень
    int ARRAY_SIZE = 10;
    form(a, &ARRAY_SIZE);
    bubble_sort(a, &ARRAY_SIZE);
    menu(&menu_var, a, &ARRAY_SIZE);
    return 0;
}