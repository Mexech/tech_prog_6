/*
● Создать все конструкторы (с параметрами, без параметров и копирования)
и деструктор, использовать переопределение операторов. Каждый вызов
конструктора и деструктора должен сопровождаться выводом этой
информации пользователю (какой объект, какой конструктор или
деструктор вызван).
● Определить исключения (exceptions) и применить в программе. Каждое
исключение должно сопровождаться текстом, поясняющим возникшую
исключительную ситуацию.

Меню пользователя должно содержать возможность
редактирования любой записи любого объекта, удаление любого
объекта, добавления нового объекта на любую позицию.

1. Стандартные потоки
Определить класс с именем WORKER, содержащий следующие поля:
● ФИО работника;
● название занимаемой должности;
● год поступления на работу.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа WORKER.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть размещены в алфавитном порядке;
● вывод на дисплей фамилий работников, чей стаж работы в
организации превышает значение, введенное с клавиатуры,
если таких работников нет, вывести на дисплей соответствующее
сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только предложения,
не содержащие запятых.
*/
#include <iostream>
#include <fstream>
#include "Keeper.h"

using namespace std;

void dispMenu() {
    cout << "Choose task: 1 - workers, 2 - files and string streams" << endl;
}

void dispWorkersMenu() {
    cout << "Type command:\n1 - add new worker\n2 - display workers\n3 - edit worker\n4 - remove worker\n5 - display workers with specified work experience\n6 - exit\n";
}

void dispFilesTaskMenu() {
    cout << "Type command:\n1 - display sentences without commas from file\n2 - display sentences without commas from string\n3 - exit" << endl;
}

void displayWithoutCommas(string line) {
    bool has_commas = false;
    string s, res;
    for(char& c : line) {
        s += c;
        if (c == '.') {
            if (!has_commas)
                res += s;
            has_commas = false;
            s = "";
        } else if (c == ',') {
            has_commas = true;
        }
    }
    if (res.length())
        cout << res << endl;
    else cout << endl;
}

void displayWithoutCommas() {
    fstream in("text.txt", fstream::in);
    string line, s;
    bool has_commas = false;
    while (getline(in, line)) {
        for(char& c : line) {
            s += c;
            if (c == '.') {
                if (!has_commas) 
                    cout << s;
                has_commas = false;
                s = "";
            } else if (c == ',') {
                has_commas = true;
            }
        }
        s += '\n';
    }
    cout << endl;
}

int main() {
    Keeper k;
    while (1) {
        dispMenu();
        int num; cin >> num;
        if (num == 1) {
            while (1) {
                dispWorkersMenu();
                int num; cin >> num;
                if (num == 1) {
                    Worker *w = new Worker();
                    cin >> *w;
                    k.pushSorted(w);
                } else if (num == 2) {
                    try {
                        k.display();
                    } catch (const exception &e) {
                        cout << "There are no workers in a list." << endl;
                    }
                } else if (num == 3) {
                    cout << "Specify worker number to edit:" << endl;
                    int val; cin >> val;
                    if (val < 0 || val >= k.amount)
                        cout << "Out of bounds. Try again." << endl;
                    else 
                        k.get(val)->edit();
                } else if (num == 4) {
                    cout << "Specify worker number to remove:" << endl;
                    int val; cin >> val;
                    if (val < 0 || val >= k.amount)
                        cout << "Out of bounds. Try again." << endl;
                    else 
                        k.pop(val);
                } else if (num == 5) {
                    cout << "Specify worker experience:" << endl;
                    int val; cin >> val;
                    k.workExpLargerThan(val);
                } else if (num == 6) {
                    break;
                } else {
                    cout << "No such command. Try again." << endl;
                }
            }
        } else if (num == 2) {
            while (1) {
                dispFilesTaskMenu();
                int num; cin >> num;
                if (num == 1) {
                    displayWithoutCommas();
                } else if (num == 2) {
                    cout << "Specify string:\n";
                    cin.ignore();
                    string s; getline(cin, s);
                    displayWithoutCommas(s);
                } else if (num == 3) {
                    break;
                } else {
                    cout << "No such command. Try again." << endl;    
                }
            }
        } else {
            cout << "No such command. Try again." << endl;
        }
    }
}