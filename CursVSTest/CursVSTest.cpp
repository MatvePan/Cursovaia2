#include "iostream"
#include "string"
#include "massive.h"
#include "fstream"
#include "cmath"
using namespace std;

struct Student { //Структуры данных студента
    string fio = " "; //Фамилия, имя и отчество Студента
    int studnum[5] = {}; //Оценки студента
    int salary = 0; //Стипендия студента
    int group = 0; //Номер группы студента
    string extra = " "; //Дополнительная информация студента
    int index = 0; //Индексация студента
    int sum = 0; //Сумма баллов студента
};

void PrintStudent(Student student) { //Функция вывода данных студента
    cout << "Student FIO|Index: " << student.fio << " | " << student.index << "\n";
    cout << "Student group: " << student.group << "\n";
    cout << "Student report card: ";
    for (int i = 0; i < 5; i++)
        cout << student.studnum[i] << "|";
    cout << "\n";
    cout << "Rating amount: " << student.sum << "\n";
    cout << "Student salary: " << student.salary << "\n";
    cout << "Student extra information: " << student.extra << "\n";
}

Student WriteStudent() { //Функция ввода данных студента
    Student student;
    string f, l, o;
    cout << "Enter student FIO\n";
    cin >> f >> l >> o;
    student.fio = f + " " + l + " " + o;
    cout << "Enter student salary\n";
    cin >> student.salary;
    cout << "Enter student group\n";
    cin >> student.group;
    cout << "Enter student extra information\n";
    cin >> student.extra;
    cout << "Enter student index\n";
    cin >> student.index;
    cout << "Enter student evaluations(max-5)\n";
    for (int i = 0; i < 5; i++) {
        cin >> student.studnum[i];
        student.sum += student.studnum[i];
    }
    return student;
}

Student InviteGroup(int group) { //Функция добавления студента в группу
    Student student;
    string f, l, o;
    cout << "Enter student FIO\n";
    cin >> f >> l >> o;
    student.fio = f + l + o;
    cout << "Enter student salary\n";
    cin >> student.salary;
    student.group = group;
    cout << "Enter student extra information\n";
    cin >> student.extra;
    cout << "Enter student index\n";
    cin >> student.index;
    cout << "Enter student evaluations(max-5)\n";
    for (int i = 0; i < 5; i++) {
        cin >> student.studnum[i];
        student.sum += student.studnum[i];
    }
    return student;
}

void DeleteStudent(Massive<Student> massive) { //Функция удаления студентов
    int del;
    bool inStock = false;
    cout << "Enter student index\n";
    cin >> del;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).index == del) {
            massive.Remove(i);
            inStock = true;
            break;
        }
    }
    if (inStock)
        cout << "This student is not here\n";
}

void StudentEditor(Massive<Student> massive) { //Функция редактирования данных студентов
    bool inStud = false;
    int num;
    cout << "Enter student number\n";
    cin >> num;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).index == num) {
            cout << "Student Editor\n;";
            cout << "1. New FIO\n";
            cout << "2. New group\n";
            cout << "3. New evaluations\n";
            cout << "4. New salary size\n";
            cout << "5. New index\n";
            cout << "6. New extra information\n";
            cout << "0. Exit\n";
            cout << "Enter number for choose\n";
            inStud = true;
            Student newStudent = massive.Number(i);
            string word;
            cin >> num;
            switch (num) {
            case 1:
                cout << "Enter new fIO\n";
                cin >> word;
                newStudent.fio = word;
                break;
            case 2:
                cout << "Enter new group\n";
                cin >> num;
                newStudent.group = num;
                break;
            case 3:
                cout << "Enter new evaluations\n";
                for (int i = 0; i < 5; i++)
                    cin >> newStudent.studnum[i];
                break;
            case 4:
                cout << "Enter new student salary size\n";
                cin >> num;
                newStudent.salary = num;
                break;
            case 5:
                cout << "Enter new student index\n";
                cin >> num;
                newStudent.index = num;
                break;
            case 6:
                cout << "Enter new student extra information\n";
                cin >> word;
                newStudent.extra = word;
                break;
            case 0:
                return;
            default:
                cout << "Incorrect choose\n";
            }
            massive.Remove(i);
            massive.Add(newStudent);
            break;
        }
    }
    if (!inStud)
        cout << "This student is not here\n";
}

void StudentSearch(Massive<Student> massive) { //Функция поиска определённых студентов
    cout << "Student Searcher\n";
    cout << "1. Search by FIO\n";
    cout << "2. Search by group\n";
    cout << "3. Search by evaluations\n";
    cout << "4. Search by salary size\n";
    cout << "5. Search by index\n";
    cout << "6. Search by rating amount\n";
    cout << "Enter number for choose\n";
    int mode;
    int table1[5];
    bool inStud = false, table;
    string fio;
    cin >> mode;
    switch (mode) {
    case 1:
        cout << "Enter student FIO\n";
        cin >> fio;
        for (int i = 0; i < massive.Count(); i++) {
            if (massive.Number(i).fio == fio) {
                PrintStudent(massive.Number(i));
                inStud = true;
            }
        }
        if (!inStud)
            cout << "No FIO\n";
        break;
    case 2:
        cout << "Enter group number\n";
        cin >> mode;
        for (int i = 0; i < massive.Count(); i++) {
            if (massive.Number(i).group == mode) {
                inStud = true;
            }
        }
        if (!inStud)
            cout << "No group\n";
        break;
    case 3:
        cout << "Enter student report card\n";
        for (int i = 0; i < 5; i++)
            cin >> table1[i];
        for (int i = 0; i < massive.Count(); i++) {
            table = true;
            for (int j = 0; j < 5; j++) {
                if (table1[j] != massive.Number(i).studnum[j]) {
                    table = false;
                }
            }
            if (table) {
                PrintStudent(massive.Number(i));
                inStud = true;
            }
        }
        if (!inStud)
            cout << "No student\n";
        break;
    case 4:
        cout << "Enter student salary\n";
        cin >> mode;
        for (int i = 0; i < massive.Count(); i++) {
            if (massive.Number(i).salary == mode) {
                PrintStudent(massive.Number(i));
                inStud = true;
            }
        }
        if (!inStud)
            cout << "No students with it salary\n";
        break;
    case 5:
        cout << "Enter student index\n";
        cin >> mode;
        for (int i = 0; i < massive.Count(); i++) {
            if (massive.Number(i).index == mode) {
                PrintStudent(massive.Number(i));
                inStud = true;
            }
        }
        break;
    case 6:
        cout << "Enter student rating amount\n";
        cin >> mode;
        for (int i = 0; i < massive.Count(); i++) {
            if (massive.Number(i).sum == mode) {
                PrintStudent(massive.Number(i));
                inStud = true;
            }
        }
        if (!inStud)
            cout << "No student\n";
        break;
    }
}

void ShowAll(Massive<Student> massive) { //Функция показа данных всех студентов
    if (massive.Count() == 0) {
        cout << "No students\n";
        return;
    }
    for (int i = 0; i < massive.Count(); i++)
        PrintStudent(massive.Number(i));
}

void AddGroup(Massive<Student> massive) { //Функция создания группы
    int group;
    int mode;
    cout << "Enter group number\n";
    cin >> group;
    cout << "1.Add students\n";
    cout << "0.Exit\n";
    while (true) {
        cin >> mode;
        massive.Add(InviteGroup(group));
        if (mode == 0)
            break;
    }
}

void DeleteGroup(Massive<Student> massive) { //Функция удаления группы
    int group;
    bool DidntLiveGroup = false;
    cout << "Enter group number\n";
    cin >> group;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).group == group) {
            massive.Remove(i);
            DidntLiveGroup = true;
        }
    }
    if (!DidntLiveGroup)
        cout << "No group\n";
}

void GroupEditor(Massive<Student> massive) { //Функция редактирования группы
    int oldnum, newnum;
    bool Group;
    cout << "Enter old group number\n";
    cin >> oldnum;
    cout << "Enter new group number\n";
    cin >> newnum;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).group == oldnum) {
            Student newStudent = massive.Number(i);
            newStudent.group = newnum;
            massive.Remove(i);
            i--;
            massive.Add(newStudent);
            Group = true;
        }
    }
    if (!Group)
        cout << "No group\n";
}

void AboutGroup(Massive<Student> massive) { //Функция получения данных студентов всей группы
    int group;
    bool graup = false;
    cout << "Enter group number\n";
    cin >> group;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).group == group) {
            PrintStudent(massive.Number(i));
            graup = true;
        }
    }
    if (!graup)
        cout << "No group\n";
}

void OneTable(Massive<Student> massive) {
    int num;
    int col = 0;
    cout << "Enter rating amount\n";
    cin >> num;
    for (int i = 0; i < massive.Count(); i++) {
        if (massive.Number(i).sum == num) {
            col++;
        }
    }
    cout << "Amount|Quantity\n";
    cout << "  " << num << "  |  " << col << "\n";
}

void AllTable(Massive<Student> massive) {
    int col = 0;
    cout << "Amount|Quantity\n";
    for (int i = 2; i < 25; i++) {
        for (int j = 0; j < massive.Count(); j++) {
            if (massive.Number(j).sum == i) {
                col++;
            }
        }
        cout << "  " << i << "  |  " << col << "\n";
    }
}

int Fun1(string word) {
    int num = 0, j = 0;
    int* table = new int(word.size());
    for (int i = 0; i < word.size(); i++)
        table[i] = word[i] - 48;
    for (int i = word.size() - 1; i >= 0; i--, j++)
        num += table[i] * pow(10, j);
    return num;
}

int* Fun2(string word) {
    int toble[5] = {};
    int j = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] != ' ') {
            toble[j] = word[i] - 48;
            j++;
        }
    }
    return toble;
}

void Save(Massive<Student> massive) { //Функция записи в файл
    Student student;
    ifstream save;
    save.open("save.txt");
    string word;
    int* table;
    int t = 0;
    while (getline(save, word)) {
        t++;
        switch (t) {
        case 1:
            student.fio = word;
            break;
        case 2:
            student.group = Fun1(word);
            break;
        case 3:
            student.index = Fun1(word);
            break;
        case 4:
            table = Fun2(word);
            for (int i = 0; i < 5; i++)
                student.studnum[i] = table[i];
            break;
        case 5:
            student.salary = Fun1(word);
            break;
        }
    }
}

void Load(Massive<Student> massive) { //Функция загрузки из файла
    ofstream load;
    load.open("load.txt");
    for (int i = 0; i < massive.Count(); i++) {
        Student student = massive.Number(i);
        load << student.fio << "|" << student.index << "\n";
        load << student.group << "\n";
        for (int i = 0; i < 5; i++)
            load << student.studnum[i] << "|" << "\n";
        load << student.salary << "\n";
    }
    load.close();
}

int main() { //Главная функция
    Massive<Student> massive;
    int mode;
    while (true) {
        system("pause");
        cout << "Students\n";
        cout << "11. Add student\n";
        cout << "12. Delete student\n";
        cout << "13. Edit student\n";
        cout << "14. Show student\n";
        cout << "15. Show all students\n";
        cout << "Group\n";
        cout << "21. Add students into group\n";
        cout << "22. Delete students from group\n";
        cout << "23. Edit group number\n";
        cout << "24. Show group students information\n";
        cout << "Output in the table\n";
        cout << "31. Show table\n";
        cout << "32. Show all table\n";
        cout << "Other\n";
        cout << "7. Save data\n";
        cout << "8. load data\n";
        cout << "9. Erase data\n";
        cout << "0. Exit\n";
        cout << "Enter number for choose\n";
        cin >> mode;
        switch (mode) {
        case 11:
            massive.Add(WriteStudent());
            break;
        case 12:
            DeleteStudent(massive);
            break;
        case 13:
            StudentEditor(massive);
            break;
        case 14:
            StudentSearch(massive);
            break;
        case 15:
            ShowAll(massive);
            break;
        case 21:
            AddGroup(massive);
            break;
        case 22:
            DeleteGroup(massive);
            break;
        case 23:
            GroupEditor(massive);
            break;
        case 24:
            AboutGroup(massive);
            break;
        case 31:
            OneTable(massive);
            break;
        case 32:
            AllTable(massive);
            break;
        case 7:
            Save(massive);
            break;
        case 8:
            Load(massive);
            break;
        case 9:
            massive.Clear();
            break;
        case 0:
            return 0;
        default:
            cout << "Incorrect choose\n";
        }
    }
}
