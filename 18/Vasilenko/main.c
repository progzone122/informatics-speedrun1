#include <stdio.h>
#include <malloc.h>
#include <windows.h>

// structure to perform list node
struct _Node {
    int value;           // element value
    struct _Node* prev;  // previous element pointer
} *tail=NULL; // global list variable

// calculate length of list
int length(struct _Node* list)
{
    int result = 0;
    if (list != NULL) {
        struct _Node* tmp = list;
        for (; tmp != NULL; result++, tmp=tmp->prev);
    }
    return result;
}

// adds new element to the end of the list
struct _Node* append(struct _Node* list, int value)
{
    struct _Node* newNode = (struct _Node*)malloc(sizeof(struct _Node));
    newNode->value = value;
    newNode->prev = list;
    return newNode;
}

// delete element by index
struct _Node* delete(struct _Node* list, int index)
{
    int len = length(list);
    if (len == 1 && index == 0) {
        free(list);
        return NULL;
    }
    if (index > -1 && index < len) {
        struct _Node *tmp, *tmp2;
        int i;
        for (tmp = list, i = len - 1; i > index + 1; i--, tmp=tmp->prev);
        tmp2 = tmp->prev;
        tmp->prev = tmp->prev->prev;
        free(tmp2);
    }
    return list;
}

// remove all elements from the list
struct _Node* clear(struct _Node* list)
{
    printf("\n      | Список Очищенно |\n");
    struct _Node* tmp = list;
    while (list != NULL) {
        tmp = list->prev;
        free(list);
        list = tmp;
    }
    return list;
}

// forward index-based element printing
void print(struct _Node* list)
{
    if (list != NULL) {
        print(list->prev);
        printf("%d ", list->value);
    }
}

void productNegative(struct _Node* list) {
    int negC = 0; // negative number counter
    int productNegative = 1;
    struct _Node* tmp = list;
    while (tmp != NULL) {
        if (tmp->value < 0) {
            negC++;
            productNegative *= tmp->value;
        }
        tmp = tmp->prev;
    }
    printf("      | Negative numbers counter: %d \n       |proudct of negative numbers: %d", negC, productNegative*(-1));
}

struct _Node* removeNegative(struct _Node* list) {
    struct _Node* tmp;
    int i;
    int flag;
    
    for (int i =0; i < length(list); i++) {
    flag = 0;
    i=length(list)-1;
    tmp = list;
        while (tmp!= NULL && i >= 0) {
            if (tmp->value < 0) {
                flag = 1;
                list = delete(list, i);
                i++;
            }
            tmp = tmp->prev;
            i--;
        }
        if (flag == 0) break;
    }
    return list;
}

int menu() {
    int option=-1;
    int len;
    printf("\n* * * * * * * * * * * * * * * * * * * * * \n1.	Формування списку.\n2.	Перегляд вмісту списку.\n3.	Добуток та кількість від'ємних елементів списку.\n4.	Видалення списку.\n5.	Видалити із списку всі від’ємні елементи.\n6.  Вийти з програми\n* * * * * * * * * * * * * * * * * * * * *\n");
    printf("Введіть варіант відповіді: "); 
    scanf("%d", &option);
    switch (option)
    {
    case 1: // Формування списку
        printf("Введіть довжину списку: "); 
        scanf("%d", &len); 
        int elem;
        printf("Введіть елементи списку\n"); 
        for (int i = 0; i < len; i++) {
            printf("      [%d]: ", i); 
            scanf("%d", &elem);
            tail = append(tail, elem);
        }
        break;
    case 2: // Перегляд вмісту списку
        printf("      - Список -\n------> ");
        print(tail);
        break;
    case 3: // Добуток та кількість від'ємних елементів списку.
        productNegative(tail);
        break;
    case 4: // Видалення списку.
        tail = clear(tail);
        break;
    case 5: //Видалити із списку всі від’ємні елементи.
        tail = removeNegative(tail);
        break;
    default:
        return -1;
    }
    return 0;
}


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int ans = 0;
    while (ans != -1) {
        ans = menu();
    }
    return 0;
}
