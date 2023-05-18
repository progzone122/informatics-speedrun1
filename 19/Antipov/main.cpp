#include <cstring>
#include <iostream>
#include <windows.h>

using namespace std;

class Employee {
private:
  char *name; // Поле для збереження імені
  int age;    // Поле для збереження віку
  int workExperience; // Поле для збереження робочого стажу

public:
  // Конструктор за замовчуванням
  Employee() : name(nullptr), age(0), workExperience(0) {
    cout << "Виклик конструктора за замовчуванням" << endl;
  }

  // Параметризований конструктор
  Employee(const char *name, int age, int workExperience)
      : age(age), workExperience(workExperience) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    cout << "Виклик параметиризованого конструктора за замовчуванням" << endl;
  }

  // Конструктор копіювання
  Employee(const Employee &other)
      : age(other.age), workExperience(other.workExperience) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    cout << "Виклик конструктора за копіюванням" << endl;
  }

  // Деструктор
  ~Employee() {
    delete[] name;
    cout << "Виклик деструктора конструктора" << endl;
  }

  // Методи доступу до полів (геттери)
  const char *getName() const { return name; }

  int getAge() const { return age; }

  int getWorkExperience() const { return workExperience; }

  // Методи встановлення значень полів (сеттери)
  void setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  void setAge(int age) { this->age = age; }

  void setWorkExperience(int workExperience) {
    this->workExperience = workExperience;
  }
};

int main() {
  SetConsoleCP(65001);       // встановлюємо кодування
  SetConsoleOutputCP(65001); // встановлюємо кодування
  // Приклад використання класу Employee
  Employee employee1("Костя", 17, 5);
  cout << "Ім'я: " << employee1.getName() << ", Вік: " << employee1.getAge()
       << ", Робочий стаж: " << employee1.getWorkExperience() << endl;

  // Використання вказівника на об'єкт
  Employee *pointer = new Employee("Вася", 25, 3);
  cout << "Ім'я: " << pointer->getName() << ", Вік: " << pointer->getAge()
       << ", Робочий стаж: " << pointer->getWorkExperience() << endl;
  delete pointer;

  return 0;
}