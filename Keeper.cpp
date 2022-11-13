#include <fstream>
#include <sstream>

#include "Keeper.h"

using namespace std;

string *split(string str, string delimiter, int count) {
  int pos, i = 0;
  string *strings = new string[count];
  
  while ((pos = str.find(delimiter)) != string::npos) {
    strings[i++] = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
  }
  strings[i] = str;
  return strings;
}

Keeper::Keeper() {
    head = NULL;
    tail = NULL;
}

Keeper::~Keeper() {
    free();
}

void Keeper::push(Worker *val) {
    Node *tmp = new Node;
    tmp->data = val;
    tmp->next = NULL;

    amount++;
    if (isEmpty()) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

void Keeper::pop(int num) {
    checkEmptiness();

    amount--;
    Node *tmp = head, *prev_tmp = head;
    int i = 0;
    do {
        if (i == num) {
            if (tmp == head) 
                head = tmp->next;
            else if (tmp == tail) {
                tail = prev_tmp;
                tail->next = NULL;
            } else
                prev_tmp->next = tmp->next;
            delete tmp->data;
            delete tmp;
            break;
        } 
    } while (tmp->next != NULL, i++, prev_tmp = tmp, tmp = tmp->next);
}

Worker *Keeper::get(int num) {
    checkEmptiness();

    Node *tmp = head, *prev_tmp = head;
    int i = 0;
    do {
        if (i == num) 
            return tmp->data;
    } while (tmp->next != NULL, i++, prev_tmp = tmp, tmp = tmp->next);
}

void Keeper::display() {
    checkEmptiness();

    Node *tmp = head;
    int i = 0;
    do {
        cout << i << " " << tmp->data;
    } while (tmp->next != NULL, i++, tmp = tmp->next);
}

void Keeper::save() {
    checkEmptiness();
    ofstream out("out.txt");

    Node *tmp = head;
    do {
        out << tmp->data->getFactoryType() << " " << tmp->data->getParams() << endl;
    } while (tmp->next != NULL, tmp = tmp->next);
}

void Keeper::load() {
    free();
    ifstream in("out.txt");
    for(string line; getline(in, line);) {
        string *p = split(line, " ", 8);
        if (p[0] == "furniture") {
            Furniture *f = new Furniture(p[1], stof(p[2]), stof(p[3]), stof(p[4]), p[5], p[6], stof(p[7]));
            push(f);
        } else if (p[0] == "vehicle") {
            Vehicle *f = new Vehicle(p[1], p[2], p[3]);
            push(f);
        } else if (p[0] == "worker") {
            Worker *f = new Worker(p[1], p[2], p[3], p[4], stof(p[5]), p[6], p[7]);
            push(f);
        }
    }
}

void Keeper::free() {
    try {
        checkEmptiness();
    } catch(const exception &e) {
        return;
    }
    Node *tmp = head, *next;
    do {
        next = tmp->next;
        delete tmp->data;
        delete tmp;
    } while (next != NULL, tmp = next);
    head = NULL; tail = NULL; amount = 0;
}

bool Keeper::isEmpty() {
    return head == NULL;
}

Keeper::Node *Keeper::getHead() {
    return head;
}

void Keeper::checkEmptiness() {
    if (isEmpty()) throw out_of_range("Keeper is empty");
}