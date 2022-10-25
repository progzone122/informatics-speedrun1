#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

double Y(int x)
{
    return ((x - 1)*(x - 1)) / 2;
}

double X(int x)
{
    return (2*x) / (sqrt(x) - 1);
}

void XY(int x, double arr[])
{

    arr[0] = ((x - 1)*(x - 1)) / 2;
    arr[1] = (2*x) / (sqrt(x) - 1);
}

int main()
{
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001);

    double arr[2];
    int num, option = -1;

    while (option != 4) {
        cout << "\n1: ((x - 1)*(x - 1)) / 2 \n2: (2*x) / (sqrt(x) - 1) \n3: обидва варіанти \n4: Вихід з программи\n "; 
        cin >> option;
        if (option != 4) {
            cout << "Введіть Х: ";
            cin >> num;
            if (num < 0) {
                cout << "X від'ємний, вираз немає розв'язку, введіть значення ще раз\n";
                option = -1;
                continue;
            }
        }
        switch (option) {
            case 1:
                cout <<  X(num);
                break;
            case 2:
                cout << Y(num);
                break;
            case 3:
                arr[2] = XY(num, arr);
                for (int i = 0; i < 2; i++)
                    cout << arr[i] << endl;
                break;
        }
    }

    return 0;
}
