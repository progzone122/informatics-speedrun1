#include <iostream>
#define _USE_MATH_DEFINES //Подключаем директиву препроцессора для 
                          //використання додаткових математичних констант
#include <cmath>
#include <windows.h> //Для встановлення кодування
#include <stdio.h>// Бібліотека яп си 

using namespace std;

float z1(float a){
    return 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
}
float z2(float a){
    return 1 / 4 - 1 / 4 * sin(5 * M_PI * 8 * a / 2);
}
main(){
    SetConsoleCP(65001); //Забираємо кракозябри в консолі віндовс (встановлюємо кодування)
    SetConsoleOutputCP(65001); //Забираємо кракозябри в консолі віндовс (встановлюємо кодування)

    float angle;
    
    cout << "Введите кут a в радианах: ";
    cin >> angle;
    printf("z1 = %f\nz2 = %f\n", z1(angle), z2(angle));//

    system("pause"); //Ставимо на паузу програму, щоб не закрилася
    return 0;
}