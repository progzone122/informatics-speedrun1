#include <iostream>
#include <string.h>

using namespace std;

// 1. Користуватський клас 
class Personnel { 
private:
    char *name = new char[9]; // ім'я
    int workshop; // цех
    int workshopNo; // номер цеху 
    int category; // розряд 
public:
    // 2. Конструктор класу без параметрів 
    Personnel() {
        cout<<"\n Constructor executed";
        workshop = 0;
        workshopNo = 0;
        category = 0;
    }
    // 2. Конструктор класу без параметрів 
    Personnel(char* namev, int workshopv, int workshopNov, int categoryv) {
        // 7.де-структора супроводжується виведенням відповідного повідомлення( який об'єкт який конструктор або деструктор викликав). 
        cout<<"\n--Constructor executed";
        strcpy(name, namev);
        cout << endl << "|-name set"; 
        workshop = workshopv;
        cout << endl << "|-workshop set"; 
        workshopNo = workshopNov;
        cout << endl << "|-workshopNo set"; 
        category = categoryv;
        cout << endl << "|-category set\n"; 
    }
    // 3.Деструктор 
    ~Personnel() {
        // 7.де-структора супроводжується виведенням відповідного повідомлення( який об'єкт який конструктор або деструктор викликав). 
        cout<<"\n --Destructor executed";
        delete name;
        cout << endl << "|-name deleted" << endl;
    }

    // 4.Визначити в класі компонента-функції для перегляду й установки по-лів даних. 
    char* getName() {
        return name;
    }
    void setName(char* value) {
        strcpy(name, value);
    }
    int getWorkshop() {
        return workshop;
    }
    void setWorkshop(int value) {
        workshop = value;
    }
    int getWorkshopNo() {
        return workshopNo;
    }
    void setWorkshopNo(int value) {
        workshopNo = value;
    }
    int getCategory() {
        return category;
    }
    void setCategory(int value) {
        category = value;
    }
    

};

// 5.Визначити покажчик на компонент-функцію.
char* (Personnel::*name)(void);

int main()
{
    char n[] = {'V','a','s','i','l','e','n','k','o'};
    Personnel obj(n, 1, 1, 1);
    // 6.Визначити покажчик на екземпляр класу. 
    Personnel *ptr = &obj; 
    // 5.Визначити покажчик на компонент-функцію.
    name = Personnel::getName;
    // 8.Показати в програмі використання покажчика на об'єкт і покажчика на компонент-функцію (метод).
    cout << endl << "using pointer to method: " << (obj.*name)();
    cout << endl << "using pointer to class : " << ptr->getName() << endl;

    return 0;
}
