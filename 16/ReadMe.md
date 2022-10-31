# Необхідне поняття понять для розуміння лабораторної роботи:
- Classes, methods, inheritance, public, protected, private
- string, substr(), getline(), find()
- vectors, push_back, how to get element from vector, vectorname.empty(),
- for (auto:) - range based for 
- arrays (якщо хтось ще не розуміє), how to get element from array, how to pass array to func, how to return array from func 
- converting one type to another: stoi(), strcpy(), c_str(), path to string .path().u8string(), 
- cin.sync(), cin.get()
- filesystem, current_path(), directory_iterator(), how to get directory,
- files fstream, ifstream, ofstream, ios::out, ios::app, ios::in, file.open(). file.close(), 
- перевірки: isdigit(int char)

***

# Документація
```c++
        class Read
            public: 
                vector <string> fileReadAll(string filename)
                    - Reads Whole file and returns vector of strings that file contains
                string vectorReadLine(vector <string> fileStrings, int lineNo)
        class StudentClass: protected ReadNWrite
            protected: 
                string name(int studentNo)
                    - returns name from file
                string group(int studentNo)
                    - returns group from file
                int * gradesExam(int studentNo)
                    - returns array[2] with 2 grades from file 
                int * gradesTest(int studentNo)
                    - returns array[3] with 3 grades from file 
                int socWork(int studentNo)
                    - returns socWork from file 
                int studBase(int studentNo)
                    - returns studBase from file 
                vector <int> listOfStudents()
                    - searches StudentXX.txt files in directory, and returns vector <int> with student numbers
            public: 
                void printData(int studentNo)
                    - prints all student data (watch protected StudentStruct)
                    - if student file not exists outputs "Студента немає"
                void scholarship()
                    - takes vector from listOfStudents() and prints if each student "отримує стипендію чи ні, чи незарахований"
                    - if vector is empty outputs "Студентів немає, спробуйте додати"
                void enterStudentData(int studentNo)
                    - takes all student data from input kbd and writes it to file 
```
