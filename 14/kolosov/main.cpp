#include <stdio.h>
#include <iostream>
#include <windows.h>


void transformArray(int array[], int ARRSIZE) {
/*  Пояснення:
У першому циклі ми рахуємо кількість парних елементів.
i = 0 Лічильник для переміщення по масиву
j = 0 Лічильник для вставки парних елементів з початку масиву (кожна вставка j++)
k > 0 Цикл працює поки лічильник парних елементів не дорівнюватиме 0
i++ Крок лічильника для переміщення */
// перетворити масив таким чином, щоб у першій його половині розташовувались парні елементи, 
// а у другій половині – непарні елементи.
// transformArray(int array[], int ARRSIZE)
    int temp, k = 0;
    for (int i = 0; i < ARRSIZE; i++) {
        if (array[i] % 2 == 0) // для перетворення
            k++;
    }
    for (int i = 0, j = 0; k > 0; i++) {
        if (array[i] % 2 == 0) {
            // Заміна знайденного парного елементу на непарний
            temp = array[i]; 
            array[i] = array[j];
            array[j] = temp; 
            k--;
            j++;
        }
    }
}

// int calculateArray(int array[], int ARRSIZE) 
int calculateArray(int array[], int ARRSIZE) {
    // добуток елементів масиву, розташованих між передостаннім та останнім нульовими елементами
    /* Пояснення: 
    у нас є змінна перемикач - flag, 
    якщо зустрівся 0 то ми починаємо рахувати добуток, 
    якщо зустрівся другий 0, то ми закінчуємо рахувати добуток.
    кожного разу як ми зустрічаємо 0 вперше (коли flag == 0) ми рахуємо добуток наново (див. завд.) */
    int product = 1, flag = 0;
    for (int i = 0; i < ARRSIZE; i++) {
        if (array[i] == 0 && flag == 1) {
            flag = 0;
        }
        else if (array[i] == 0 && flag == 0) {
            product = 1;
            flag = 1;
        }
        else if (flag == 1) {
            product *= array[i];
        }
    }
    return product;
}

// void arrayPrint(int array[], int ARRSIZE)
void arrayPrint(int array[], int ARRSIZE) {
    printf("\n[");
    for (int i = 0; i < ARRSIZE-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[ARRSIZE-1]); 
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int ARRSIZE = 6;
    int array[ARRSIZE];
    int product, option;

    printf("Введіть масив\n");
    for (int i = 0; i < ARRSIZE; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    arrayPrint(array, ARRSIZE);

    printf("1: трансформувати масив\n2: порахувати массив\n Введіть відповіть: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
        transformArray(array, ARRSIZE);
        arrayPrint(array, ARRSIZE);
        break;
    case 2:
        product = calculateArray(array, ARRSIZE);
        // Виведення добутку
        if (product != 1)
            printf("Добуток: %d", product);
        else 
            printf("Не було введено жодного нуля (0 . . . 0 рахуються елементи між нулями)\n");
        break;
    }
    return 0;
}
