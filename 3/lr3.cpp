#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a, t, k, S, x1, x2;
    cout << "| ====== Введіть значення ====== |\n";

    cout << "  a = ";
    cin >> a;
    cout << "  t = ";
    cin >> t;
    cout << "  k = ";
    cin >> k;
    cout << "  S = ";
    cin >> S;

    cout << "| ============================== |\n\n";

    cout << "| =========== Рішення ========== |\n";

    if(k < S / 2){
        x1 = a - pow(t, 3) / S;
        if(S == 0){
            cout << "S = 0";
        }else{
            cout << "x1 = " << x1 << "\n";
        }
    }else{
        cout << "x1 = На введених вхідних даних функція не визначена\n";
    }
    if(k > S / 2 || k == S / 2){
        x2 = t - pow(a, 4);
        cout << "x2 = " << x2 << "\n";
    }else{
        cout << "x2 = На введених вхідних даних функція не визначена\n";
    }

    cout << "| ============================== |\n";
	return 0;
}
