#include <iostream>
#include <windows.h>

using namespace std;

class Time {
private:
  int first;  // години
  int second; // хвилини

public:
  Time() {
    first = 0;
    second = 0;
  }

  void setFirst(int value) {
    if (value > 0) {
      first = value;
    } else {
      cout << "Неправильне значення годин. Введіть позитивне ціле число."
           << endl;
    }
  }

  void setSecond(int value) {
    if (value > 0) {
      second = value;
    } else {
      cout << "Неправильне значення хвилин. Введіть позитивне ціле число."
           << endl;
    }
  }

  int getFirst() { return first; }

  int getSecond() { return second; }

  int minutes() {
    // Цей метод обчислює загальну кількість хвилин на основі значень поля first
    // (години) та поля second (хвилини). Перші години множаться на 60, щоб
    // перевести їх у хвилини, і потім додаються значення поля second.
    return first * 60 + second;
  }
};

int main() {
  SetConsoleCP(65001);       // встановлюємо кодування
  SetConsoleOutputCP(65001); // встановлюємо кодування

  // Оголошення об'єкту за ім'ям
  Time time1;

  time1.setFirst(2);
  time1.setSecond(30);

  // Оголошення об'єкту через вказівник
  Time time2;

  Time *time2Ptr = &time2;
  time2Ptr->setFirst(1);
  time2Ptr->setSecond(45);

  // Виведення значень полів об'єктів
  cout << "Перший об'єкт:" << endl;
  cout << "Години: " << time1.getFirst() << endl;
  cout << "Хвилини: " << time1.getSecond() << endl;
  cout << "Загальна кількість хвилин: " << time1.minutes() << endl;

  cout << "\nДругий об'єкт:" << endl;
  cout << "Години: " << time2Ptr->getFirst() << endl;
  cout << "Хвилини: " << time2Ptr->getSecond() << endl;
  cout << "Загальна кількість хвилин: " << time2Ptr->minutes() << endl;

  return 0;
}