#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

struct Student
{
    string group;
    string name;
    int gradesExam[2]; // відмітки по 2 іспитам
    int gradesTest[3]; // відмітки по 3 залікам
    int socialWorked; // 0 активна, 1 неактивна
    int learningBase; // 0 бюджет, 1 контракт
    int data = 0; // 0 данні відсутні, 1 данні є 
};


void calculateScholarship(struct Student * studentList) {
    int grades3;
    int grades4;
    int score = 0; 
    int scholarship;
    // 0 не вступив
    // 1 вступив, звичайна стипендія
    // 2 вступив, підвищенна 25%
    // 3 вступив, підвищенна 50%

    cout << endl << "Введіть значення звичайної степендії: ";
    cin >> scholarship;
    /*
        Критерії розрахунку степендії (балів)
    if всі відмітки 5     | 25% 1бал
    if суспільна праця 0 | 25%  1бал
    if відмітки > 4    | 0% 0 балів
    if відмітки >3    | -1 бал  
    if відмітки >3 and суспільна праця 0 | 0балів
    */
    for (int i = 0; i < 5; i++) {
        if (studentList[i].data == 1) {
            score = 0;
            grades3 = 0;
            grades4 = 0;
            for (int c = 0; c < 2; c++) {
                if (studentList[i].gradesExam[c] <= 3)
                    grades3 = 1;
                else if (studentList[i].gradesExam[c] <= 4)
                    grades4 = 1;
            }
            for (int v = 0; v < 3; v++) {
                if (studentList[i].gradesExam[v] <= 3)
                    grades3 = 1;
                else if (studentList[i].gradesExam[v] <= 4)
                    grades4 = 1;
            }
            // Розрахунок балів учня (згідно критеріям)
            if (studentList[i].socialWorked == 0)
                score++;
            if (grades4 == 0)
                score++;
            if (grades3 == 1)
                score--;

            if (score == 2) {
                cout << endl << "Студент " <<  studentList[i].name 
                << " Зарахований та отримує степендію у розмірі " 
                << scholarship * 1.5; 
            }
            else if (score == 1) {
                cout << endl << "Студент " <<  studentList[i].name 
                << " Зарахований та отримує степендію у розмірі " 
                << scholarship * 1.25; 
            }
            else if (score == 0) {
                cout << endl << "Студент " <<  studentList[i].name 
                << " Зарахований"; 
            }
            else if (score < 0) {
                cout << endl << "Студент " <<  studentList[i].name 
                << " Не зарахований"; 
            }
        }
    }
}

// printStudentData(struct Student * studentList, int studentNo)
void printStudentData(struct Student * studentList, int studentNo) {
    if (studentList[studentNo].data == 1) {
        cout << "    __________Данні_студента______\n";
        cout << "    |Группа: " << studentList[studentNo].group << endl
        << "    |Ім'я: " << studentList[studentNo].name << endl
        << "    |Оцінки за 2 іспити: ";
        for (int i = 0; i < 2; i++)
            cout << studentList[studentNo].gradesExam[i] << " ";
        cout << endl  << "    |Оцінки по 3 залікам: ";
        for (int i = 0; i < 3; i++)
            cout << studentList[studentNo].gradesTest[i] << " ";
        cout << endl << "    |Участь у суспільній роботі: ";
        if (studentList[studentNo].socialWorked == 0) 
            cout << "Активна" << endl;
        else 
            cout << "Неактивна" << endl;
        cout << "    |Форма навчання: ";
        if (studentList[studentNo].learningBase == 0) 
            cout << "Бюджет" << endl;
        else 
            cout << "Контракт" << endl;
    }
    else
        cout << "Данні про цього студента відсутні.\n";
}


// enterStudentData(struct Student * studentList, int studentNo)
// Ввід всіх данних структури Student 
void enterStudentData(struct Student * studentList, int studentNo) {
    cout << "ДАННІ ВВОДИТИ ЛАТИНСЬКИМИ ЛІТЕРАМИ" << endl;
    //  cin.sync();  для того щоб прибрати данні з буфера(інакше ввід буде пропускатись)
    cin.sync(); 
    cout << "Введіть группу студента: " << endl;
    getline(cin, studentList[studentNo].group);
    //  cin.sync();  для того щоб прибрати данні з буфера(інакше ввід буде пропускатись)
    cin.sync();
    cout << "Введіть Ім'я студента: " << endl;
    getline(cin, studentList[studentNo].name);

    cout << endl << "Введіть відмітки за 2 іспити студента: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Введіть " << i+1 << "'у оцінку: ";
        cin >> studentList[studentNo].gradesExam[i];
    }
    cout << endl << "Введіть відмітки по 3 залікам студента: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Введіть " << i+1 << "'у оцінку: ";
        cin >> studentList[studentNo].gradesTest[i];
    }
    cout << endl << "Введіть чи брав студент участь у суспільній праці? (0 - так, 1 - ні): ";
    cin >> studentList[studentNo].socialWorked;
    cout << endl << "Введіть форму навчання студента: (0 бюджет, 1 котракт): ";
    cin >> studentList[studentNo].learningBase;
}


// int callMenu(struct Student * studentList)
int callMenu(struct Student * studentList) {
    int option, studentNo;

    cout << endl << "____________________________" << endl
    << "1. Вивести данні студента" << endl
    << "2. Побудувати список степендії" << endl 
    << "3. Ввести данні студента" << endl
    << "4. Вихід з программи" << endl;
    cin >> option;

    switch (option) {
    
    case 1: // Вивести данні студента
        cout << "  Введіть номер студента котрий вам потрібен: ";
        cin >> studentNo;
        printStudentData(studentList, studentNo);
        break;
    case 2: // Побудувати список степендії
        calculateScholarship(studentList);
        break;
    case 3: // Ввести данні студента
        cout << "  Введіть номер студента котрий вам потрібен: ";
        cin >> studentNo;
        enterStudentData(studentList, studentNo);
        break;
    case 4: // Вихід з программи
        return -1;
    }
    return 1; // Код корректного завершення функції
}


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int exitCode;

    Student studentList[5] = {{}, {}, {}, {}, {}};
    studentList[0] = {"21-1", "Kolosov    ", {4, 4}, {4, 3, 5}, 0, 0, 1};
    studentList[1] = {"21-1", "NotKolosov ", {5, 5}, {5, 5, 5}, 0, 0, 1};
    studentList[2] = {"21-1", "NotKolosov1", {4, 4}, {4, 3, 5}, 1, 0, 1};
    studentList[3] = {"21-1", "NotKolosov2", {4, 3}, {4, 3, 5}, 1, 1, 1};

    while (exitCode != -1)
        exitCode = callMenu(studentList);
    
    return 0;
}
