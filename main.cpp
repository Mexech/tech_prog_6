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
#include "Keeper.h"

using namespace std;

void dispMenu() {
    cout << "1 - add new Factory\n2 - display factories\n3 - edit factory\n4 - remove Factory\n5 - load factories\n6 - save factories\n7 - exit\n";
}

int main() {
    Keeper k;
    while (1) {
        dispMenu();
        int num; cin >> num;
        // if (num == 1) {
        //     cout << "Specify factory type(1 - furniture, 2 - vehicle, 3 - worker)" << endl;
        //     int val; cin >> val;
        //     if (val == 1) {
        //         cin >> *f;
        //         k.push(f);
        //     } else if (val == 2) {
        //         Vehicle *f = new Vehicle;
        //         cin >> *f;
        //         k.push(f);
        //     } else if (val == 3) {
        //         Worker *f = new Worker;
        //         cin >> *f;
        //         k.push(f);
        //     } else {
        //         cout << "Such type doesn't exist. Try again" << endl;
        //     }
        // } else if (num == 2) {
        //     try {
        //         k.display();
        //     } catch (const exception &e) {
        //         cout << "Keeper is empty." << endl;
        //     }
        // } else if (num == 3) {
        //     cout << "Specify factory number to edit:" << endl;
        //     int val; cin >> val;
        //     if (val < 0 || val >= k.amount)
        //         cout << "Out of bounds. Try again." << endl;
        //     else 
        //         k.get(val)->edit();
        // } else if (num == 4) {
        //     cout << "Specify factory number to remove:" << endl;
        //     int val; cin >> val;
        //     if (val < 0 || val >= k.amount)
        //         cout << "Out of bounds. Try again." << endl;
        //     else 
        //         k.pop(val);
        // } else if (num == 5) {
        //     k.load();
        // } else if (num == 6) {
        //     try {
        //         k.save();
        //     } catch (const exception &e) {
        //         cout << "Keeper is empty. Not saved." << endl;
        //     }
        // } else if (num == 7) {
        //     break;
        // } else {
        //     cout << "No such command. Try again." << endl;
        // }
    }
}